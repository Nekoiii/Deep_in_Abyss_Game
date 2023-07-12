#include "fish.h"
#include"monster.h"
#include<QPainter>
#include<QPixmap>
#include<QKeyEvent>
#include<QDebug>
#include<QTime>
#include<QTimer>
#include<QGraphicsObject>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QRectF>

int Fish::name()const
{
    return 5;
    qDebug()<<"fish name";
}


Fish::~Fish()
{
    qDebug()<<"delete a fish";
}

Fish::Fish(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    fish_weight=70;
    fish_height=27;
    if(speedx<0)
        fishPix.load(":/new/prefix1/fish.png");
    else
        fishPix.load(":/new/prefix1/fishR.png");
    
}

QRectF Fish::boundingRect()const
{
    return QRectF(0,0,fish_weight,fish_height);
}

void Fish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,fishPix);
}

void Fish::advance(int phase)
{
    if(!phase)
        return;
    fall();
}

void Fish::fall()
{
    if(speedY<20)
        ++speedY;
    moveBy(speedX*2,speedY);
}


















