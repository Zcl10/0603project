//
// Created by yao on 20-6-29.
//

#include "ipopt_solver.h"

class FgEvalRD {
public:
    FgEvalRD(ReferPointIpoptSolver *p_controller, const double &speed)
        : p_controller(p_controller), speed(speed) {
        this->N = p_controller->p_control_parameter->predict_N;
        this->dt = p_controller->p_control_parameter->sample_time;
        double m = p_controller->p_vehicle_parameter->m;
        double I = p_controller->p_vehicle_parameter->I;
        double a = p_controller->p_vehicle_parameter->a;
        double b = p_controller->p_vehicle_parameter->b;
        double Cf = p_controller->p_vehicle_parameter->Cf;
        double Cr = p_controller->p_vehicle_parameter->Cr;
        this->k[0] = (Cf + Cr) / m;
        this->k[1] = (a * Cf - b * Cr) / m;
        this->k[2] = -Cf / m;
        this->k[3] = (a * Cf - b * Cr) / I;
        this->k[4] = (a * a * Cf + b * b * Cr) / I;
        this->k[5] = -a * Cf / I;
    }

public:
    ReferPointIpoptSolver *p_controller;
    int N;
    double dt;
    double speed;
    double k[6];

    typedef CPPAD_TESTVECTOR(AD<double>) ADvector;

    void operator()(ADvector &fg, const ADvector &vars) {
        // MPC Implementation ...
        const int x_range_begin = 0;
        const int y_range_begin = x_range_begin + N;
        const int yaw_range_begin = y_range_begin + N;
        const int v_range_begin = yaw_range_begin + N;
        const int w_range_begin = v_range_begin + N;
        const int steer_range_begin = w_range_begin + N;

        fg[0] = 0.0;

        // The cost function is not limited to the state, we could also include the control input! The reason we would do this is to allow us to penalize the magnitude of
        // the input as well as the change-rate. If we want to change lanes, for example, we would have a large cross-track error, but we wouldn't want to jerk the curvature
        // wheel as hard as we can. We could add the control input magnitude like this:
        for (int t = 0; t < N - 1; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer * pow(vars[steer_range_begin + t], 2);
        }
        // We still need to capture the change-rate of the control input to add some temporal smoothness.
        // This additional term in the cost function captures the difference between the next actuator state and the current one:
        fg[0] += p_controller->p_control_parameter->weight.steer_rate
            * pow(vars[steer_range_begin] - p_controller->getNextSteer(), 2);
        for (int t = 0; t < N - 2; t++) {
            fg[0] += p_controller->p_control_parameter->weight.steer_rate
                * pow(vars[steer_range_begin + t + 1] - vars[steer_range_begin + t], 2);
        }

        // Initial constraints
        // We add 1 to each of the starting indices due to cost being located at
        // index 0 of `fg`. This bumps up the position of all the other values.
        for (int i = 0; i < 5; ++i) {
            fg[1 + i * N] = vars[i * N];
        }

        // The rest of the constraints
        for (int i = 1; i < N; i++) {
            // The state at time t+1 .
            AD<double> x1 = vars[x_range_begin + i];
            AD<double> y1 = vars[y_range_begin + i];
            AD<double> yaw1 = vars[yaw_range_begin + i];
            AD<double> v1 = vars[v_range_begin + i];
            AD<double> w1 = vars[w_range_begin + i];
            // The state at time t.
            AD<double> x0 = vars[x_range_begin + i - 1];
            AD<double> y0 = vars[y_range_begin + i - 1];
            AD<double> yaw0 = vars[yaw_range_begin + i - 1];
            AD<double> v0 = vars[v_range_begin + i - 1];
            AD<double> w0 = vars[w_range_begin + i - 1];
            // Only consider the actuation at time t.
            AD<double> angle0 = vars[steer_range_begin + i - 1];

            fg[1 + x_range_begin + i] = x1 - (x0 + (speed * CppAD::cos(yaw0) - v0 * CppAD::sin(yaw0)) * dt);
            fg[1 + y_range_begin + i] = y1 - (y0 + (speed * CppAD::sin(yaw0) + v0 * CppAD::cos(yaw0)) * dt);
            fg[1 + yaw_range_begin + i] = yaw1 - (yaw0 + w0 * dt);
            fg[1 + v_range_begin + i] =
                v1 - (v0 + (k[0] * v0 / speed + k[1] * w0 / speed + k[2] * angle0 - speed * w0) * dt);
            fg[1 + w_range_begin + i] = w1 - (w0 + (k[3] * v0 / speed + k[4] * w0 / speed + k[5] * angle0) * dt);
            //two point distance and heading error in cost function
            fg[0] += p_controller->p_control_parameter->weight.cte
                * (pow(x1 - p_controller->initref_path_[i][0], 2) + pow(y1 - p_controller->initref_path_[i][1], 2));
            fg[0] += p_controller->p_control_parameter->weight.epsi * pow(yaw1 - p_controller->initref_path_[i][2], 2);
        }
    }
};

bool ReferPointIpoptSolver::dynamicSolve() {
    ROS_INFO_STREAM("Dynamic " << this->name);
    int state_size = 5;
    bool ok = true;
    typedef CPPAD_TESTVECTOR(double) Dvector;

    // n_vars: Set the number of model variables (includes both states and inputs).
    // For example: If the state is a 4 element vector, the actuators is a 2
    // element vector and there are 10 timesteps. The number of variables is:
    // 4 * 10 + 2 * 9
    size_t N = p_control_parameter->predict_N;
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
    const int x_range_begin = 0;
    const int y_range_begin = x_range_begin + N;
    const int yaw_range_begin = y_range_begin + N;
    const int v_range_begin = yaw_range_begin + N;
    const int w_range_begin = v_range_begin + N;
    const int steer_range_begin = w_range_begin + N;

    vars[x_range_begin] = x_init;
    vars[y_range_begin] = y_init;
    vars[yaw_range_begin] = yaw_init;
    //TODO : see here
    vars[v_range_begin] = 0.0;
    vars[w_range_begin] = 0.0;

    Dvector vars_lowerbound(n_vars);
    Dvector vars_upperbound(n_vars);

    // Set lower and upper limits for variables.
    // State values *except* actuator controls don't have an expected limit. Set these to double::min and max values
    // Set px, py, psi, velocity, cte, epsi upper and lower bound values to double::min and double::max values respectively.
    for (int i = 0; i < steer_range_begin; i++) {
        vars_lowerbound[i] = -1.0e19;
        vars_upperbound[i] = 1.0e19;
    }
    double max_steer = std::min(p_control_parameter->max_steer * M_PI / 180.,
                                p_control_parameter->lateral_acc * p_vehicle_parameter->L / pow(speed, 2));
    for (int i = steer_range_begin; i < n_vars; i++) {
        vars_lowerbound[i] = -max_steer;
        vars_upperbound[i] = max_steer;
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
    FgEvalRD fg_eval(this, speed);
    // solve the problem
    CppAD::ipopt::solve<Dvector, FgEvalRD>(options, vars,
                                           vars_lowerbound, vars_upperbound,
                                           constraints_lowerbound, constraints_upperbound,
                                           fg_eval, solution);
    // Check some of the solution values
    ok &= solution.status == CppAD::ipopt::solve_result<Dvector>::success;
    ROS_WARN_STREAM("ok: " << ok);
    // Cost
    double cost = solution.obj_value;
    ROS_WARN_STREAM("Cost: " << cost);

    return false;
}