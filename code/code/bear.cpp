#include "bear.h"
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

int Bear::name()const
{
    return 3;
}

Bear::Bear(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    bearPix.load(":/new/prefix1/bear1.png");
    bear_weight=100;
    bear_height=62;
    a_state=0;
    a_step=0;
}

Bear::~Bear()
{
    qDebug()<<"delete a bear";
}

QRectF Bear::boundingRect()const
{
    return QRectF(0,0,bear_weight,bear_height);
}

void Bear::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,bearPix);
}

void Bear::advance(int phase)
{
    if(!phase)
        return;
    
    int i=qrand()%100;
    if(i<3){
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
    int a=20,b=490,c=30;
    if(a_state==1){
        a=0;b=470;c=30;
    }
    else{
        a=20;b=490;c=30;
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
    foreach (QGraphicsItem *t, collidingItems()){           //被攻击
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
            //qDebug()<<"HP: "<<this->HP;
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

void Bear::changePix()
{
    switch(a_state){
    case 0:{
        if(speedX<0){
            switch(a_step){
            case 1:bearPix.load(":/new/prefix1/bear2.png");break;
            case 3:bearPix.load(":/new/prefix1/bear1.png");a_step=0;break;
            default:break;
            }
        }
        else{
            switch(a_step){
            case 1:bearPix.load(":/new/prefix1/bearR2.png");break;
            case 3:bearPix.load(":/new/prefix1/bearR1.png");a_step=0;break;
            default:break;
            }
        }
        break;
    }
    case 1:{
        speedY+=1;
        if(speedX<0){
            speedX-=3;
            bearPix.load(":/new/prefix1/bear3.png");
        }
        else{
            speedX+=3;
            bearPix.load(":/new/prefix1/bearR3.png");
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


















