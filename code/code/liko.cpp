#include "liko.h"
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

int Liko::name()const
{
    return 0;
}

Liko::~Liko()
{
    qDebug()<<"delete liko";
}

Liko::Liko(int hp,int mp,int atk,int speedx,int speedy):Monster(hp,mp,atk,speedx,speedy)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    LikoPix.load(":/new/prefix1/walkR1.png");
    LikoPix=LikoPix.scaled(130,130);
    PressFlag=false;
    IfLeft=false;
    IfFall=true;
    likoW=130;
    likoH=130;
    jumpTimes=0;
    count=0;
    count2=0;
    timer=new QTimer;
    KeyTime=new QTime;
    a_step=0;
    m_step=0;
}

QRectF Liko::boundingRect()const
{
    return QRectF(0,0,likoW,likoH);
}

void Liko::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    
    painter->drawPixmap(0,0,LikoPix);
}

void Liko::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case(Qt::Key_Right):{
        speedX=15;
        a_state=1;
        break;        
    }
    case(Qt::Key_Left):{
        a_state=1;
        speedX=-15;
        break;        
    }
    case(Qt::Key_C):{
        if(event->isAutoRepeat())break;
        if(jumpTimes<1){
            speedY=-20;
        }
        jumpTimes+=1;
        break;
    }
    case (Qt::Key_Down):{
        a_state=4;
        if(!event->isAutoRepeat())
            a_step=1;
        break;
    }
    case(Qt::Key_X):{
        if(event->isAutoRepeat())break;
        KeyTime->start();
        break;
    }
    case(Qt::Key_A):{
        if(event->isAutoRepeat()||this->MP<10)break;
        this->MP-=10;
        a_step=0;
        a_state=5;
        break;
    }
    default:
        break;
    }
}

void Liko::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case(Qt::Key_Right):{
        a_state=0;
        break;
    }
    case(Qt::Key_Left):{
        a_state=0; 
        break;
    }
    case(Qt::Key_Down):{
        a_state=0;
        a_step=0;
        break;
    }
    case(Qt::Key_X):{
        if(event->isAutoRepeat())break;
        if(KeyTime->elapsed()<550){
            a_state=2;
            a_step=0;
        }
        else{
            a_state=3;
            a_step=0;
        }
        break;
    }
        
    default:
        break;
    }
}

void Liko::changePix()
{
    switch (a_state) {
    case 0:{
        if(speedX<0)
            LikoPix.load(":/new/prefix1/standL.png");
        else
            LikoPix.load(":/new/prefix1/standR.png");
        update();
        break;
    }
    case 1:{
        if(speedX<0){
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/walkL1.png");break;
            case 3:LikoPix.load(":/new/prefix1/walkL2.png");break;
            case 5:LikoPix.load(":/new/prefix1/walkL3.png");break;
            case 7:LikoPix.load(":/new/prefix1/walkL4.png");a_step=0;break;
            default:
                break;
            }
        }else{
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/walkR1.png");break;
            case 3:LikoPix.load(":/new/prefix1/walkR2.png");break;
            case 5:LikoPix.load(":/new/prefix1/walkR3.png");break;
            case 7:LikoPix.load(":/new/prefix1/walkR4.png");a_step=0;break;
            default:
                break;
            }
        }
        //update();
        break;
    }
    case 2:{
        if(speedX<0){
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/attackL1.png");break;
            case 2:LikoPix.load(":/new/prefix1/attackL2.png");break;
            case 3:LikoPix.load(":/new/prefix1/attackL3.png");break;
            case 4:LikoPix.load(":/new/prefix1/attackL4.png");a_step=0;a_state=0;break;
            default:
                break;
            }
        }
        else{
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/attackR1.png");break;
            case 2:LikoPix.load(":/new/prefix1/attackR2.png");break;
            case 3:LikoPix.load(":/new/prefix1/attackR3.png");break;
            case 4:LikoPix.load(":/new/prefix1/attackR4.png");a_step=0;a_state=0;break;
            default:
                break;
            }
        }
        update();
        break;
    }
    case 3:{
        if(speedX<0){
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/dashL1.png");break;
            case 2:LikoPix.load(":/new/prefix1/dashL2.png");break;
            case 3:LikoPix.load(":/new/prefix1/dashL3.png");break;
            case 4:LikoPix.load(":/new/prefix1/dashL4.png");break;
            case 5:LikoPix.load(":/new/prefix1/dashL5.png");break;
            case 6:LikoPix.load(":/new/prefix1/dashL6.png");a_step=0;a_state=0;break;
            default:
                break;
            }
        }
        else{
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/dashR1.png");break;
            case 2:LikoPix.load(":/new/prefix1/dashR2.png");break;
            case 3:LikoPix.load(":/new/prefix1/dashR3.png");break;
            case 4:LikoPix.load(":/new/prefix1/dashR4.png");break;
            case 5:LikoPix.load(":/new/prefix1/dashR5.png");break;
            case 6:LikoPix.load(":/new/prefix1/dashR6.png");a_step=0;a_state=0;break;
            default:
                break;
            }
        }
        break;
    }
    case 4:{
        if(speedX<0){
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/DefL1.png");break;
            case 2:LikoPix.load(":/new/prefix1/DefL2.png");break;
            case 3:LikoPix.load(":/new/prefix1/DefL3.png");break;
            case 4:LikoPix.load(":/new/prefix1/DefL4.png");break;
            default:
                break;
            }
        }
        else{
            switch (a_step) {
            case 1:LikoPix.load(":/new/prefix1/DefR1.png");break;
            case 2:LikoPix.load(":/new/prefix1/DefR2.png");break;
            case 3:LikoPix.load(":/new/prefix1/DefR3.png");break;
            case 4:LikoPix.load(":/new/prefix1/DefR4.png");break;
            default:
                break;
            }
        }
        update();  //可能只有坐标移动了才会自动重绘，所以这里要加 updata()！！！！
        break;
    }
    case 5:{
        switch (a_step) {
        case 1:LikoPix.load(":/new/prefix1/Magic1.png");break;
        case 2:LikoPix.load(":/new/prefix1/Magic2.png");break;
        case 3:LikoPix.load(":/new/prefix1/Magic3.png");break;
        case 4:LikoPix.load(":/new/prefix1/Magic4.png");break;
        case 6:LikoPix.load(":/new/prefix1/Magic5.png");break;
        case 8:LikoPix.load(":/new/prefix1/Magic6.png");a_step=0;a_state=0;break;
        default:
            break;
        }
        update();
        break;
    }   
        
    default:
        break;
    }
    
    //update();
}

void Liko::fall()
{
    foreach (QGraphicsItem *t, collidingItems()){
        if(scenePos().rx()>=t->scenePos().rx()-50
                &&scenePos().rx()<=t->scenePos().rx()+510
                &&((t->scenePos().ry()-scenePos().ry())>=107)){
            Monster *mon=static_cast<Monster*>(t);
            if(mon->name()==1){
                IfFall=false;
                jumpTimes=0;
                //qDebug()<<"set jumpTimes=0";
            }
        }
    }
    if(collidingItems().isEmpty())
        IfFall=true;
    
    if(speedY<3){
        IfFall=false;
        speedY+=1;
        QPointF pos = scenePos();
        pos.ry() += speedY;
        setPos(pos); 
    }
    if(speedY>=0){
        speedY=23;
    }
    
    if(a_state==5)speedY=23;
    
    if(IfFall){
        QPointF pos = scenePos();
        pos.ry() += speedY;
        setPos(pos); 
        update();
    }
    IfFall=true;
}

void Liko::advance(int phase)
{
    if(!phase)
        return;
    fall();
    
    switch(a_state){       //0: 站立，1：走路，2：短攻，3：长攻, 4：防御，5:魔法
    case 0:{
        changePix();
        break;
    }
    case 1:{
        a_step+=1;
        changePix();
        if(speedX>=0){
            if(scenePos().rx()<=1200){
                QPointF pos = scenePos();
                pos.rx() += speedX;
                setPos(pos);
            }
        }
        else{
            if(scenePos().rx() >-40){
                QPointF pos = scenePos();
                pos.rx() += speedX;
                setPos(pos);
            }
        }
        break;
    }
    case 2:{
        changePix();
        if(a_step<4)a_step+=1;
        break;
    }
    case 3:{
        a_step+=1;
        changePix();
        if(speedX>=0){
            speedX=30;
            if(scenePos().rx()<=1200){
                QPointF pos = scenePos();
                pos.rx() += speedX;
                setPos(pos);
            }
        }
        else{
            speedX=-30;
            if(scenePos().rx() >-40){
                QPointF pos = scenePos();
                pos.rx() += speedX;
                setPos(pos);
            }
        }
        break;
    }
    case 4:{
        changePix();
        if(a_step<4) ++a_step;
        break;
    }
    case 5:{
        if(a_step<8) ++a_step;
        changePix();
        break;
    }
    default:
        break;
    }
    
    foreach (QGraphicsItem *t, collidingItems()){        //怪物碰撞检测
        Monster *mon=static_cast<Monster*>(t);
        int def=qrand()%4,i=qrand()%100,hurt;
        if(this->a_state!=4)def=0;
        
        if(mon->name()==5){
            this->HP+=20;
            this->MP+=10;
            if(this->HP>1000)this->HP=1000;
            if(this->MP>100)this->MP=100;
            mon->deleteLater();              //直接马上delete的话程序会出错
        }
        else if(mon->name()==2||mon->name()==3||mon->name()==4){
            if(i<50)
                hurt=mon->Atk-def;
            else if(i<80)
                hurt=mon->Atk-1-def;
            else if(i<95)
                hurt=0;
            else 
                hurt=mon->Atk+2-def;
            if(hurt<0)hurt=0;
            
            switch(mon->a_state){
            case 1:this->HP-=hurt;break;
                
            default:
                break;
            }
        }
        else if(mon->name()==6){
            hurt=mon->Atk-def;
            if(hurt<0)hurt=0;
            this->HP-=hurt;
            mon->deleteLater(); 
            //qDebug()<<"get shot";
        }
        
        if(this->a_state==4 && this->HP<1)
            this->HP=1;
        //qDebug()<<"Liko's HP: "<<this->HP;
        //qDebug()<<"Liko's MP: "<<this->MP;
        
    }
}






















