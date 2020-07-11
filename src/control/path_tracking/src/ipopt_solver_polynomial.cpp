//
// Created by yao on 20-4-18.
//

#include "ipopt_solver.h"

class FgEvalP {
public:
    FgEvalP(PolynomialIpoptSolver *p_controller) : p_controller(p_controller) {
        this->N = p_controller->p_control_parameter->predict_N;
        this->dt = p_controller->p_control_parameter->sample_time;
    }

public:
    PolynomialIpoptSolver *p_controller;
    int N;
    double dt;

    typedef CPPAD_TESTVECTOR(AD<double>) ADvector;

    void operator()(ADvector &fg, const ADvector &vars) {
        // MPC Implementation ...

        const int x_range_begin = 0;
        const int y_range_begin = x_range_begin + N;
        const int yaw_range_begin = y_range_begin + N;
        const int v_range_begin = yaw_range_begin + N;

        const int steer_range_begin = v_range_begin + N;
        const int acc_range_begin = steer_range_begin + (N - 1);

        fg[0] = 0.0;

        // The cost function is not limited to the state, we could also include the control input! The reason we would do this is to allow us to penalize the magnitude of
        // the input as well as the change-rate. If we want to change lanes, for example, we would have a large cross-track error, but we wouldn't want to jerk the curvature
        // wheel as hard as we can. We could add the control input magnitude like this:
        for (int t = 0; t < N - 1; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer * pow(vars[steer_range_begin + t], 2);
            fg[0] += p_controller->p_control_parameter->weight.acc * pow(vars[acc_range_begin + t], 2);
        }
        // We still need to capture the change-rate of the control input to add some temporal smoothness.
        // This additional term in the cost function captures the difference between the next actuator state and the current one:
        fg[0] += p_controller->p_control_parameter->weight.steer_rate
            * pow(vars[steer_range_begin] - p_controller->getNextSteer(), 2);
        fg[0] += p_controller->p_control_parameter->weight.acc_rate
            * pow(vars[acc_range_begin] - p_controller->getNextAcceleration(), 2);
        for (int t = 0; t < N - 2; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer_rate
                * pow(vars[steer_range_begin + t + 1] - vars[steer_range_begin + t], 2);
            fg[0] += p_controller->p_control_parameter->weight.acc_rate *
                pow(vars[acc_range_begin + t + 1] - vars[acc_range_begin + t], 2);
        }

        // Initial constraints
        // We add 1 to each of the starting indices due to cost being located at
        // index 0 of `fg`. This bumps up the position of all the other values.
        for (int i = 0; i < 4; ++i) {
            fg[1 + i * N] = vars[i * N];
        }

        // The rest of the constraints
        for (int i = 1; i < N; i++) {
            // The state at time t+1 .
            AD<double> x1 = vars[x_range_begin + i];
            AD<double> y1 = vars[y_range_begin + i];
            AD<double> yaw1 = vars[yaw_range_begin + i];
            AD<double> v1 = vars[v_range_begin + i];
            // The state at time t.
            AD<double> x0 = vars[x_range_begin + i - 1];
            AD<double> y0 = vars[y_range_begin + i - 1];
            AD<double> yaw0 = vars[yaw_range_begin + i - 1];
            AD<double> v0 = vars[v_range_begin + i - 1];
            // Only consider the actuation at time t.
            AD<double> delta0 = vars[steer_range_begin + i - 1];
            AD<double> a0 = vars[acc_range_begin + i - 1];

            AD<double> f1 = p_controller->poly(x1); // use a our polynomial (3rd order) to calc f0 at x0
            AD<double> psides1 = CppAD::atan(p_controller->poly.oneDerive(x1)); // atan(derrivative of f0)

            fg[1 + x_range_begin + i] = x1 - (x0 + v0 * CppAD::cos(yaw0) * dt);
            fg[1 + y_range_begin + i] = y1 - (y0 + v0 * CppAD::sin(yaw0) * dt);
            fg[1 + yaw_range_begin + i] =
                yaw1 - (yaw0 + v0 * delta0 / p_controller->p_vehicle_parameter->L * dt);
            fg[1 + v_range_begin + i] = v1 - (v0 + a0 * dt);

            fg[0] += p_controller->p_control_parameter->weight.vel
                * pow(v1 - p_controller->p_control_parameter->desire_velocity, 2);
            fg[0] += p_controller->p_control_parameter->weight.cte * pow(y1 - f1, 2);
            fg[0] += p_controller->p_control_parameter->weight.epsi * pow(yaw1 - psides1, 2);
        }
    }
};

bool PolynomialIpoptSolver::solve(const std::vector<double> &local_path_x,
                                  const std::vector<double> &local_path_y,
                                  const std::vector<double> &heading,
                                  const std::vector<double> &curvature,
                                  const std::vector<double> &local_path_s,
                                  const std::vector<double> &arc_length) {
    ROS_INFO(this->name.c_str());

    if (!poly.calculatePolynomial(local_path_x, local_path_y, 3)) {
        ROS_ERROR("Polynomial fitting error!");
        return false;
    }
    // In there represent polynomial fitting path
    initref_path_.clear();
    for (int i = 0; i < local_path_s.size(); ++i) {
        initref_path_.emplace_back(std::vector<double>{local_path_x[i], poly(local_path_x[i]), 0.});
    }

    double x_init = 0.;
    double y_init = 0.;
    double yaw_init = 0;
    double speed = std::max(p_ecu_report->motion.velocity, p_control_parameter->lowest_velocity);
    double angle = p_ecu_report->motion.velocity / p_control_parameter->steer_ratio * M_PI / 180;

    int N = p_control_parameter->predict_N;
    int state_size = 4;
    bool ok = true;
    typedef CPPAD_TESTVECTOR(double) Dvector;

    // n_vars: Set the number of model variables (includes both states and inputs).
    // For example: If the state is a 4 element vector, the actuators is a 2
    // element vector and there are 10 timesteps. The number of variables is:
    // 4 * 10 + 2 * 9
    size_t n_vars = state_size * N + 2 * (N - 1);

    // Set the number of constraints
    size_t n_constraints = state_size * N;

    // Initial value of the independent variables. SHOULD BE 0 besides initial state.
    Dvector vars(n_vars);
    for (unsigned int i = 0; i < n_vars; i++) {
        vars[i] = 0;
    }

    // initial state ...
    // vars is a vehicle state (state + actuators) vector representation for N timesteps
    const int x_range_begin = 0;
    const int y_range_begin = x_range_begin + N;
    const int yaw_range_begin = y_range_begin + N;
    const int v_range_begin = yaw_range_begin + N;

    const int steer_range_begin = v_range_begin + N;
    const int acc_range_begin = steer_range_begin + (N - 1);

    vars[x_range_begin] = x_init;
    vars[y_range_begin] = y_init;
    vars[yaw_range_begin] = yaw_init;
    vars[v_range_begin] = speed;

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
    double max_steer =
        std::min(p_control_parameter->max_steer * M_PI / 180., 0.4 * 9.8 * p_vehicle_parameter->L / pow(speed, 2));
    for (int i = steer_range_begin; i < acc_range_begin; i++) {
        vars_lowerbound[i] = -max_steer;
        vars_upperbound[i] = max_steer;
    }
    for (int i = acc_range_begin; i < n_vars; i++) {
        vars_lowerbound[i] = p_control_parameter->max_deceleration;
        vars_upperbound[i] = p_control_parameter->max_acceleration;
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
    for (int i = 0; i < state_size; ++i) {
        constraints_lowerbound[i * N] = vars[i * N];
        constraints_upperbound[i * N] = vars[i * N];
    }

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
    FgEvalP fg_eval(this);
    // solve the problem
    CppAD::ipopt::solve<Dvector, FgEvalP>(options, vars,
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
        predict_path_.emplace_back(std::vector<double>{solution.x[x_range_begin + i], solution.x[y_range_begin + i],
                                                       solution.x[yaw_range_begin + i]});
    }

    // Return the first actuator values. The variables can be accessed with `solution.x[i]`.
    steer_next = ok ? solution.x[steer_range_begin] : 0.;
    steer_max_abs = 0.;
    for (int i = 0; i < N - 1 && ok; ++i) {
        steer_max_abs = std::max(steer_max_abs, fabs(solution.x[steer_range_begin + i]));
    }
    velocity_next = ok ? solution.x[v_range_begin + 1] : 0.;
    acceleration_next = ok ? solution.x[acc_range_begin] : 0.;
//#define PRINT_INPUT_OUTPUT
#ifdef PRINT_INPUT_OUTPUT
    std::cout << "dt = " << p_control_parameter->sample_time << std::endl;
    std::cout << "x = " << x_init << std::endl;
    std::cout << "y = " << y_init << std::endl;
    std::cout << "theta = " << yaw_init << std::endl;
    std::cout << "v = " << speed << std::endl;
    std::cout << "angle = " << angle << std::endl;

    std::cout << "control_list = [";
    for (int j = 0; j < N - 1; ++j)
        std::cout << "(" << solution.x[steer_range_begin + j] << "," << solution.x[acc_range_begin + j] << "), ";
    std::cout << "\b\b]" << std::endl;

    std::cout << "rviz_point = [";
    for (int l = 0; l < N; ++l) {
        std::cout << "(" << solution.x[x_range_begin + l] << "," << solution.x[y_range_begin + l] << "), ";
    }
    std::cout << "\b\b]" << std::endl;

    std::cout << "initref = [";
    for (int i = 0; i < initref_path_.size(); ++i) {
        std::cout << "(" << initref_path_[i][0] << "," << initref_path_[i][1] << "), ";
    }
    std::cout << "\b\b]" << std::endl;
#endif
    return ok;
}
