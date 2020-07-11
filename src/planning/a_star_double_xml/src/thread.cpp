//
// Created by tb on 18-6-14.
//

#include "../include/thread.h"
#include <QDir>

Thread::Thread() {
    std::cout << "constructe thread class" << std::endl;
    currentLat=0;
    currentLon=0;
    //automatic_start = true;     //自动启动开关
    rcv_task_file = false;
    auto_start_suc = false;
//    this->base_dir = ros::package::getPath("a_star_double_xml");
//    task_file_dir = QString::fromStdString(base_dir + "/task_file_dir/KYXZ2018A.txt");
    QString home = QDir::homePath();
    task_file_dir = home + "/taskfile/WRXLC2019.txt";
    qDebug() << "task file dir: " << task_file_dir << endl;
}

void Thread::run()
{
    //初始化参数
    automatic_start = AStarThread->ros_pub.run_param.automatic_start;
    std::cout << "automatic start: " << std::boolalpha << automatic_start << std::endl;
    std::cout <<"From thread run function: "<<currentThreadId();
    QTimer* m_pTimer = new QTimer();
    m_pTimer->setInterval(100);         //10hz
    //connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()) , Qt::DirectConnection);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    m_pTimer->start();
    this->exec();
    return;
}

void Thread::onTimeout() {
    //qDebug()<<"From ontimeout function thread: "<<currentThreadId();
    //****update the current location of vehicle*****//
    {
        QMutexLocker locker(&AStarThread->ros_pub.mutex_is_rev_gps);
        if(AStarThread->ros_pub.is_rcv_gps){
            {
                QMutexLocker locker(&AStarThread->ros_pub.mutex_vehicle_gps);
                currentLon=AStarThread->ros_pub.vehicle_gps.longitude;
                currentLat=AStarThread->ros_pub.vehicle_gps.latitude;
            }
        }else{
            ROS_WARN("waiting for gps msg ...");
            return;
        }
    }

    //启动程序/实时构建地图/实时检测是否重规划
    if(automatic_start){
        if(!rcv_task_file){
            if (QFile::exists(task_file_dir)){
                ROS_INFO("task file received.");
                rcv_task_file = true;
            }else{
                ROS_WARN("Waiting to recv task file");
                return;
            }
        }
        if(rcv_task_file && !auto_start_suc){
            auto_start_suc = true;
            AStarThread->automaticStart();
        }
        if(auto_start_suc){
            AStarThread->RealTime();
        }
    } else {
        AStarThread->RealTime();
    }

    //匹配
    {
        //add pathplanFinishFlag lock
        QMutexLocker locker(&(AStarThread->m_attach_xml_file.mutex_PathPlanFinishFlag));
        if(AStarThread->m_attach_xml_file.PathPlanFinishFlag) {
            AStarThread->m_attach_xml_file.mapMatchAndUpdate(currentLat,currentLon);
        }
    }

    //only for test! test the BuildTopologicalMap function
    /*float current_x,current_y;
    float intersec_x,intersec_y;
    AStarThread->m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(currentLat,currentLon,0,0,&current_x,&current_y);
    float distance_to_last_intersec =100;
    QList<extractroad_msg::extractroad>::iterator intersec_iter = AStarThread->original_intersec_list.begin();
    for(; intersec_iter != AStarThread->original_intersec_list.end(); intersec_iter++) {
        AStarThread->m_attach_xml_file.Position_Trans_From_ECEF_To_UTM(
                (*intersec_iter).vehicle_point[1], (*intersec_iter).vehicle_point[0], 0, 0, &intersec_x, &intersec_y);
        distance_to_last_intersec =
                AStarThread->m_attach_xml_file.distance(current_x, current_y, intersec_x, intersec_y);
        if (distance_to_last_intersec < 15) {
            {
                QMutexLocker locker(&AStarThread->ros_pub.mutex_is_rcv_intersec);
                AStarThread->ros_pub.is_rcv_intersec = true;
            }
            {
                QMutexLocker locker(&AStarThread->ros_pub.mutex_intersec_data);
                AStarThread->ros_pub.intersec_data = (*intersec_iter);
            }
        }
    }*/
}
