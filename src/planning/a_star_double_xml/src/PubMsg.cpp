#include "PubMsg.h"

PubMsg::PubMsg(int argc, char **argv) :
    index(0),
    nearest_point_id_(0),
    empty_traj_count_(0),
    vehicle_state_updated_(false),
    is_rcv_gps(false),
    gps_state(false),
    vertical_wall_state(false),
    ditch_state(false),
    need_replanning_(false),
    attach_success_(false),
    is_rcv_intersec(false),
    is_foogy(false),
    is_grass(false),
    is_water(false),
    need_replanning_real_time(false),
    rcv_cross_road(false) {
    std::cout << "constructe PubMsg class" << std::endl;
    linear_interpo_dis = 1;         // 插值点间距的控制距离，1米插一个点
    cur_road_type = -1;
    backup_confirm_flag = false;
    wait_for_search = false;
    wait_for_xunxian = false;
    search_stop = false;
    xunxian_stop = false;
    first_path_flag = false;
    vehicle_vel = 0;
    gear_position = -1;
    weapon_contorl = false;
    weapon_task_finished = false;
    weapon_start_time = 0;
    check_gps_update = false;
    ros::init(argc, argv, "a_star_double_xml");

    this->base_dir = ros::package::getPath("a_star_double_xml");

    ros::start();
    ros::NodeHandle n;
    ros::NodeHandle private_nh_("~");        //读取参数
    // add ros communications
    vehicle_state_sub =
        n.subscribe("/sensor_fusion_output", 1, &PubMsg::vehicleStateCb, this);
    traj_sub_ =
        n.subscribe("global_path/traj_plan", 1, &PubMsg::trajectoryCb, this);
    intersection_sub =
        n.subscribe("/crossroadtopic", 1, &PubMsg::IsIntersection, this);
    foggy_sub_ = n.subscribe("is_foggy", 1, &PubMsg::isFoogy, this);
    grass_sub_ = n.subscribe("is_grass", 1, &PubMsg::isGrass, this);
    water_sub_ = n.subscribe("/stiffwaterogm", 1, &PubMsg::isWater, this);
    path_pub = n.advertise<lanelet_map_msgs::Way>("/topology_global_path", 1);
    global_way_pub = n.advertise<lanelet_map_msgs::Way>("/global_path", 1);
    weapon_pub = n.advertise<three_one_msgs::ControlWeapon>("/weapon",1);
//    vertical_wall_sub_ = n.subscribe("/vertical_wall_topic",1,&PubMsg::vertical_wall_cb,this);
//    ditch_sub_ = n.subscribe("ditch_detection",1,&PubMsg::ditch_cb,this);
    gps_sub_ = n.subscribe("/GPSmsg", 1, &PubMsg::gpsStateCb, this);
    search_stop_sub_ =
        n.subscribe("/search_plan_end", 1, &PubMsg::searchStop, this);
    vel_sub_ =
        n.subscribe("ecudatareport", 1, &PubMsg::callbackEcuDataReport, this);
    task_command_sub_ =
        n.subscribe("task_command", 1, &PubMsg::callbackTaskCommand, this);
    start();        //启动线程

    connect(this,
            SIGNAL(ReplanMsg(float, float)),
            this,
            SLOT(Replanning(float, float)));
    //In this way, the Repalnning function will run in the main thread!

    //初始化全局路网运行参数
    run_param.automatic_start = private_nh_.param("automatic_start", true);
    run_param.get_node_from_txt = private_nh_.param("get_node_from_txt", false);
    run_param.use_prior_map_replan =
        private_nh_.param("use_prior_map_replan", true);
    run_param.open_dynamic_obs_det =
        private_nh_.param("open_dynamic_obs_det", true);
    run_param.open_foggy_det = private_nh_.param("open_foggy_det", true);
    run_param.open_fixed_line_patrol =
        private_nh_.param("open_fixed_line_patrol", false);
    run_param.set_patrol_times = private_nh_.param("set_patrol_times", 0);
    run_param.remote_control_mode = private_nh_.param("remote_control_mode",false);
    need_interpolation =
        private_nh_.param("need_interpolation", true);     //是否需要插值
    use_bspline = private_nh_.param("use_bspline",
                                    true);            //是否使用样条插值，当false，则使用线性插值
    close_replan = private_nh_.param("close_replan", false);
                                    //connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
    std::cout << "ROS NODE INIT!, base_dir: " << base_dir << std::endl;
}

PubMsg::~PubMsg() {
    if (ros::isStarted()) {
        ros::shutdown();
        ros::waitForShutdown();
    }
    quit();
    wait();
}

void PubMsg::run() {
    //qDebug()<<"From ROS function: "<<currentThreadId();
    ros::Rate rate(10); //10hz
    while (ros::ok()) {
        ros::spinOnce();
        if (!vehicle_state_updated_) {
            rate.sleep();
            continue;
        } else {
            {
                QMutexLocker locker(&mutex_attach_success);
                if (!this->attach_success_) {
                    continue;
                }
            }
            {
                QMutexLocker locker(&mutex_need_replanning);
                if (this->need_replanning_) {
                    float lat, lon;
                    lat = this->vehicle_gps.latitude;
                    lon = this->vehicle_gps.longitude;

                    //Q_EMIT ReplanMsg( lat, lon);
                    need_replanning_real_time = true;
                    this->need_replanning_ = false;
                }
            }
            {
                QMutexLocker
                    locker(&(this->path_planner_->mutex_PathPlanFinishFlag));
                if (this->path_planner_->PathPlanFinishFlag) {
                    QMutexLocker locker1(&path_planner_->mutex_pub_way);
                    if (is_foogy
                        && path_planner_->way_msgs.open_foggy_det == 1) {
                        path_planner_->way_msgs.foggy_area = 1;        //烟雾区标志
                    } else {
                        path_planner_->way_msgs.foggy_area = 0;
                    }
                    if (is_water && path_planner_->way_msgs.open_water_det) {
                        path_planner_->way_msgs.water_area = 1;
                    } else {
                        path_planner_->way_msgs.water_area = 0;
                    }
                    if (is_grass) {
                        path_planner_->way_msgs.lawn_area = 1;        //前方草地标志
                    } else {
                        path_planner_->way_msgs.lawn_area = 0;
                    }
                    //武器站任务开始控制
                    if(path_planner_->way_msgs.task_area == "weapon" && !weapon_contorl && !weapon_task_finished){
                        check_gps_update = true;
                        if(gps_state){
                            path_planner_->way_msgs.vel_limit = 0;  //控制最高限速为零
                            if(vehicle_vel < 0.5){      //当车辆速度小于0.5m/s，认为车辆停止
                                weapon_contorl = true;  //开始武器站任务
                                weapon_start_time = time(NULL);    //记录武器站任务开始时间；
                                ROS_INFO("weapon task begin,time:%ld",weapon_start_time);
                            }
                        }
                    }
                    if(weapon_contorl){
                        path_planner_->way_msgs.vel_limit = 0;  //控制最高限速为零
                        three_one_msgs::ControlWeapon weapon_msg;
                        weapon_msg.priority = 0;
                        weapon_msg.weapon_28 = 0;
                        weapon_msg.weapon_330 = 0;
                        weapon_msg.weapon_cmd = 1;
                        weapon_pub.publish(weapon_msg);
                        time_t time_record = time(NULL);
                        auto task_duration = (double)(time_record - weapon_start_time);
                        //等待5min
                        if(task_duration > 600){
                            weapon_contorl = false;
                            weapon_task_finished = true;
                            ROS_INFO("weapon task done.");
                        }else{
                            if((int)(task_duration * 10) % 10 == 0){
                                ROS_INFO("weapon time record: %d s",(int)task_duration);
                            }
                        }
                    }else{
                        three_one_msgs::ControlWeapon weapon_msg;
                        weapon_msg.priority = 0;
                        weapon_msg.weapon_28 = 0;
                        weapon_msg.weapon_330 = 0;
                        weapon_msg.weapon_cmd = 0;
                        weapon_pub.publish(weapon_msg);
                    }
                    //当车辆处于巡线区域，控制车辆限速最高为1.5m/s
                    if(path_planner_->way_msgs.task_area == "patrol_area"){
                        path_planner_->way_msgs.vel_limit = 1.5;
                    }
                    //interpolation
                    if (/*task_command == "1"*/true) {            //当任务命令为开始的时候发路网，其他情况不发路网
                        if (/*need_interpolation*/false) {
                            lanelet_map_msgs::Way
                                pub_way_msg = path_planner_->way_msgs;
                            pub_way_msg.points.clear();
                            if (use_bspline && path_planner_->way_msgs.points.size() > 4) {
                                this->interpolateBspline(path_planner_->way_msgs,
                                                         &pub_way_msg);       //样条拟合会失去节点属性
                            } else {
                                this->linearInterpolation(path_planner_->way_msgs,
                                                          &pub_way_msg);
                            }
                            path_pub.publish(pub_way_msg);
                        } else {
                            path_pub.publish(path_planner_->way_msgs);
//                            std::cout<<"Debug direction: "<<path_planner_->way_msgs.is_forward+0<<std::endl;
                        }
                    }
                    global_way_pub.publish(path_planner_->global_way_msgs);
                    vehicle_state_updated_ = false;
                    index++;
                }
            }
        }
        rate.sleep();
    }
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

bool PubMsg::init() {
//    if(   !ros::master::check())
//    {
//        return false;
//    }
//    vehicle_state_updated_ = false;
//    ros::start();
//    ros::NodeHandle n;
//     add ros communications
//    vehicle_state_sub = n.subscribe("/sensor_fusion_output", 1, &PubMsg::vehicleStateCb, this);
//    path_pub = n.advertise<lanelet_map_msgs::Way>("/topology_global_path", 1);
//    start();
//    std::cout << "ROS NODE INIT!" << std::endl;
}

void PubMsg::vehicleStateCb(const sensor_driver_msgs::GpswithHeading &gps) {
    {
        QMutexLocker locker(&this->mutex_is_rev_gps);
        this->is_rcv_gps = true;
    }
    {
        QMutexLocker locker(&this->mutex_vehicle_gps);
        this->vehicle_gps = gps.gps;
    }

    /// GPS to UTM
    cartographer::transform::TransformTools tft;
    tft.geographic_to_utm(gps.gps.longitude, gps.gps.latitude,
                          &(vehicle_pose_.x), &(vehicle_pose_.y));
    double theta = gps.heading * M_PI / 180.0 + M_PI_2;
    if (theta > M_PI) {
        theta -= 2 * M_PI;
    }
    this->vehicle_pose_.z = theta;
    this->vehicle_state_updated_ = true;
}

void PubMsg::vertical_wall_cb(const vertical_wall_grid::vertical_wall_grid &detectData) {
    if(detectData.detected){
        vertical_wall_state = true;
        ROS_INFO("verticl wall detected");
    }else{
        vertical_wall_state = false;
    }
}

void PubMsg::ditch_cb(const vertical_wall_grid::vertical_wall_grid &detectData) {
    if(detectData.detected){
        ditch_state = true;
        ROS_INFO("ditch detected");
    }else{
        ditch_state = false;
    }
}

void PubMsg::gpsStateCb(const sensor_driver_msgs::GpswithHeading &gps) {
    if(check_gps_update){
        gps_state = true;
        ROS_INFO("Can receive satellite signals");
    }
}

void PubMsg::IsIntersection(const extractroad_msg::extractroad &inter_data) {
    {
        QMutexLocker locker(&this->mutex_is_rcv_intersec);
        is_rcv_intersec = true;
        rcv_cross_road = true;
    }
    {
        QMutexLocker locker(&this->mutex_intersec_data);
        intersec_data = inter_data;
        /*qDebug()<<"I heard a intersection"<<endl
                <<"the chadaokou gps:" << inter_data.vehicle_point[0] <<","<< inter_data.vehicle_point[1] << endl
                <<"the number of leadpoints:" << inter_data.roadcount<<endl
                <<"the leadpoints gps:"<<endl;
        for(int i = 0 ; i< inter_data.leadpoints.size() ; i++){
            qDebug()<<inter_data.leadpoints.at(i)<<endl;
        }*/
    }
    std::cout << "rcv an intersection" << std::endl;
}

void PubMsg::trajectoryCb(const plan2control_msgs::Trajectory &traj) {
    QMutexLocker locker(&mutex_attach_success);
    if (this->attach_success_) {
        QMutexLocker locker(&mutex_need_replanning);
        {
            QMutexLocker locker1(&mutex_backup_confirm);
            float temp_dis = 20;        //初始化
            if (!traj.points.empty()) {
                temp_dis = distance(traj.points.front().position.x,
                                    traj.points.front().position.y,
                                    traj.points.back().position.x,
                                    traj.points.back().position.y);
            }
            if (backup_confirm_flag) {
                if ((traj.points.empty() || temp_dis <= 15)
                    && !this->need_replanning_) {
                    std::cout << "the length of trajectory is " << temp_dis
                              << std::endl;
                    this->empty_traj_count_++;
                } else {
                    this->empty_traj_count_ = 0;
                }
            } else {
                if ((traj.points.empty() || temp_dis <= 8)
                    && !this->need_replanning_) {
                    std::cout << "the length of trajectory is " << temp_dis
                              << std::endl;
                    this->empty_traj_count_++;
                } else {
                    this->empty_traj_count_ = 0;
                }
            }
        }
        if (empty_traj_count_ > 0) {
            std::cout << "empty traj_count : " << empty_traj_count_
                      << std::endl;
        }

        //当处于烟雾区/搜索区/武器站，不触发重规划或者倒车
        {
            QMutexLocker locker1(&path_planner_->mutex_pub_way);
            /*if(path_planner_->way_msgs.task_area == "XunXian_stop"){
                xunxian_stop = true;
            }
            if(is_foogy){
                this->empty_traj_count_ = 0;
            }*/
            if (path_planner_->way_msgs.task_area == "hidden_area"
                || wait_for_search) {
                wait_for_search = true;
                if (search_stop) {
                    wait_for_search = false;
                }
                if (empty_traj_count_ > 0) {
                    std::cout << "In hidden area, clear empty_traj_count_." << std::endl;
                }
                this->empty_traj_count_ = 0;
            }
            if (path_planner_->way_msgs.task_area == "park_area") {
                if (empty_traj_count_ > 0) {
                    std::cout << "In park area, clear empty_traj_count_." << std::endl;
                }
                this->empty_traj_count_ = 0;
            }
            if (weapon_contorl) {
                if (empty_traj_count_ > 0) {
                    std::cout << "In weapon area, clear empty_traj_count_." << std::endl;
                }
                this->empty_traj_count_ = 0;
            }
            if (close_replan) {
                if (empty_traj_count_ > 0) {
                    std::cout << "Close replan function, clear empty_traj_count_." << std::endl;
                }
                this->empty_traj_count_ = 0;
            }
            /*if(path_planner_->way_msgs.task_area == "XunXian_start" || wait_for_xunxian){
                wait_for_xunxian = true;
                if(xunxian_stop){
                    std::cout << "xunxian stop." << std::endl;
                    wait_for_xunxian = false;
                }else{
                    if(empty_traj_count_ > 0){
                        std::cout << "In xunxian area, clear empty_traj_count_." << std::endl;
                    }
                    this->empty_traj_count_ = 0;
                }
            }*/
        }

        //当处于远程操控模式，清空计数，不触发倒车与重规划
        if(run_param.remote_control_mode){
            if (empty_traj_count_ > 0) {
                std::cout << "remote control mode, clear empty_traj_count_." << std::endl;
            }
            this->empty_traj_count_ = 0;
        }
        //检测到垂直墙，清空计数，不触发倒车与重规划
//        if(vertical_wall_state){
//            if (empty_traj_count_ > 0) {
//                std::cout << "vertical wall detected, clear empty_traj_count_." << std::endl;
//            }
//            this->empty_traj_count_ = 0;
//        }
        //检测到壕沟，清空计数，不触发倒车与重规划
//        if(ditch_state){
//            if (empty_traj_count_ > 0) {
//                std::cout << "ditch detected, clear empty_traj_count_." << std::endl;
//            }
//            this->empty_traj_count_ = 0;
//        }

        //垂直墙区域，清空计数，不触发倒车与重规划
        if(path_planner_->way_msgs.wall_area){
            if (empty_traj_count_ > 0) {
                std::cout << "vertical wall area, clear empty_traj_count_." << std::endl;
            }
            this->empty_traj_count_ = 0;
        }
        //壕沟区域，清空计数，不触发倒车与重规划
        if(path_planner_->way_msgs.ditch_area){
            if (empty_traj_count_ > 0) {
                std::cout << "ditch area, clear empty_traj_count_." << std::endl;
            }
            this->empty_traj_count_ = 0;
        }

        //当处于重规划第一段路的时候，清空计数
        {
            QMutexLocker locker2(&mutex_first_path_flag);
            if (first_path_flag) {
                if (empty_traj_count_ > 0) {
                    std::cout
                        << "In the first path of replanning, clear empty_traj_count_."
                        << std::endl;
                }
                this->empty_traj_count_ = 0;
            }
        }

        if (this->empty_traj_count_ > 20) {
            this->need_replanning_ = true;
            std::cout << "clear empty_traj_count_." << std::endl;
            this->empty_traj_count_ = 0;
        }
    }
}

void PubMsg::callbackEcuDataReport(const three_one_msgs::Report &msg) {
    {
        QMutexLocker locker(&mutex_vehicle_vel);
        vehicle_vel = msg.motion.vehicle_speed;
        gear_position = msg.motion.current_gear;
    }
}

void PubMsg::callbackTaskCommand(const std_msgs::String &commandData) {
    if (commandData.data != "0" && task_command != commandData.data) {
        ROS_INFO("task command from %s to %s",
                 task_command.c_str(),
                 commandData.data.c_str());
        task_command = commandData.data;
    }
}

void PubMsg::isFoogy(const std_msgs::String &isfoogy) {
    if (is_foogy == false && isfoogy.data == "1" && empty_traj_count_ > 8) {
        is_foogy = true;
        ROS_INFO("is foogy!!!");
    } else {
        //ROS_INFO("is not foogy.");
        is_foogy = false;
    }
    if (isfoogy.data == "0") {
        //ROS_INFO("is not foogy.");
        is_foogy = false;
    }
}

void PubMsg::isGrass(const std_msgs::String &isgrass) {
    if (isgrass.data == "1" && empty_traj_count_ > 8) {
        is_grass = true;
        //ROS_INFO("have grass!!!");
    } else {
        //ROS_INFO("don't have grass.");
        is_grass = false;
    }
}

void PubMsg::isWater(const stiff_msgs::stiffwater &water_msg) {
    if (water_msg.havewater == 1) {
        is_water = true;
        //ROS_INFO("have water!!!");
    } else {
        //ROS_INFO("don't have water.");
        is_water = false;
    }
}

void PubMsg::searchStop(const std_msgs::UInt8 &isSearchStop) {
    if (isSearchStop.data == 1) {
        if (!search_stop) {
            ROS_INFO("search stop.");
        }
        search_stop = true;
    }
}

void PubMsg::transParameter(const std::vector<geometry_msgs::Point> &object) {
    this->way_point.clear();
    this->way_point = object;
}

void PubMsg::transPathPlanner(AttachXmlFile *planner) {
    this->path_planner_ = planner;
}

void PubMsg::Replanning(float lat, float lon) const {
    //qDebug()<<"From Repalnning function: "<<currentThreadId();
    std::cout << "start replan!!!" << std::endl;
    {
        QMutexLocker locker(&(this->path_planner_->mutex_PathPlanFinishFlag));
        this->path_planner_->PathPlanFinishFlag = false;
    }
    this->path_planner_->RePlanning(lat, lon);
    this->path_planner_->m_bPathPlaned = true;
    this->path_planner_->m_flag = 0;
    {//add pathplanfinishflag lock
        QMutexLocker locker(&(this->path_planner_->mutex_PathPlanFinishFlag));
        this->path_planner_->PathPlanFinishFlag = true;
    }
}

double PubMsg::distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

void PubMsg::interpolateBspline(const lanelet_map_msgs::Way &origin_way,
                                lanelet_map_msgs::Way *result) {
    *result = origin_way;
    const size_t ctrlpt_num = origin_way.points.size();
    if (ctrlpt_num < 5) {
        return;
    }
    result->points.clear();
    std::vector<double> ctrlp;
    for (const auto &node:origin_way.points) {
        ctrlp.push_back(node.point.x);
        ctrlp.push_back(node.point.y);
    }
    size_t degree = ctrlpt_num > 9 ? 8 : ctrlpt_num - 1;
    tinyspline::BSpline clamped_spline(ctrlpt_num, 2, degree);
    clamped_spline.setControlPoints(ctrlp);

    const std::size_t sample_num = std::max((std::size_t) 200, ctrlpt_num * 6);
    size_t count = 0;
    double origin_length = 0.0;
    double new_length = 0.0;
    double size_f = static_cast<double>(sample_num - 1);
    for (std::size_t j = 0; j < sample_num; j++) {
        double knot_percent = static_cast<double>(j) / size_f;
        lanelet_map_msgs::Node node;
        node.point.x = clamped_spline.eval(knot_percent).result().at(0);
        node.point.y = clamped_spline.eval(knot_percent).result().at(1);
        node.id = static_cast<int>(j);
        if (j > 0) {
            new_length += distance(result->points.back().point.x,
                                   result->points.back().point.y,
                                   node.point.x,
                                   node.point.y);
            while (new_length > origin_length) {
                count++;
                if (count >= origin_way.points.size()) {
                    count = origin_way.points.size() - 1;
                    break;
                }
                origin_length +=
                    distance(origin_way.points.at(count - 1).point.x,
                             origin_way.points.at(count - 1).point.y,
                             origin_way.points.at(count).point.x,
                             origin_way.points.at(count).point.y);
            }
        }
        node.type = origin_way.points.at(count).type;
        node.vlimit = origin_way.points.at(count).vlimit;
        result->points.push_back(node);
    }
}
float PubMsg::PointToTheta(float x1, float y1, float x2, float y2) {
    //THETA 范围 0 到 CV_PI*2
    float theta;
    if (x2 - x1 == 0) {
        if (y2 - y1 > 0)
            theta = CV_PI / 2;
        else
            theta = CV_PI * 3 / 2;
    } else if (x2 - x1 > 0)
        theta = (atan((y2 - y1) / (x2 - x1)));
    else
        theta = ((CV_PI + atan((y2 - y1) / (x2 - x1))));

    if (theta < 0) theta = CV_PI * 2 + theta;

    return theta;
}

void PubMsg::linearInterpolation(const lanelet_map_msgs::Way &origin_way,
                                 lanelet_map_msgs::Way *result) {
    result->points.clear();
    if (origin_way.points.size() == 0) {
        return;
    }
    result->points.push_back(origin_way.points[0]);
    int control_point_num = origin_way.points.size();
    for (int i = 0; i < control_point_num - 1; i++) {
        float x1 = origin_way.points[i].point.x;
        float y1 = origin_way.points[i].point.y;
        float x2 = origin_way.points[i + 1].point.x;
        float y2 = origin_way.points[i + 1].point.y;
        float dis_xy;
        float theta;
        float line_segment, sum_seg;

        theta = PointToTheta(x1, y1, x2, y2);
        dis_xy = distance(x1, y1, x2, y2);    //计算两点之间的距离
        int n = dis_xy / linear_interpo_dis;
        line_segment = dis_xy / n;
        sum_seg = line_segment;
        lanelet_map_msgs::Node node;
        for (int i = 0; i < n - 1; i++) {
            node.point.x = x1 + sum_seg * std::cos(theta);
            node.point.y = y1 + sum_seg * std::sin(theta);
            result->points.push_back(node);
            sum_seg = sum_seg + line_segment;
        }
        result->points.push_back(origin_way.points[i + 1]);
    }
}
