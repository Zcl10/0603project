//
// Created by yao on 20-4-18.
//

#include "ipopt_solver.h"

class FgEvalR {
public:
    FgEvalR(ReferPointIpoptSolver *p_controller, const double &speed)
        : p_controller(p_controller), speed(speed) {
        this->N = p_controller->p_control_parameter->predict_N;
        this->dt = p_controller->p_control_parameter->sample_time;
    }

public:
    ReferPointIpoptSolver *p_controller;
    int N;
    double dt;
    double speed;

    typedef CPPAD_TESTVECTOR(AD<double>) ADvector;

    void operator()(ADvector &fg, const ADvector &vars) {
        // MPC Implementation ...

        const int x_range_begin = 0;
        const int y_range_begin = x_range_begin + N;
        const int yaw_range_begin = y_range_begin + N;
        const int steer_range_begin = yaw_range_begin + N;

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
        for (int i = 0; i < 3; ++i) {
            fg[1 + i * N] = vars[i * N];
        }

        // The rest of the constraints
        for (int i = 1; i < N; i++) {
            // The state at time t+1 .
            AD<double> x1 = vars[x_range_begin + i];
            AD<double> y1 = vars[y_range_begin + i];
            AD<double> yaw1 = vars[yaw_range_begin + i];
            // The state at time t.
            AD<double> x0 = vars[x_range_begin + i - 1];
            AD<double> y0 = vars[y_range_begin + i - 1];
            AD<double> yaw0 = vars[yaw_range_begin + i - 1];
            // Only consider the actuation at time t.
            AD<double> angle0 = vars[steer_range_begin + i - 1];

            fg[1 + x_range_begin + i] = x1 - (x0 + speed * CppAD::cos(yaw0) * dt);
            fg[1 + y_range_begin + i] = y1 - (y0 + speed * CppAD::sin(yaw0) * dt);
            fg[1 + yaw_range_begin + i] =
                yaw1 - (yaw0 + speed * CppAD::tan(angle0) / p_controller->p_vehicle_parameter->L * dt);
            //two point distance and heading error in cost function
            fg[0] += p_controller->p_control_parameter->weight.cte
                * (pow(x1 - p_controller->initref_path_[i][0], 2) + pow(y1 - p_controller->initref_path_[i][1], 2));
            fg[0] += p_controller->p_control_parameter->weight.epsi * pow(yaw1 - p_controller->initref_path_[i][2], 2);
        }
    }
};

//
// MPC class definition implementation.
//

void ReferPointIpoptSolver::renewPeriodStep(const std::vector<double> &curvature) {
    //TODO: adaptive sample time
    //// configure variable step time dt and predict steps N
    double PGC = 0;
    for (unsigned int l = 1; l < curvature.size() - 1; ++l) {
        double tmp = curvature.at(l);
        PGC += fabs(tmp);
    }
    PGC /= (curvature.size() - 2);
    ROS_INFO_STREAM("PGC is: " << PGC);
    double w = 10.0;
    double new_period = round(5.0 + 10 * exp(-w * PGC)) / 100;
}

void ReferPointIpoptSolver::delayProcessing() {
    static double dt = 1.0 / p_control_parameter->control_rate;
    static double max_change = p_control_parameter->max_steer_rate * M_PI / 180 * dt;
    static int delay_N = (p_control_parameter->delay_time + 0.001) * p_control_parameter->control_rate;
    static std::deque<double> history_cmd;
    history_cmd.push_back(steer_next);
    while (history_cmd.size() > delay_N)
        history_cmd.pop_front();
    for (int i = 0; i < delay_N; ++i) {
        yaw_init += speed * tan(angle) / p_vehicle_parameter->L * dt / 2;
        x_init += speed * cos(yaw_init) * dt;
        y_init += speed * sin(yaw_init) * dt;
        yaw_init += speed * tan(angle) / p_vehicle_parameter->L * dt / 2;
        if (i + 1 < history_cmd.size()) {
            double angle_change = history_cmd[i + 1] - history_cmd[i];
            angle_change = std::min(angle_change, fabs(max_change));
            angle_change = std::max(angle_change, -fabs(max_change));
            angle += angle_change;
        }
    }
}

void ReferPointIpoptSolver::selectReferPoints(const std::vector<double> &local_path_x,
                                              const std::vector<double> &local_path_y,
                                              const std::vector<double> &heading,
                                              const std::vector<double> &local_path_s,
                                              const std::vector<double> &arc_length) {
    size_t N = p_control_parameter->predict_N;
    initref_path_.clear();
    initref_path_ = std::vector<std::vector<double >>(N, std::vector<double>(3, 0.));
    int first_index = 0;
    while (first_index < local_path_s.size()) {
        std::pair<double, double> vec1 = std::make_pair(cos(heading[first_index]), sin(heading[first_index]));
        std::pair<double, double>
            vec2 = std::make_pair(x_init - local_path_x[first_index], y_init - local_path_y[first_index]);
        double temp = ToolKit::calculateDotProduct(vec1, vec2);
        if (temp > 0)
            first_index++;
        else
            break;
    }
    initref_path_[0] = std::vector<double> {local_path_x[first_index], local_path_y[first_index], heading[first_index]};
    int index = first_index;
    for (int i = 1; i < N; ++i) {
        double dt_distance = speed * p_control_parameter->sample_time;
        double move_distance = i * dt_distance;
        while (index < local_path_s.size() && local_path_s[index] - local_path_s[first_index] < move_distance)
            index++;

        if (index >= local_path_s.size()) {
            initref_path_[i][0] = initref_path_[i - 1][0] + dt_distance * cos(initref_path_[i - 1][2]);
            initref_path_[i][1] = initref_path_[i - 1][1] + dt_distance * sin(initref_path_[i - 1][2]);
            initref_path_[i][2] = initref_path_[i - 1][2];
        } else {
            double tiny_s = move_distance - (local_path_s[index - 1] - local_path_s[first_index]);
            double factor = tiny_s / arc_length[index];
            initref_path_[i][0] = local_path_x[index - 1] + factor * (local_path_x[index] - local_path_x[index - 1]);
            initref_path_[i][1] = local_path_y[index - 1] + factor * (local_path_y[index] - local_path_y[index - 1]);
            initref_path_[i][2] = heading[index - 1] + factor * (heading[index] - heading[index - 1]);
        }
    }
}

bool ReferPointIpoptSolver::solve(const std::vector<double> &local_path_x,
                                  const std::vector<double> &local_path_y,
                                  const std::vector<double> &heading,
                                  const std::vector<double> &curvature,
                                  const std::vector<double> &local_path_s,
                                  const std::vector<double> &arc_length) {
    this->x_init = 0.;
    this->y_init = 0.;
    this->yaw_init = 0.;
    this->speed = std::max(p_ecu_report->motion.velocity, p_control_parameter->lowest_velocity);
    this->angle = p_ecu_report->motion.steer / p_control_parameter->steer_ratio * M_PI / 180;
//    this->speed = std::max(p_vehicle_state->velocity.linear.x, p_control_parameter->lowest_velocity);
//    this->angle = atan2(p_vehicle_state->velocity.angular.z * p_vehicle_parameter->L / speed, 1);
    delayProcessing();
    selectReferPoints(local_path_x, local_path_y, heading, local_path_s, arc_length);
    if (p_control_parameter->dynamic)
        return dynamicSolve();
    else
        return kineticSolve();
}

bool ReferPointIpoptSolver::kineticSolve() {
    ROS_INFO_STREAM("Kinetic " << this->name);
    int state_size = 3;
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
    const int steer_range_begin = yaw_range_begin + N;

    vars[x_range_begin] = x_init;
    vars[y_range_begin] = y_init;
    vars[yaw_range_begin] = yaw_init;

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
    FgEvalR fg_eval(this, speed);
    // solve the problem
    CppAD::ipopt::solve<Dvector, FgEvalR>(options, vars,
                                          vars_lowerbound, vars_upperbound,
                                          constraints_lowerbound, constraints_upperbound,
                                          fg_eval, solution);
    // Check some of the solution values
    ok &= solution.status == CppAD::ipopt::solve_result<Dvector>::success;
    ROS_WARN_STREAM("ok: " << ok);
    // Cost
    double cost = solution.obj_value;
    ROS_WARN_STREAM("Cost: " << cost);

    // Solved (predicted) waypoint ...
    predict_path_.clear();
    for (int i = 0; i < N && ok; i++) {
        predict_path_.emplace_back(std::vector<double> {solution.x[x_range_begin + i], solution.x[y_range_begin + i],
                                                        solution.x[yaw_range_begin + i]});
    }

    // Return the first actuator values. The variables can be accessed with `solution.x[i]`.
    steer_next = ok ? solution.x[steer_range_begin] : 0.;
    steer_max_abs = 0.;
    for (int i = 0; i < N - 1 && ok; ++i) {
        steer_max_abs = std::max(steer_max_abs, fabs(solution.x[steer_range_begin + i]));
    }
//#define PRINT_INPUT_OUTPUT
#ifdef PRINT_INPUT_OUTPUT
    std::cout << "dt = " << p_control_parameter->sample_time << std::endl;
    std::cout << "x = " << x_init << std::endl;
    std::cout << "y = " << y_init << std::endl;
    std::cout << "theta = " << yaw_init << std::endl;
    std::cout << "v = " << speed << std::endl;
    std::cout << "angle = " << angle << std::endl;

//    std::cout << "solve_angle = [";
//    for (int j = steer_range_begin; j < steer_rate_range_begin; ++j)
//        std::cout << "(" << solution.x[j] << "," << 0 << "), ";
//    std::cout << "\b\b]" << std::endl;

    std::cout << "control_list = [";
    for (int j = steer_range_begin; j < n_vars; ++j)
        std::cout << "(" << solution.x[j] << "," << 0 << "), ";
    std::cout << "\b\b]" << std::endl;

    std::cout << "rviz_point = [";
    for (int l = 0; l < predict_path_.size(); ++l) {
        std::cout << "(" << solution.x[x_range_begin + l] << "," << solution.x[y_range_begin + l] << "), ";
    }
    std::cout << "\b\b]" << std::endl;

    std::cout<<"initref = [";
    for (int i = 0; i < initref_path_.size(); ++i) {
        std::cout << "(" << initref_path_[i][0] << "," << initref_path_[i][1] << "), ";
    }
    std::cout << "\b\b]" << std::endl;
#endif
    return ok;
}