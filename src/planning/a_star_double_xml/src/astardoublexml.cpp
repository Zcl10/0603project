#include "astardoublexml.h"
#include "ui_astardoublexml.h"
#include <QMessageBox>
#include <qdebug.h>
#include "MapSearchNode.h"
#include <QFile>
#include <QTextStream>

AStarDoubleXML::AStarDoubleXML(int argc, char** argv, QWidget *parent) :
    QMainWindow(parent)
    ,ros_pub(argc, argv) {
/*AStarDoubleXML::AStarDoubleXML(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AStarDoubleXML)
{
    ui->setupUi(this);  //Setupui function builds a user interface for "this" pointer*/
    this->base_dir =  QString::fromStdString(ros_pub.base_dir);
    this->m_attach_xml_file.base_dir = this->base_dir;
    ui.setupUi(this);
    m_bRecvRndf=false;

    //build topological map in real time
    record_flag = true;
    end_task_node_id = -1;
    first_planning_finished = false;
    second_plan_trig_dis = 5;   //触发重规划第二次路径发送控制距离
    backup_flag = false;
    first_path_flag = false;
    first_plan_start_id = -1;
    first_planning_flag = false;
    wait_times = 0;
    wait_times_for_second_path = 0;
    backup_start_gps.longitude = 0;
    backup_start_gps.latitude = 0;
    repeat_tri_times = 0;
    ros_pub.transPathPlanner(&m_attach_xml_file);

    //get_node_from_txt = false;       //从txt中读取任务点路网，若为false，则从xml文件读取路网
    //use_prior_map_replan = true;    //是否先验地图进行重规划
    get_node_from_txt = ros_pub.run_param.get_node_from_txt;
    use_prior_map_replan = ros_pub.run_param.use_prior_map_replan;
    open_fixed_line_patrol = ros_pub.run_param.open_fixed_line_patrol;
    m_attach_xml_file.set_patrol_times = ros_pub.run_param.set_patrol_times;
    m_attach_xml_file.open_dynamic_obs_det = ros_pub.run_param.open_dynamic_obs_det;
    m_attach_xml_file.open_foggy_det = ros_pub.run_param.open_foggy_det;
    std::cout << "read param: " << std::endl;
    std::cout << "     get_node_from_txt:     " << std::boolalpha << get_node_from_txt << std::endl
              << "     use_prior_map_replan:  " << std::boolalpha << use_prior_map_replan << std::endl
              << "     open_dynamic_obs_det:  " << std::boolalpha << m_attach_xml_file.open_dynamic_obs_det << std::endl
              << "     open_foggy_det:        " << std::boolalpha << m_attach_xml_file.open_foggy_det << std::endl
              << "     open_fixed_line_patrol:" << std::boolalpha << open_fixed_line_patrol << std::endl
              << "     set_patrol_times: " << m_attach_xml_file.set_patrol_times << std::endl;
    //connect(this,SIGNAL(lastWindowClosed()),&ros_pub,SLOT(quit()));
}

AStarDoubleXML::~AStarDoubleXML() {
    //delete ui;
}

void AStarDoubleXML::on_ReadFile_clicked() {
    {//add pathplanfinishflag lock
        QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
        m_attach_xml_file.PathPlanFinishFlag= false;
    }
    if(!m_attach_xml_file.original_road_network_list.isEmpty()){
        qDeleteAll(m_attach_xml_file.original_road_network_list);
        m_attach_xml_file.original_road_network_list.clear();
    }
    if(!m_attach_xml_file.m_astarsearch.NodeList.isEmpty()) {
        m_attach_xml_file.m_Pathid_vector.clear();          //note
        //qDeleteAll(m_attach_xml_file.m_astarsearch.NodeList);
        m_attach_xml_file.m_astarsearch.NodeList.clear();
        if(!m_attach_xml_file.m_astarsearch.NodeList.isEmpty())
        ROS_FATAL("on_ReadFile_clicked,NodeList cannnot been cleared.");
    }
    if(!m_attach_xml_file.m_RoadList.isEmpty()) {
        m_attach_xml_file.m_RoadList.clear();
    }
    if(!m_attach_xml_file.m_path_map_list.isEmpty()) {
        //qDeleteAll(m_attach_xml_file.m_path_map_list);
        m_attach_xml_file.m_path_map_list.clear();
    }
    if(!m_attach_xml_file.v_mapping_list.isEmpty()){
        m_attach_xml_file.v_mapping_list.clear();
    }

    if(get_node_from_txt){
        std::cout<<"get node from txt file."<< std::endl;
        m_attach_xml_file.GetNodeFromTxtFile();
    }else{
        std::cout<<"get node from xml file."<< std::endl;
        m_attach_xml_file.GetNodeFromFile();	//读入地图xml文件
    };
    m_attach_xml_file.InitDisplay();	//初始化显示
    m_bRecvRndf = true;
    this->ros_pub.init();

    //copy NodeList to original_road_network_list
    if(!m_attach_xml_file.original_road_network_list.isEmpty())
        m_attach_xml_file.original_road_network_list.clear();
    QList<MapSearchNode*>::iterator road_iter = m_attach_xml_file.m_astarsearch.NodeList.begin();
    for(; road_iter != m_attach_xml_file.m_astarsearch.NodeList.end(); road_iter++){
        m_attach_xml_file.original_road_network_list.append(*road_iter);
    }

    //only for test! test the BuildTopologicalMap function
    /*QList<MapSearchNode*>::iterator intersec_iter = m_attach_xml_file.m_astarsearch.NodeList.begin();
    for(; intersec_iter != m_attach_xml_file.m_astarsearch.NodeList.end(); intersec_iter++){
        if((*intersec_iter)->intersection){
            extractroad_msg::extractroad temp_intersec_data;
            temp_intersec_data.roadcount = 2;
            temp_intersec_data.leadpoints.push_back(114.38947930);
            temp_intersec_data.leadpoints.push_back(37.83803321);
            temp_intersec_data.leadpoints.push_back(114.38950377);
            temp_intersec_data.leadpoints.push_back(37.83781871);
            temp_intersec_data.vehicle_point[0] = (*intersec_iter)->lon;
            temp_intersec_data.vehicle_point[1] = (*intersec_iter)->lat;

            original_intersec_list.append(temp_intersec_data);
        }
    }*/
}

void AStarDoubleXML::on_Pathplan_clicked() {
    ROS_INFO("plan path......");
    if(!m_attach_xml_file.m_path_map_list.isEmpty()) {
        m_attach_xml_file.m_path_map_list.clear();
    }
    if(!m_bRecvRndf) {
        on_ReadFile_clicked();
    }
    if(get_node_from_txt){
        int start_id = -1;
        int end_id = -1;
        QList<MapSearchNode*>::iterator iter = m_attach_xml_file.m_astarsearch.NodeList.begin();
        for( ; iter != m_attach_xml_file.m_astarsearch.NodeList.end(); iter++) {
            if ((*iter)->type == 0)
                start_id = (*iter)->node_id;
            if ((*iter)->type == 1)
                end_id = (*iter)->node_id;
        }
        m_attach_xml_file.PathPlan(start_id, end_id);
    }else{
        if(!m_attach_xml_file.m_cMapMatch.TaskBeReaded) {
            on_ReadTaskFile_clicked();
        }
        ///Planning
        m_attach_xml_file.MatchTaskPoints(m_attach_xml_file.plan_task_list);  //匹配任务点
        m_attach_xml_file.PlanWithTaskPoint(m_attach_xml_file.plan_task_list);
    }
    //ros_pub.transPathPlanner(&m_attach_xml_file);

    QList<MapSearchNode*>::iterator path_iter = m_attach_xml_file.m_path_map_list.begin();
    std::cout << "result of path:  " << std::endl;
    for(;path_iter != m_attach_xml_file.m_path_map_list.end(); ++path_iter){
        std::cout << "   " << (*path_iter)->node_id << std::endl;
    }

    m_attach_xml_file.m_bPathPlaned = true;
    m_attach_xml_file.m_flag = 0;

    {//add pathplanfinishflag lock
        QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
        m_attach_xml_file.PathPlanFinishFlag=true;
    }
    {QMutexLocker locker(&ros_pub.mutex_attach_success);
        ros_pub.attach_success_ = true;
    }
    m_attach_xml_file.is_forward = true;

    //copy NodeList to original_road_network_list
    if(!m_attach_xml_file.original_road_network_list.isEmpty())
        m_attach_xml_file.original_road_network_list.clear();
    QList<MapSearchNode*>::iterator road_iter = m_attach_xml_file.m_astarsearch.NodeList.begin();
    for(; road_iter != m_attach_xml_file.m_astarsearch.NodeList.end(); road_iter++){
        m_attach_xml_file.original_road_network_list.append(*road_iter);
    }

    //更新发布路网
    sensor_msgs::NavSatFix current_vehicle_gps;
    {QMutexLocker locker(&ros_pub.mutex_is_rev_gps);
        if(ros_pub.is_rcv_gps){
            {QMutexLocker locker1(&ros_pub.mutex_vehicle_gps);
                current_vehicle_gps = ros_pub.vehicle_gps;}
        }
    }
    m_attach_xml_file.publishWay(current_vehicle_gps,m_attach_xml_file.m_path_map_list);
    ROS_INFO("plan path done.");
}

void AStarDoubleXML::on_ReadTaskFile_clicked() {
    {//add pathplanfinishflag lock
        QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
        m_attach_xml_file.PathPlanFinishFlag= false;
    }

    //Read task file
    if(!m_attach_xml_file.m_cMapMatch.TaskList.isEmpty()) {
        m_attach_xml_file.m_cMapMatch.TaskList.clear();
        //m_attach_xml_file.m_cMapMatch.TaskBeReaded=false;
    }
    if(!m_attach_xml_file.plan_task_list.isEmpty()){
        m_attach_xml_file.plan_task_list.clear();
    }
    sensor_msgs::NavSatFix cur_veh_gps;
    {QMutexLocker locker(&ros_pub.mutex_is_rev_gps);
        if(ros_pub.is_rcv_gps) {
            { QMutexLocker locker1(&ros_pub.mutex_vehicle_gps);
                /*m_attach_xml_file.m_cMapMatch.gps_updated = true;
                m_attach_xml_file.m_cMapMatch.currentlon =
                                                this->ros_pub.vehicle_gps.longitude;
                m_attach_xml_file.m_cMapMatch.currentlat =
                                                this->ros_pub.vehicle_gps.latitude;*/
                cur_veh_gps = this->ros_pub.vehicle_gps;
            }
        } else {
            ROS_WARN("on_ReadTaskFile_clicked(): unable to recive the gps information.");
            return;
        }
    }

    int start_num = 0;
    int forced_start_task_id = -1;
    m_attach_xml_file.m_cMapMatch.ReadTaskFile(this->base_dir);
    QList<Task_Node>::iterator iter = m_attach_xml_file.m_cMapMatch.TaskList.begin();
    for(;iter != m_attach_xml_file.m_cMapMatch.TaskList.end(); iter++){
        if(iter->manu == 100){
            forced_start_task_id = iter->Task_num;
            ROS_INFO("forced_start_task_id = %d",forced_start_task_id);
        }
    }
    int last_id,next_id;
    m_attach_xml_file.taskMapMatch(cur_veh_gps.latitude,cur_veh_gps.longitude,
                               &m_attach_xml_file.m_cMapMatch.TaskList,
                               &last_id,&next_id);
    if(forced_start_task_id != -1){
        start_num = forced_start_task_id;
    }else{
        start_num = next_id;
    }
    std::cout << "on_ReadTaskFile_clicked(), start_num = " << start_num << std::endl;
    QList<Task_Node>::iterator task_iter = m_attach_xml_file.m_cMapMatch.TaskList.begin();
    for(; task_iter != m_attach_xml_file.m_cMapMatch.TaskList.end(); task_iter++){
        if(task_iter->Task_num == start_num){
            for(;task_iter != m_attach_xml_file.m_cMapMatch.TaskList.end(); task_iter++){
                if(task_iter->Task_num == start_num){   //当检测到车辆当前位置距离第一个任务点很近时，放弃第一个任务点
                    float current_x,current_y;
                    m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(cur_veh_gps.latitude,
                            cur_veh_gps.longitude,0,0,&current_x,&current_y);
                    double car2startTask = m_attach_xml_file.distance(current_x,current_y,task_iter->x,task_iter->y);
                    if(car2startTask < 15){
                        ROS_WARN("the car is near the start task point,abondon the start task point");
                        continue;
                    }
                }
                m_attach_xml_file.plan_task_list.append(*task_iter);
            }
            break;
        }
    }

    //将当前车辆位置放入任务链表头
    Task_Node temp_node;
    temp_node.lon = cur_veh_gps.longitude;
    temp_node.lat = cur_veh_gps.latitude;
    temp_node.Task_num = 0;
    temp_node.on_road = true;
    temp_node.type = 0;
    m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(temp_node.lat,temp_node.lon,0,0,&temp_node.x,&temp_node.y);
    m_attach_xml_file.plan_task_list.prepend(temp_node);
    m_attach_xml_file.update_flag_for_task = 0;
    m_attach_xml_file.ShowPathWithPathList();  //更新显示

    //copy NodeList to original_road_network_list
    /*if(!m_attach_xml_file.original_road_network_list.isEmpty())
        m_attach_xml_file.original_road_network_list.clear();
    QList<MapSearchNode*>::iterator road_iter = m_attach_xml_file.m_astarsearch.NodeList.begin();
    for(; road_iter != m_attach_xml_file.m_astarsearch.NodeList.end(); road_iter++){
        m_attach_xml_file.original_road_network_list.append(*road_iter);
    }*/
}

void AStarDoubleXML::on_pushButton_clicked() {
    /// replanning
    QFile data(base_dir+"/taskfile_manual.txt");
    qDebug() << "output task list to " << base_dir + "/taskfile_manual.txt" << endl;
    if (data.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&data);
        for(int i = 0; i < m_attach_xml_file.plan_task_list.size(); ++i){
            std::cout << setprecision(10) << m_attach_xml_file.plan_task_list.at(i).lat << std::endl;
            out << qSetRealNumberPrecision(10) << i+1
            << " " << m_attach_xml_file.plan_task_list.at(i).lon
            << " " << m_attach_xml_file.plan_task_list.at(i).lat
            << " " << 0.0
            << " " << m_attach_xml_file.plan_task_list.at(i).type
            << "\n";
        }
    }
    std::cout << "output task list to file done." << std::endl;
    /*{
        QMutexLocker locker(&ros_pub.mutex_need_replanning);
        if(!ros_pub.need_replanning_) {
            ros_pub.need_replanning_ = true;
        }
    }*/
    /*float lat, lon;
    lat = ros_pub.vehicle_gps.latitude;
    lon = ros_pub.vehicle_gps.longitude;
    std::cout << "start replan!!!" << std::endl;

    m_attach_xml_file.RePlanning(lat,lon);

    m_attach_xml_file.m_bPathPlaned = true;
    m_attach_xml_file.m_flag = 0;*/
}

void AStarDoubleXML::automaticStart() {
    ROS_INFO("AUTOMATIC START!");
    on_ReadFile_clicked();
    ROS_INFO("automatic start: read road network done.");
    on_ReadTaskFile_clicked();
    ROS_INFO("automatic start: read task file done.");
    on_Pathplan_clicked();
    ROS_INFO("automatic start: path plan done.");
}

void AStarDoubleXML::on_OutputTxt_clicked() {
    //m_attach_xml_file.OutputTxtFileWithPath(this->base_dir);
    m_attach_xml_file.task_id = 0;
    if(!m_attach_xml_file.plan_task_list.isEmpty()){
        m_attach_xml_file.plan_task_list.clear();
    }
}

void AStarDoubleXML::RealTime(){
    BuildTopologicalMap();      //构建拓扑地图
    dataTransfer(); //更新数据

    //检查任务文件是否被更新，若更新，则重新规划
    m_attach_xml_file.m_cMapMatch.taskFile.refresh();   //更新任务文件信息
    if(m_attach_xml_file.m_cMapMatch.taskFile.lastModified() != m_attach_xml_file.m_cMapMatch.lastModifiedTime){
        qDebug() << "The task file was modified:" << m_attach_xml_file.m_cMapMatch.taskFile.lastModified() << endl;
        m_attach_xml_file.m_cMapMatch.lastModifiedTime = m_attach_xml_file.m_cMapMatch.taskFile.lastModified();
        automaticStart();
        return;
    }

    sensor_msgs::NavSatFix current_vehicle_gps;
    float x = 0.0;
    float y = 0.0;
    {QMutexLocker locker(&ros_pub.mutex_is_rev_gps);
        if(ros_pub.is_rcv_gps){
            {
                QMutexLocker locker(&ros_pub.mutex_vehicle_gps);
                current_vehicle_gps = ros_pub.vehicle_gps;

                //显示当前车辆位置
                m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(current_vehicle_gps.latitude,
                                                                  current_vehicle_gps.longitude,
                                                                  0,0,&x,&y);
                m_attach_xml_file.ShowPathWithPathList();  //更新显示
                m_attach_xml_file.ShowVelPos(x,y);//在地图内显示车辆位置
            }
        }
    }
    if(m_bRecvRndf){
        if(!m_attach_xml_file.use_coherence_mapping)
            m_attach_xml_file.findNodeType(current_vehicle_gps);
    }
    //发送当前任务点类型
    {QMutexLocker locker(&ros_pub.mutex_cur_road_type);
        ros_pub.cur_road_type = m_attach_xml_file.cur_road_type;}

    Backup(current_vehicle_gps);

    if(use_prior_map_replan){

        //因为有些功能需要拦截重规划，但不能从源头拦截重规划，有些重规划还是有必要的
        //下面拦截重规划的目的是定线巡逻，只有在路线的两个端点处才需要重规划，认为在
        //巡逻过程中由于路线确定所以是不需要重规划的
        //为添加这个功能，重规划位置的记录功能被关闭了
        if(open_fixed_line_patrol){
            //m_Replan_Task_list链表里保存了重规划触发时还未通过的任务点，m_Replan_Task_list的size初始值为0
            //当m_Replan_Task_list中的任务点数为1且车辆当前位置距离原始任务点链表中的某个端点比较近时，这是认为车
            //辆已经到端点了
            if(first_planning_flag && !m_attach_xml_file.m_cMapMatch.TaskList.isEmpty()){
                first_planning_flag = false;        //清除重规划标志
                first_path_flag = false;            //清除在倒车第一段路的标志
                double temp_dis_to_last_task = m_attach_xml_file.distance(x,y,
                        m_attach_xml_file.m_cMapMatch.TaskList.last().x,
                        m_attach_xml_file.m_cMapMatch.TaskList.last().y);
                std::cout << "trigger replanning in fixed line patrol: " << std::endl
                << "  distance to end task point is     " <<  temp_dis_to_last_task << std::endl
                << "  the size of m_Replan_Task_list is " <<  m_attach_xml_file.m_Replan_Task_list.size() << std::endl;
                if(m_attach_xml_file.m_Replan_Task_list.size() == 1 ){  /*默认最后一个任务点与车辆在同一条路上，所以此时只有起点*/
                    std::cout << "end point, vehicle return" << std::endl;
                    m_attach_xml_file.numOfPatrols++;     //累加巡逻次数
                    if(m_attach_xml_file.numOfPatrols < m_attach_xml_file.set_patrol_times){
                        first_planning_flag = true;    //只有在端点处且巡逻次数没够的时候可以重规划
                        first_path_flag = true;        //在重规划的倒车阶段不接收重规划标志
                    }
                    //反转任务链表，因为任务链表的匹配是建立在TaskList上的，不反转的话在完成第一次巡逻匹配就停止不动了
                    QList<Task_Node> temp_task_list;
                    QList<Task_Node>::iterator temp_iter = m_attach_xml_file.m_cMapMatch.TaskList.begin();
                    for(; temp_iter != m_attach_xml_file.m_cMapMatch.TaskList.end(); temp_iter++){
                        temp_task_list.append(*temp_iter);
                    }
                    m_attach_xml_file.m_cMapMatch.TaskList.clear();
                    m_attach_xml_file.m_cMapMatch.TaskList.reserve(temp_task_list.size());
                    std::reverse_copy(temp_task_list.begin(), temp_task_list.end(),
                            std::back_inserter(m_attach_xml_file.m_cMapMatch.TaskList));
                    //更改任务链表属性
                    m_attach_xml_file.m_cMapMatch.TaskList.first().type = 0;
                    m_attach_xml_file.m_cMapMatch.TaskList.last().type = 1;
                    //从TaskList中提取余下任务点
                    QList<Task_Node>::iterator task_iter = m_attach_xml_file.m_cMapMatch.TaskList.begin();
                    for(; task_iter != m_attach_xml_file.m_cMapMatch.TaskList.end(); task_iter++){
                        if(task_iter == m_attach_xml_file.m_cMapMatch.TaskList.begin()) continue;
                        m_attach_xml_file.m_Replan_Task_list.append(*task_iter);
                    }
                    m_attach_xml_file.update_flag_for_task = 0;                 //重新匹配任务点
                }
            }
        }

        if(first_planning_flag){
            first_planning_flag = false;
            ROS_INFO("replanning in prior map.");
            //add pathplanfinishflag lock
            {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag= false;}
            ROS_INFO("planning the first path ......");
            if(!m_attach_xml_file.m_astarsearch.NodeList.isEmpty()){
                m_attach_xml_file.m_astarsearch.NodeList.clear();
            }
            QList<MapSearchNode*>::iterator copy_iter = m_attach_xml_file.original_road_network_list.begin();
            for(; copy_iter != m_attach_xml_file.original_road_network_list.end(); copy_iter++){
                m_attach_xml_file.m_astarsearch.NodeList.append(*copy_iter);
            }
            //复制用于匹配的规划路径，防止规划失败，这里对需要temp_list做个说明：如果上一次重规划失败，那么v_mapping_list中指向的变量将是
            //上一次temp_mapmatch_list保存的内容，如果没有temp_list直接清空temp_list然后再讲v_mapping_list中的内容复制到team_mapmatch_list
            //中的话，就会出现错误，由于清除操作，在复制之前,v_mapping_list中全是野指针。
            QList<MapSearchNode> temp_list;
            QList<MapSearchNode*>::iterator temp_iter = m_attach_xml_file.v_mapping_list.begin();
            for(; temp_iter != m_attach_xml_file.v_mapping_list.end(); temp_iter++){
                temp_list.append(*(*temp_iter));
            }
            if(!temp_mapmatch_list.isEmpty()){
                temp_mapmatch_list.clear();
            }
            QList<MapSearchNode>::iterator path_iter = temp_list.begin();
            for(;path_iter != temp_list.end(); path_iter++){
                temp_mapmatch_list.append(*path_iter);
            }

            int value = m_attach_xml_file.RePlanning(current_vehicle_gps.latitude,current_vehicle_gps.longitude);
            ROS_INFO("the first plan done.");

            //判断倒车到上一个岔道口位置的倒车路径是否大于300米，如果大于300米，则认为该路径不合适，继续使用之前的路径
            float temp_dis = 0.0;
            if(!m_attach_xml_file.m_path_map_list.isEmpty()){
                MapSearchNode* start_point = m_attach_xml_file.m_path_map_list.first();
                MapSearchNode* end_point = m_attach_xml_file.m_path_map_list.last();
                temp_dis = m_attach_xml_file.distance(start_point->x, start_point->y,end_point->x,end_point->y);
            }
            if(temp_dis > 300 || value == 0){
                if(temp_dis > 300){
                    ROS_WARN("replanning: the first planned reversing path is more than 300 meters! replan failed.");
                    std::cout << "size of the first path:" << m_attach_xml_file.m_path_map_list.size() << std::endl
                              << "temp_dis: " << temp_dis << std::endl
                              << "first path:  " << std::endl;
                }
                QList<MapSearchNode*>::iterator path_iter = m_attach_xml_file.m_path_map_list.begin();
                for(; path_iter != m_attach_xml_file.m_path_map_list.end(); path_iter++){
                    std::cout << (*path_iter)->node_id << std::endl;
                }

                if(!m_attach_xml_file.v_mapping_list.isEmpty()){
                    m_attach_xml_file.v_mapping_list.clear();
                }
                if(!m_attach_xml_file.m_path_map_list.isEmpty()){
                    m_attach_xml_file.m_path_map_list.clear();
                }
                QList<MapSearchNode>::iterator copy_iter1 = temp_path_list.begin();
                for(; copy_iter1 != temp_path_list.end() ; copy_iter1++){
                    m_attach_xml_file.m_path_map_list.append(&(*copy_iter1));
                }
                QList<MapSearchNode>::iterator copy_iter2 = temp_mapmatch_list.begin();
                for(; copy_iter2 != temp_mapmatch_list.end(); copy_iter2++){
                    m_attach_xml_file.v_mapping_list.append(&(*copy_iter2));
                }
                first_path_flag = false;
                m_attach_xml_file.m_flag = 0;
                m_attach_xml_file.is_forward = true;
                {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                    m_attach_xml_file.PathPlanFinishFlag= true;}
                m_attach_xml_file.ShowPathWithPathList();  //更新显示
                m_attach_xml_file.publishWay(current_vehicle_gps,m_attach_xml_file.m_path_map_list);    //更新发布路网
                return;
            }

            m_attach_xml_file.is_forward = false;
            {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag= true;}
            first_planning_finished = true;     //第一次规划完成标志
            m_attach_xml_file.m_bPathPlaned = true;
            m_attach_xml_file.m_flag = 0;
        }

        if(first_planning_finished) {
            MapSearchNode *fallback_node = NULL;
            fallback_node = m_attach_xml_file.first_path.last();
            float current_x, current_y;
            m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(current_vehicle_gps.latitude,
                                                              current_vehicle_gps.longitude,
                                                              0, 0,
                                                              &current_x, &current_y);
            float temp_distance;
            if (fallback_node != NULL) {
                temp_distance = m_attach_xml_file.distance(fallback_node->x, fallback_node->y, current_x, current_y);
                {
                    QMutexLocker locker(&ros_pub.mutex_vehicle_vel);
                    if(ros_pub.vehicle_vel < 0.4){
                        ROS_INFO("vel < 0.4,wait_times_for_second_path %d",wait_times_for_second_path);
                        wait_times_for_second_path++;
                    }else{
                        wait_times_for_second_path = 0;
                    }
                }
                if (temp_distance < second_plan_trig_dis || wait_times_for_second_path > 600) {
                    {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                        m_attach_xml_file.PathPlanFinishFlag = false;}
                    first_planning_finished = false;
                    first_path_flag = false;
                    ROS_INFO("clear wait_times_for_second_path.");
                    wait_times_for_second_path = 0;
                    ROS_INFO("planning the second path ......");
                    if (!m_attach_xml_file.m_path_map_list.isEmpty()) {
                        m_attach_xml_file.m_path_map_list.clear();
                    }
                    QList<MapSearchNode *>::iterator copy_iter = m_attach_xml_file.second_path.begin();
                    for (; copy_iter != m_attach_xml_file.second_path.end(); copy_iter++) {
                        m_attach_xml_file.m_path_map_list.append(*copy_iter);
                    }
                    ROS_INFO("the second plan done.");
                    m_attach_xml_file.is_forward = true;
                    {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                        m_attach_xml_file.PathPlanFinishFlag = true;}
                    m_attach_xml_file.m_bPathPlaned = true;
                    //m_attach_xml_file.m_flag = 0;
                    m_attach_xml_file.ShowPathWithPathList();  //更新显示
                }
            } else {
                ROS_FATAL("In RealTime(): can't get fallback node\n");
            }
        }
    }else{
        if(first_planning_flag){
            ROS_INFO("replanning in real-time map.");
            {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag= false;}
            first_planning_flag = false;
            ROS_INFO("planning the first path ......");
            PlanTheFirstPath();
            ROS_INFO("the first plan done.");

            //判断倒车到上一个岔道口位置的倒车路径是否大于300米，如果大于300米，则认为该路径不合适，继续使用之前的路径
            MapSearchNode* start_point = m_attach_xml_file.m_path_map_list.first();
            MapSearchNode* end_point = m_attach_xml_file.m_path_map_list.last();
            float temp_dis = m_attach_xml_file.distance(start_point->x, start_point->y,end_point->x,end_point->y);
            if(temp_dis > 300){
                ROS_WARN("replanning: the first planned reversing path is more than 300 meters! replan failed.");
                if(!m_attach_xml_file.m_path_map_list.isEmpty()){
                    m_attach_xml_file.m_path_map_list.clear();
                }
                if(!m_attach_xml_file.v_mapping_list.isEmpty()){
                    m_attach_xml_file.v_mapping_list.clear();
                }
                QList<MapSearchNode>::iterator copy_iter = temp_path_list.begin();
                for(; copy_iter != temp_path_list.end() ; copy_iter++){
                    m_attach_xml_file.m_path_map_list.append(&(*copy_iter));
                    m_attach_xml_file.v_mapping_list.append(&(*copy_iter));
                }
                first_path_flag = false;
                m_attach_xml_file.is_forward = true;
                {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                    m_attach_xml_file.PathPlanFinishFlag= true;}
                m_attach_xml_file.ShowPathWithPathList();  //更新显示
                m_attach_xml_file.publishWay(current_vehicle_gps,m_attach_xml_file.m_path_map_list);    //更新发布路网
                return;
            }

            {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag= true;}
        }

        if(first_planning_finished) {
            MapSearchNode *fallback_node = NULL;
            QList<MapSearchNode *>::iterator road_iter = m_attach_xml_file.road_network_list.begin();
            for (; road_iter != m_attach_xml_file.road_network_list.end(); road_iter++) {
                if ((*road_iter)->node_id == m_attach_xml_file.fallback_node_id) {
                    fallback_node = *road_iter;
                    break;
                }
            }
            float current_x,current_y;
            m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(current_vehicle_gps.latitude,
                                                              current_vehicle_gps.longitude,
                                                              0,0,
                                                              &current_x,&current_y);
            float temp_distance;
            if (fallback_node != NULL) {
                temp_distance = m_attach_xml_file.distance(fallback_node->x, fallback_node->y, current_x, current_y);
                /*if(temp_distance < 10){
                    std::cout<<"distance to the fallback node:"<<temp_distance<<std::endl;
                }*/
                if (temp_distance < second_plan_trig_dis) {
                    {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                        m_attach_xml_file.PathPlanFinishFlag = false;
                    }
                    first_planning_finished = false;
                    ROS_INFO("planning the second path ......");
                    PlanTheSecondPath();
                    ROS_INFO("the second plan done.");
                    {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                        m_attach_xml_file.PathPlanFinishFlag = true;
                    }
                }
            }else{
                ROS_FATAL("In RealTime(): can't get fallback node");
            }
        }
    }
    m_attach_xml_file.publishWay(current_vehicle_gps,m_attach_xml_file.m_path_map_list);    //更新发布路网
}

void AStarDoubleXML::BuildTopologicalMap() {
    if(record_flag) {
        QMutexLocker locker(&ros_pub.mutex_is_rcv_intersec);
        if(ros_pub.is_rcv_intersec){
            ros_pub.is_rcv_intersec = false;
            QMutexLocker locker1(&ros_pub.mutex_intersec_data);
            m_attach_xml_file.AddIntersectionNode(ros_pub.intersec_data);
            /*{
                QMutexLocker locker(&ros_pub.mutex_vehicle_gps);
                m_attach_xml_file.BuildNewRoadNetwork(ros_pub.vehicle_gps);
            }

            PathPlanwithTaskPoint(end_point);*/
        } else{
            {QMutexLocker locker(&ros_pub.mutex_is_rev_gps);
                if(ros_pub.is_rcv_gps){
                    QMutexLocker locker2(&ros_pub.mutex_vehicle_gps);
                    m_attach_xml_file.AddNormalNode(ros_pub.vehicle_gps);
                }
            }
        }
    }else{
        m_attach_xml_file.topology_parent_id = m_attach_xml_file.last_intersec_id;

        float lat,lon,x,y;
        {QMutexLocker locker(&ros_pub.mutex_vehicle_gps);
            lat = ros_pub.vehicle_gps.latitude;
            lon = ros_pub.vehicle_gps.longitude;
        }
        m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(lat, lon,0,0,&x,&y);

        MapSearchNode* last_intersec_node = NULL;
        QList<MapSearchNode*>::iterator iter = m_attach_xml_file.road_network_list.begin();
        for(; iter != m_attach_xml_file.road_network_list.end(); iter++){
            if((*iter)->node_id == m_attach_xml_file.last_intersec_id){
                last_intersec_node = (*iter);
                break;
            }
        }
        if(last_intersec_node == NULL)
            ROS_FATAL("In BuildTopologicalMap(): fail to find last_intersec_node.");

        float distance_to_last_intersec = m_attach_xml_file.distance(x,y,last_intersec_node->x,last_intersec_node->y);

        if(distance_to_last_intersec < 5){      //5m
            record_flag = true;
        }
    }
}

void AStarDoubleXML::Backup(sensor_msgs::NavSatFix current_vehicle_gps) {
    {
        QMutexLocker locker(&ros_pub.mutex_need_replanning);
        if (ros_pub.need_replanning_real_time && !backup_flag && !first_path_flag) {
            if(ros_pub.need_replanning_real_time){
                ROS_INFO("tri back up, clean re-planning msg");
                ros_pub.need_replanning_real_time = false;
            }
            if(m_attach_xml_file.road_network_list.size() <= 2){
                ROS_WARN("abondon back up, the size of road_network_list is less than 2!");
                return;
            }
            {
                QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag = false;
            }
            backup_flag = true;
            first_plan_vehicle_gps = current_vehicle_gps;
            m_attach_xml_file.replan_flag = true;
            m_attach_xml_file.AddNormalNode(first_plan_vehicle_gps);       //将当前位置插入到拓扑地图中
            first_plan_start_id = m_attach_xml_file.topology_parent_id;
            m_attach_xml_file.first_plan_tri_intersec_id = m_attach_xml_file.last_intersec_id;
            //更新任务链表
            m_attach_xml_file.ReCreateTaskList(current_vehicle_gps.latitude,current_vehicle_gps.longitude);

            //判断是否在同一个位置反复触发倒车，如果在同一个地方触发倒车累加超过2次，则直接进行重规划
            if(backup_start_gps.latitude != 0 && backup_start_gps.longitude != 0){
                float backup_start_x,backup_start_y,current_x,current_y;
                m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(backup_start_gps.latitude,
                                                                  backup_start_gps.longitude,
                                                                  0, 0,
                                                                  &backup_start_x, &backup_start_y);
                m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(current_vehicle_gps.latitude,
                                                                  current_vehicle_gps.longitude,
                                                                  0, 0,
                                                                  &current_x, &current_y);
                float temp_dis = m_attach_xml_file.distance(current_x,current_y,backup_start_x,backup_start_y);
                if(temp_dis < 10 ){     //当距离上一次触发重规划位置小于15米时，认为是在同一个位置触发的重规划
                    ++repeat_tri_times;
                    ROS_WARN("it's less than 10 meters from the last trigger re-planning position, the rep-trig-times is %d",repeat_tri_times);
                } else{
                    repeat_tri_times = 0;
                    ROS_INFO("it's more than 10 meters from the last trigger re-planning position, clean rep-trig-times. ");
                }
                if(repeat_tri_times >= 1){
                    ROS_WARN("repeat the trigger in the same  place, re-planning !");
                    repeat_tri_times = 0;
                    first_planning_flag = true;
                    backup_flag = false;
                    first_path_flag = true;
                    return;
                }
            }
            backup_start_gps = current_vehicle_gps;     //更新倒车触发位置点

            //复制路径
            QList<MapSearchNode> temp_list;
            QList<MapSearchNode*>::iterator temp_iter = m_attach_xml_file.m_path_map_list.begin();
            for(;temp_iter != m_attach_xml_file.m_path_map_list.end(); temp_iter++){
                temp_list.append(*(*temp_iter));
            }
            //如果上一次重规划失败，那么m_path_map_list和v_mapping_list中指针指向的上一次重规划前的temp_path_list
            //所以这里在清除temp_path_list之前需要先用一个暂时链表把m_path_map_list保存起来
            if(!temp_path_list.isEmpty()){
                temp_path_list.clear();
            }
            QList<MapSearchNode >::iterator copy_iter = temp_list.begin();
            for (; copy_iter != temp_list.end(); copy_iter++) {
                temp_path_list.append(*copy_iter);
            }
            if (!m_attach_xml_file.m_path_map_list.isEmpty()) {
                m_attach_xml_file.m_path_map_list.clear();
            }

            //找到倒车引导点（5米）
            float backup_start_x, backup_start_y;
            m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(backup_start_gps.latitude,
                                                              backup_start_gps.longitude,
                                                              0, 0,
                                                              &backup_start_x, &backup_start_y);
            MapSearchNode* backup_ptr = NULL;
            /*if(!m_attach_xml_file.road_network_list.isEmpty()){
                backup_ptr = m_attach_xml_file.road_network_list.last();
            }else{
                ROS_WARN("the road_network_list is empty, can't back up.");
                first_path_flag = false;
                backup_flag = false;
                return;
            }
            float temp_dis;
            do{
                temp_dis = m_attach_xml_file.distance(backup_ptr->x, backup_ptr->y,
                                                      backup_start_x, backup_start_y);
                if (temp_dis <= 10 || m_attach_xml_file.m_path_map_list.isEmpty()) {
                    std::cout << "backup node is: " << backup_ptr->node_id << std::endl
                              << "dis to this backup node: " << temp_dis << std::endl;
                    m_attach_xml_file.m_path_map_list.append(backup_ptr);
                }
                if(!backup_ptr->searchParent.isEmpty()) {
                    backup_ptr = backup_ptr->searchParent.last();
                } else {
                    break;
                }
            }while(temp_dis < 5);*/
            int i = m_attach_xml_file.road_network_list.size() - 1;
            for (; i >= 0; i--) {
                double temp_dis = m_attach_xml_file.distance(m_attach_xml_file.road_network_list.at(i)->x,
                                                            m_attach_xml_file.road_network_list.at(i)->y,
                                                            backup_start_x, backup_start_y);
                double last2start = std::numeric_limits<double>::infinity();
                if(!m_attach_xml_file.m_path_map_list.isEmpty()){
                    MapSearchNode* last_ptr = m_attach_xml_file.m_path_map_list.last();
                    last2start = m_attach_xml_file.distance(last_ptr->x,last_ptr->y,backup_start_x,backup_start_y);
                    if(temp_dis < last2start){
                        ROS_WARN("backup: filter %d node.",m_attach_xml_file.road_network_list.at(i)->node_id);
                    }
                }
                if ((temp_dis <= 20.0 && temp_dis >= last2start) || m_attach_xml_file.m_path_map_list.isEmpty()) {
                    backup_ptr = m_attach_xml_file.road_network_list.at(i);
                    if (backup_ptr == NULL) {
                        ROS_WARN("Backup(): backup_ptr = NULL");
                        break;
                    } else {
                        std::cout << "   backup node is: " << backup_ptr->node_id << std::endl
                                  << "   dis to this backup node: " << temp_dis << std::endl;
                        m_attach_xml_file.m_path_map_list.append(backup_ptr);
                    }
                }
                if(temp_dis > 20.0 || i == 0){
                    break;
                }
            }
            m_attach_xml_file.is_forward = false;
            {
                QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                m_attach_xml_file.PathPlanFinishFlag = true;
            }
            m_attach_xml_file.ShowPathWithPathList();  //更新显示
        }
    }

    if(first_path_flag){    //清除在第一次重规划倒车期间接收到的重规划触发信号
        QMutexLocker locker(&ros_pub.mutex_need_replanning);
        if (ros_pub.need_replanning_real_time) {
            ROS_INFO("in first path, clean the re-planning msg!");
            ros_pub.need_replanning_real_time = false;
        }
        {
            QMutexLocker locker1(&ros_pub.mutex_first_path_flag);
            if(!ros_pub.first_path_flag){
                ros_pub.first_path_flag = true;
            }
        }
    }else{
        QMutexLocker locker1(&ros_pub.mutex_first_path_flag);
        if(ros_pub.first_path_flag){
            ros_pub.first_path_flag = false;
        }
    }

    if(backup_flag){
        float current_x,current_y;
        float backup_start_x,backup_start_y;
        m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(current_vehicle_gps.latitude,
                                                          current_vehicle_gps.longitude,
                                                          0,0,
                                                          &current_x,&current_y);
        m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(backup_start_gps.latitude,
                                                          backup_start_gps.longitude,
                                                          0,0,
                                                          &backup_start_x,&backup_start_y);
        float temp_dis = m_attach_xml_file.distance(current_x,current_y, backup_start_x,backup_start_y);
        if(temp_dis < 5){       //在未到达5米之前清除重规划触发信号
            {
                QMutexLocker locker(&ros_pub.mutex_need_replanning);
                if (ros_pub.need_replanning_real_time) {
                    ros_pub.need_replanning_real_time = false;
                }
            }
        }
        if(temp_dis > 5 || wait_times > 1){
            //清空路线，让车停在那
            if(wait_times < 1){
                {QMutexLocker locker(&ros_pub.mutex_backup_confirm);
                ros_pub.backup_confirm_flag = true;}
                std::cout << "dis to back up start position: " << temp_dis << std::endl
                          << "wait ......" << std::endl;
                wait_times++;
                wait_start_time = time(NULL);
                //确认前先发送前进的路
                {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                    m_attach_xml_file.PathPlanFinishFlag = false;}
                if(!m_attach_xml_file.m_path_map_list.isEmpty()) {
                    m_attach_xml_file.m_path_map_list.clear();
                }
                QList<MapSearchNode>::iterator copy_iter = temp_path_list.begin();
                for(; copy_iter != temp_path_list.end() ; copy_iter++){
                    m_attach_xml_file.m_path_map_list.append(&(*copy_iter));
                }
                m_attach_xml_file.is_forward = true;
                {QMutexLocker locker(&m_attach_xml_file.mutex_PathPlanFinishFlag);
                    m_attach_xml_file.PathPlanFinishFlag = true;}
                m_attach_xml_file.ShowPathWithPathList();  //更新显示
            }
            time_t record_time = time(NULL);
            if(wait_times < 40 && (double)(record_time - wait_start_time) <= 4){ //等待4S
                ROS_INFO("wait_times:%d",wait_times);
                ROS_INFO("wait time:%d",(int)(record_time - wait_start_time));
                wait_times++;
                return;
            }else{
                {QMutexLocker locker(&ros_pub.mutex_backup_confirm);
                    ros_pub.backup_confirm_flag = false;}
                ROS_INFO("wait done.");
                wait_times = 0;
            }

            {QMutexLocker locker(&ros_pub.mutex_need_replanning);       //确认是否还有重规划的信息
                if (ros_pub.need_replanning_real_time && m_attach_xml_file.m_pnexttask.type != 3
                    && m_attach_xml_file.m_pcurtask.type != 3 && m_attach_xml_file.m_pcurtask.type != 4){
                    ros_pub.need_replanning_real_time = false;
                    first_planning_flag = true;
                    backup_flag = false;
                    first_path_flag = true;
                }else{
                    if(ros_pub.need_replanning_real_time){
                        ROS_WARN("abandon replanning,because the car is at park or patrol area!");
                    }
                    ros_pub.need_replanning_real_time = false;
                    backup_flag = false;
                    first_path_flag = false;
                }
            }
        }
    }
}

void AStarDoubleXML::PlanTheFirstPath(){
    int value1 = m_attach_xml_file.findFbIntersec(first_plan_vehicle_gps);       //找到回退岔道口和普通路点
    if(!m_attach_xml_file.m_astarsearch.NodeList.isEmpty()){
        m_attach_xml_file.m_astarsearch.NodeList.clear();
    }
    QList<MapSearchNode*>::iterator copy_iter = m_attach_xml_file.road_network_list.begin();
    for(; copy_iter != m_attach_xml_file.road_network_list.end(); copy_iter++){
        m_attach_xml_file.m_astarsearch.NodeList.append(*copy_iter);
    }
    if(!m_attach_xml_file.m_path_map_list.isEmpty()) {
        m_attach_xml_file.m_path_map_list.clear();
    }
    std::cout<<"first pathplan start&stop id: "<< first_plan_start_id
             << "," <<m_attach_xml_file.fallback_node_id << std::endl;
    std::cout<<"first plan fb_intersec_id :"<<m_attach_xml_file.fb_intersec_id<< std::endl;
    int value2 = m_attach_xml_file.PathPlan(first_plan_start_id,
                                   m_attach_xml_file.fallback_node_id);

    if(value1 == 0 || value2 == 0){
        ROS_FATAL("Replanning: the first plan failed! value1= %d , value2=%d",value1,value2);
        if(!m_attach_xml_file.m_path_map_list.isEmpty()){
            m_attach_xml_file.m_path_map_list.clear();
        }
        if(!m_attach_xml_file.v_mapping_list.isEmpty()){
            m_attach_xml_file.v_mapping_list.clear();
        }
        QList<MapSearchNode>::iterator copy_iter = temp_path_list.begin();
        for(; copy_iter != temp_path_list.end() ; copy_iter++){
            m_attach_xml_file.m_path_map_list.append(&(*copy_iter));
            m_attach_xml_file.v_mapping_list.append(&(*copy_iter));
        }
        first_path_flag = false;
        m_attach_xml_file.is_forward = true;
        m_attach_xml_file.ShowPathWithPathList();  //更新显示
        return;
    }
    m_attach_xml_file.is_forward = false;
    m_attach_xml_file.first_plan_intersec_id = m_attach_xml_file.fb_intersec_id;
    first_planning_finished = true;     //第一次规划完成标志
    m_attach_xml_file.m_bPathPlaned = true;
    //m_attach_xml_file.m_flag = 0;
    m_attach_xml_file.ShowPathWithPathList();  //更新显示
}

void AStarDoubleXML::PlanTheSecondPath() {
    first_path_flag = false;
    if(!m_attach_xml_file.m_astarsearch.NodeList.isEmpty()){
        m_attach_xml_file.m_astarsearch.NodeList.clear();
    }
    QList<MapSearchNode*>::iterator copy_iter = m_attach_xml_file.original_road_network_list.begin();
    for(; copy_iter != m_attach_xml_file.original_road_network_list.end(); copy_iter++){
        m_attach_xml_file.m_astarsearch.NodeList.append(*copy_iter);
    }

    if(!m_attach_xml_file.m_path_map_list.isEmpty()) {
        m_attach_xml_file.m_path_map_list.clear();
    }

    m_attach_xml_file.FindConnectTaskID(first_plan_vehicle_gps);

    int node_num = m_attach_xml_file.original_road_network_list.size();
    int value1 = 1;
    end_task_node_id = m_attach_xml_file.original_road_network_list.at(node_num-1)->node_id;
    if(end_task_node_id != m_attach_xml_file.connect_task_id){
        std::cout<<"second pathplan start&stop id: "<< m_attach_xml_file.connect_task_id
                 << "," << end_task_node_id << std::endl;
        value1 = m_attach_xml_file.PathPlan(m_attach_xml_file.connect_task_id,
                                   end_task_node_id);
    }else{
        QList<MapSearchNode*>::iterator iter = m_attach_xml_file.original_road_network_list.begin();
        for(; iter != m_attach_xml_file.original_road_network_list.end(); iter++){
            if((*iter)->node_id == m_attach_xml_file.connect_task_id){
                m_attach_xml_file.m_path_map_list.append(*iter);
                break;
            }
        }
    }

    //add last node/last intersec/lead point to the m_path_map_list
    int value2 = m_attach_xml_file.AddPassableFork();

    if(value1 == 0 || value2 == 0){
        ROS_FATAL("Replanning: the second plan failed! value1= %d , value2= %d",value1,value2);
        if(!m_attach_xml_file.m_path_map_list.isEmpty()){
            m_attach_xml_file.m_path_map_list.clear();
        }
        QList<MapSearchNode>::iterator copy_iter = temp_path_list.begin();
        for(; copy_iter != temp_path_list.end() ; copy_iter++){
            m_attach_xml_file.m_path_map_list.append(&(*copy_iter));
        }
        m_attach_xml_file.is_forward = true;
        m_attach_xml_file.ShowPathWithPathList();  //更新显示
        return;
    }
    m_attach_xml_file.is_forward = true;
    m_attach_xml_file.m_bPathPlaned = true;
    m_attach_xml_file.m_flag = 0;
    m_attach_xml_file.ShowPathWithPathList();  //更新显示
}

void AStarDoubleXML::dataTransfer() {
    m_attach_xml_file.vehicle_vel = ros_pub.vehicle_vel;
    m_attach_xml_file.gear_position = ros_pub.gear_position;
    m_attach_xml_file.vehicle_theta = ros_pub.vehicle_pose_.z;
}
