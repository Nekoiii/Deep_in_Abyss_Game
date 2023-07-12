#include "mushroom.h"
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

int Mushroom::name()const
{
    return 2;
}

Mushroom::Mushroom(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    mushPix.load(":/new/prefix1/mushroom1.png");
    mush_weight=100;
    mush_height=62;
    a_state=0;
    a_step=0;
}

Mushroom::~Mushroom()
{
    qDebug()<<"delete a mushroom";
}

QRectF Mushroom::boundingRect()const
{
    return QRectF(0,0,mush_weight,mush_height);
}

void Mushroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,mushPix);
}

void Mushroom::advance(int phase)
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
    //qDebug()<<x;
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
                //qDebug()<<"set x=0";
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
            case 2:this->HP-=hurt;break;
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
        //qDebug()<<"turn";
    }
    moveBy(speedX,0);
}

void Mushroom::changePix()
{
    switch(a_state){
    case 0:{
        if(speedX<0){
            switch(a_step){
            case 1:mushPix.load(":/new/prefix1/mushroom2.png");break;
            case 3:mushPix.load(":/new/prefix1/mushroom1.png");a_step=0;break;
            default:break;
            }
        }
        else{
            switch(a_step){
            case 1:mushPix.load(":/new/prefix1/mushroomR2.png");break;
            case 3:mushPix.load(":/new/prefix1/mushroomR1.png");a_step=0;break;
            default:break;
            }
        }
        break;
    }
    case 1:{
        speedY+=1;
        if(speedX<0){
            speedX-=3;
            mushPix.load(":/new/prefix1/mushroom3.png");
        }
        else{
            speedX+=3;
            mushPix.load(":/new/prefix1/mushroomR3.png");
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









