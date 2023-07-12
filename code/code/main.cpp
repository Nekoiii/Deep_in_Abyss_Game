#include"mainview.h"
#include"beginwid.h"
#include"floor.h"
#include"liko.h"
#include"mushroom.h"
#include<QApplication>
#include<QDebug>
#include<QTimer>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    
    //MainView mainview;
    //mainview.show();
    
    beginWid beginW;
    beginW.show();
    
    return app.exec();
}



























