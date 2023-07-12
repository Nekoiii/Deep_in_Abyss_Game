#include "bullet.h"
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

int Bullet::name()const
{
    return 6;
}

Bullet::Bullet(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    bulletPix.load(":/new/prefix1/bullet.png");
    bullet_weight=52;
    bullet_height=16;
}

Bullet::~Bullet()
{
    qDebug()<<"delete a bullet";
}

QRectF Bullet::boundingRect()const
{
    return QRectF(0,0,bullet_weight,bullet_height);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,bulletPix);
}

void Bullet::advance(int phase)
{
    if(!phase)
        return;
    moveBy(speedX,0);
    
}

















