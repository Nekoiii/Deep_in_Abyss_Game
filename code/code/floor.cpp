#include "floor.h"
#include "mushroom.h"
#include<QPixmap>
#include<QPainter>
#include<QDebug>

int Floor::name()const
{
    return 1;
}

Floor::Floor(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    qreal i=qrand()%4;
    if(i<=1){
        floorG1.load(":/new/prefix1/floor-G1.png");
    }
    else if(i==2){
        floorG1.load(":/new/prefix1/floor-G2.png");
    }
    else{
        floorG1.load(":/new/prefix1/floor-G3.png");
    }
    floorW=570;
    floorH=540;
}


QRectF Floor::boundingRect()const
{
    return QRectF(0,0,floorW,floorH);
}

void Floor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,floorG1);
}

Floor::~Floor()
{
    qDebug()<<"delete a floor";
}






















