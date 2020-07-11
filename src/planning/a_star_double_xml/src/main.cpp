#include "../include/astardoublexml.h"
#include <QApplication>
#include "thread.h"
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AStarDoubleXML w(argc, argv);
    w.show();
    qDebug()<<"From main thread: "<<QThread::currentThreadId();
    Thread w_thred;     //new thread for replanning in real time and updata postion
    w_thred.AStarThread = &w;
    if(w_thred.isRunning()){
        ROS_INFO("the thread t is running.");
    }else{
        w_thred.start();
    }
    //w_thred.connect(&w_thred, SIGNAL(finished()), &w_thred, SLOT(deleteLater()));
    w_thred.connect(&app,SIGNAL(lastWindowClosed()), &w_thred,  SLOT(quit()));
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();
    return result;
    //return a.exec();
}
