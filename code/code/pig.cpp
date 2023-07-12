#include "pig.h"
#include"monster.h"
#include "bullet.h"
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

int Pig::name()const
{
    return 4;
}

Pig::Pig(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    pigPix.load(":/new/prefix1/tama1.png");
    pig_weight=200;
    pig_height=163;
    a_state=0;
    a_step=0;
}

Pig::~Pig()
{
    qDebug()<<"delete a pig";
}

QRectF Pig::boundingRect()const
{
    return QRectF(0,0,pig_weight,pig_height);
}

void Pig::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,pigPix);
}

void Pig::advance(int phase)
{
    if(!phase)
        return;
    
    int i=qrand()%100;
    if(i<5){
        a_state=1;
        speedY=-4;
    }
    else{
        if(speedX<0)speedX=-7;
        else speedX=7;
    }
    
    ++a_step;
    changePix();
    
    qreal x=qrand()%30;
    int a=30,b=440,c=140;
    if(a_state==1){
        a=10;b=410;
    }
    else{
        a=30;b=440;
    }
    foreach (QGraphicsItem *t, collidingItems()){
        if((scenePos().rx()<t->scenePos().rx()-a
            ||scenePos().rx()>t->scenePos().rx()+b
            ||scenePos().rx()<-30
            ||scenePos().rx()>1350)
                &&scenePos().ry()<t->scenePos().ry()-c){
            Monster *mon=static_cast<Monster*>(t);
            switch(mon->name()){
            case 1:{
                x=0;
                break;
            }
            default:
                break;
            }
        }
    }
    foreach (QGraphicsItem *t, collidingItems()){
        Monster *mon=static_cast<Monster*>(t);
        switch(mon->name()){
        case 0:{
            int i=qrand()%100;
            int hurt;
            if(i<50)
                hurt=mon->Atk;
            else if(i<80)
                hurt=mon->Atk-1;
            else if(i<95)
                hurt=0;
            else 
                hurt=mon->Atk+2;
            
            switch(mon->a_state){
            case 2:
                this->HP-=hurt;break;
            case 3:
                if(hurt>1)
                    this->HP-=(hurt-1);
                else
                    this->HP-=hurt;
                break;
            case 5:{
                if(hurt==0)hurt=1;
                this->HP-=hurt*2;
                break;
            }
            default:
                break;
            }
            qDebug()<<"HP: "<<this->HP;
        }
        default:
            break;
        }
    }
    if(x<1){
        speedX=-speedX;
    }
    moveBy(speedX,0);
}



void Pig::changePix()
{
    switch(a_state){
    case 0:{
        if(speedX<0){
            switch(a_step){
            case 1:pigPix.load(":/new/prefix1/tama2.png");break;
            case 3:pigPix.load(":/new/prefix1/tama1.png");a_step=0;break;
            default:break;
            }
        }
        else{
            switch(a_step){
            case 1:pigPix.load(":/new/prefix1/tamaR2.png");break;
            case 3:pigPix.load(":/new/prefix1/tamaR1.png");a_step=0;break;
            default:break;
            }
        }
        break;
    }
    case 1:{
        speedY+=1;
        if(speedX<0){
            speedX-=3;
            switch(a_step){
            case 1:pigPix.load(":/new/prefix1/tama3.png");break;
            case 3:pigPix.load(":/new/prefix1/tama4.png");a_step=0;break;
            default:break;
            }
        }
        else{
            speedX+=3;
            switch(a_step){
            case 1:pigPix.load(":/new/prefix1/tamaR3.png");break;
            case 3:pigPix.load(":/new/prefix1/tamaR4.png");a_step=0;break;
            default:break;
            }
        }
        if(speedY>3){
            a_state=0;
            a_step=0;
            speedY=0;
            //qDebug()<<"set a_state=0";
        }
        break;
    }
    default:
        break;
    }
} 





















