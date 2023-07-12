#include "gameover.h"
#include "mainview.h"
#include"replay.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsWidget>
#include<QTime>
#include<QTimer>
#include<QDebug>
#include<QLabel>
#include<QString>
#include<QFont>
#include<QPalette>
#include<QColor>
#include<QPixmap>

Gameover::Gameover(QWidget *parent):QGraphicsView(parent)
{
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,1300-2,1000-2);
    setScene(scene);
    
    
    
    //setBackgroundBrush(pix);
    setFixedSize(1300,1000);
    
    //Replay *rep=new Replay;
    //scene->addItem(rep);
}

















