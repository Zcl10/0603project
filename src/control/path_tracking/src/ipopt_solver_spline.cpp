//
// Created by yao on 20-4-18.
//

#include "ipopt_solver.h"

class FgEvalS {
public:
    FgEvalS(SplineIpoptSolver *p_controller) : p_controller(p_controller) {
        this->N = p_controller->p_control_parameter->predict_N;
        this->dt = p_controller->p_control_parameter->sample_time;
        this->speed = std::max(p_controller->p_vehicle_state->velocity.linear.x,
                               p_controller->p_control_parameter->lowest_velocity);
    }

public:
    SplineIpoptSolver *p_controller;
    int N;
    double dt;
    double speed;

    typedef CPPAD_TESTVECTOR(AD<double>) ADvector;

    void operator()(ADvector &fg, const ADvector &vars) {
        // MPC Implementation ...

        const int s_range_begin = 0;
        const int d_range_begin = s_range_begin + N;
        const int phi_range_begin = d_range_begin + N;

        const int steer_range_begin = phi_range_begin + N;

        fg[0] = 0.0;

        // The cost function is not limited to the state, we could also include the control input! The reason we would do this is to allow us to penalize the magnitude of
        // the input as well as the change-rate. If we want to change lanes, for example, we would have a large cross-track error, but we wouldn't want to jerk the curvature
        // wheel as hard as we can. We could add the control input magnitude like this:
        for (int t = 0; t < N - 1; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer * pow(vars[steer_range_begin + t], 2);
        }
        // We still need to capture the change-rate of the control input to add some temporal smoothness.
        // This additional term in the cost function captures the difference between the next actuator state and the current one:
//        fg[0] += p_controller->p_control_parameter->weight.steer_rate
//            * pow(vars[steer_range_begin] - p_controller->p_vehicle_state->velocity.angular.z / speed, 2);
        for (int t = 0; t < N - 2; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer_rate
                * pow(vars[steer_range_begin + t + 1] - vars[steer_range_begin + t], 2);
        }

        // Initial constraints
        // We add 1 to each of the starting indices due to cost being located at
        // index 0 of `fg`. This bumps up the position of all the other values.
        fg[1 + s_range_begin] = vars[s_range_begin];
        fg[1 + d_range_begin] = vars[d_range_begin];
        fg[1 + phi_range_begin] = vars[phi_range_begin];

        // The rest of the constraints
        for (int i = 1; i < N; i++) {
            // The state at time t+1 .
            AD<double> s1 = vars[s_range_begin + i];
            AD<double> d1 = vars[d_range_begin + i];
            AD<double> phi1 = vars[phi_range_begin + i];
            // The state at time t.
            AD<double> s0 = vars[s_range_begin + i - 1];
            AD<double> d0 = vars[d_range_begin + i - 1];
            AD<double> phi0 = vars[phi_range_begin + i - 1];
            // Only consider the actuation at time t.
            AD<double> kappa0 = vars[steer_range_begin + i - 1];

            AD<double> path_speed = speed * CppAD::cos(phi0) / (1 - d0 * p_controller->path_kappa[i - 1]);
            fg[1 + s_range_begin + i] = s1 - (s0 + path_speed * dt);
            fg[1 + d_range_begin + i] = d1 - (d0 + speed * CppAD::sin(phi0) * dt);
            fg[1 + phi_range_begin + i] =
                phi1 - (phi0 + (speed * kappa0 - path_speed * p_controller->path_kappa[i - 1]) * dt);

            //lateral and heading error in cost function
            fg[0] += p_controller->p_control_parameter->weight.cte * pow(d1, 2);
            fg[0] += p_controller->p_control_parameter->weight.epsi * pow(phi1, 2);
        }
    }
};

bool SplineIpoptSolver::solve(const std::vector<double> &local_path_x,
                              const std::vector<double> &local_path_y,
                              const std::vector<double> &heading,
                              const std::vector<double> &curvature,
                              const std::vector<double> &local_path_s,
                              const std::vector<double> &arc_length) {
    ROS_INFO(this->name.c_str());

    x_spline.set_points(local_path_s, local_path_x);
    y_spline.set_points(local_path_s, local_path_y);
    k_spline.set_points(local_path_s, curvature);

    double s_init = p_frenet_coordinate->s;
    double d_init = p_frenet_coordinate->d;
    double phi_init = p_frenet_coordinate->phi;
    double speed = std::max(p_vehicle_state->velocity.linear.x, p_control_parameter->lowest_velocity);
    double kappa = p_vehicle_state->velocity.angular.z / speed;

    path_kappa.clear();
    double dt_distance = speed * p_control_parameter->sample_time;
    for (int i = 0; i < p_control_parameter->predict_N; ++i) {
        double move_distance = i * dt_distance;
        path_kappa.push_back(k_spline(move_distance));
    }

    int N = p_control_parameter->predict_N;
    int state_size = 3;
    bool ok = true;
    typedef CPPAD_TESTVECTOR(double) Dvector;

    // n_vars: Set the number of model variables (includes both states and inputs).
    // For example: If the state is a 4 element vector, the actuators is a 2
    // element vector and there are 10 timesteps. The number of variables is:
    // 4 * 10 + 2 * 9
    size_t n_vars = state_size * N + N - 1;

    // Set the number of constraints
    size_t n_constraints = state_size * N;

    // Initial value of the independent variables. SHOULD BE 0 besides initial state.
    Dvector vars(n_vars);
    for (unsigned int i = 0; i < n_vars; i++) {
        vars[i] = 0;
    }

    // initial state ...
    // vars is a vehicle state (state + actuators) vector representation for N timesteps
    const int s_range_begin = 0;
    const int d_range_begin = s_range_begin + N;
    const int phi_range_begin = d_range_begin + N;

    const int steer_range_begin = phi_range_begin + N;

    vars[s_range_begin] = s_init;
    vars[d_range_begin] = d_init;
    vars[phi_range_begin] = phi_init;
    vars[steer_range_begin] = kappa;

    Dvector vars_lowerbound(n_vars);
    Dvector vars_upperbound(n_vars);

    // Set lower and upper limits for variables.
    // State values *except* actuator controls don't have an expected limit. Set these to double::min and max values
    // Set px, py, psi, velocity, cte, epsi upper and lower bound values to double::min and double::max values respectively.
    for (int i = 0; i < steer_range_begin; i++) {
        vars_lowerbound[i] = -1.0e19;
        vars_upperbound[i] = 1.0e19;
    }
    // curvature upper and lower bounds ...
    // The upper and lower limits of curvature angles are set to -25 and 25
    // degrees (values in radians).
    for (int i = steer_range_begin; i < n_vars; i++) {
        vars_lowerbound[i] = -p_control_parameter->max_steer;
        vars_upperbound[i] = p_control_parameter->max_steer;
    }

    // Lower and upper limits for the constraints
    // Should be 0 besides initial state.
    Dvector constraints_lowerbound(n_constraints);
    Dvector constraints_upperbound(n_constraints);
    for (unsigned int i = 0; i < n_constraints; i++) {
        constraints_lowerbound[i] = 0.0;
        constraints_upperbound[i] = 0.0;
    }

    // ... initial state constraints.
    constraints_lowerbound[s_range_begin] = s_init;
    constraints_upperbound[s_range_begin] = s_init;

    constraints_lowerbound[d_range_begin] = d_init;
    constraints_upperbound[d_range_begin] = d_init;

    constraints_lowerbound[phi_range_begin] = phi_init;
    constraints_upperbound[phi_range_begin] = phi_init;

    // options for IPOPT solver
    std::string options;
    // Uncomment this if you'd like more print information
    options += "Integer print_level  0\n";
    // NOTE: Setting sparse to true allows the solver to take advantage
    // of sparse routines, this makes the computation MUCH FASTER. If you
    // can uncomment 1 of these and see if it makes a difference or not but
    // if you uncomment both the computation time should go up in orders of
    // magnitude.
    options += "Sparse  true        forward\n";
    options += "Sparse  true        reverse\n";
    // NOTE: Currently the solver has a maximum time limit of 0.5 seconds.
    // Change this as you see fit.
    options += "Numeric max_cpu_time          0.5\n";

    // place to return solution
    CppAD::ipopt::solve_result<Dvector> solution;
    // object that computes objective and constraints
    FgEvalS fg_eval(this);
    // solve the problem
    CppAD::ipopt::solve<Dvector, FgEvalS>(options, vars,
                                          vars_lowerbound, vars_upperbound,
                                          constraints_lowerbound, constraints_upperbound,
                                          fg_eval, solution);
    // Check some of the solution values
    ok &= solution.status == CppAD::ipopt::solve_result<Dvector>::success;

    // Cost
    double cost = solution.obj_value;
    ROS_WARN_STREAM("Cost: " << cost);

    // Solved (predicted) waypoint ...
    predict_path_.clear();
    for (int i = 0; i < N && ok; i++) {
        double s = solution.x[s_range_begin + i];
        double d = solution.x[d_range_begin + i];
        double tangent_angle = atan2(y_spline.deriv(1, s), x_spline.deriv(1, s));
        predict_path_.emplace_back(std::vector<double>{x_spline(s) - d * sin(tangent_angle),
                                                       y_spline(s) + d * cos(tangent_angle),
                                                       0.});
    }

    // Return the first actuator values. The variables can be accessed with `solution.x[i]`.
    steer_next = ok ? solution.x[steer_range_begin] : 0.;
    steer_max_abs = 0.;
    for (int i = 0; i < N - 1 && ok; ++i) {
        steer_max_abs = std::max(steer_max_abs, fabs(solution.x[steer_range_begin + i]));
    }
    return ok;
}