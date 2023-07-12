#include "mainview.h"
#include"floor.h"
#include"liko.h"
#include"mushroom.h"
#include"pig.h"
#include"bear.h"
#include"fish.h"
#include"bullet.h"
#include"gameover.h"
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
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QMediaPlaylist>


MainView::MainView(QWidget *parent):QGraphicsView(parent)
{
    randx=0;
    randy=1;
    Deep=1;
    score=0;
    
    /*bgm=new QSoundEffect(this);
    bgm->setSource(QUrl::fromLocalFile("F:/Qt/floorTest3/MP3_2.mp3"));
    bgm->setLoopCount(QSoundEffect::Infinite);  
    bgm->setVolume(1.0f);
    bgm->play();*/
    bgmList=new QMediaPlaylist;
    bgmList->addMedia(QUrl::fromLocalFile("../Abyss/MP3b.mp3"));
    bgmList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    bgmList->setCurrentIndex(0);
    
    bgm=new QMediaPlayer(this);
    bgm->setVolume(3);
    bgm->setPlaylist(bgmList);
    bgm->play();
    
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,1300-2,1000-2);
    
    likoPlayer=new Liko(1000,100,3,0,23);
    scene->addItem(likoPlayer);
    scene->setFocusItem(likoPlayer);
    likoPlayer->setZValue(1);    
    
    
    for(;randx<=3;){
        makeFloor();
        randx+=1;
    }
    
    //要包含头文件QGraphicsView
    setScene(scene); 
    QPixmap background(1300,1000);
    background.load(":/new/prefix1/background.jpg");
    setBackgroundBrush(background);
    setFixedSize(1300,1000);
    
    deepLab=new QLabel(this);
    deepLab->setFixedSize(200,80);
    deepLab->move(5,0);
    QFont ft("Microsoft YaHei",20,55);
    deepLab->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::Text,Qt::white);
    deepLab->setPalette(pa);
    
    scoreLab=new QLabel(this);
    scoreLab->setFixedSize(200,80);
    scoreLab->move(5,40);
    scoreLab->setFont(ft);
    scoreLab->setPalette(pa);
    
    hpLab=new QLabel(this);
    hpLab->setFixedSize(200,80);
    hpLab->move(580,880);
    hpLab->setFont(ft);
    hpLab->setPalette(pa);
    
    mpLab=new QLabel(this);
    mpLab->setFixedSize(200,80);
    mpLab->move(580,920);
    mpLab->setFont(ft);
    mpLab->setPalette(pa);
    
    deepLab->setText(QString("Deep : ")+QString::number(Deep-1));
    scoreLab->setText(QString("Score : ")+QString::number(score));
    hpLab->setText(QString("HP : ")+QString::number(likoPlayer->HP));
    mpLab->setText(QString("MP : ")+QString::number(likoPlayer->MP));
    
    m_timer = new QTimer;                        //定时刷新updata
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    m_timer->start(50);
    
    connect(this, SIGNAL(sig_moveItems()), this, SLOT(slt_moveItems()));
    connect(this,SIGNAL(sig_gameover()),this,SLOT(slt_gameover()));
}

void MainView::makeFloor()
{
    qreal x=qrand()%1300;
    qreal y=qrand()%700;
    qreal num=qrand()%7;
    Floor *floor_1=new Floor(100,100,0,0,0);
    floor_1->setPos(x-250,y+250);
    scene->addItem(floor_1);
    
    for(;num>4;--num){
        Bear *mush=new Bear(Deep*2,100,Deep/20+1,7,10);
        if(Deep<10)mush->HP=20;
        
        if(x-250<0){
            mush->setPos(x-250+400,y+250-40);
        }else if(x-250>1300-570){
            mush->setPos(x-250,y+250-40);
        }else{
            mush->setPos(x-250+250,y+250-40);
        }
        scene->addItem(mush);
    }
}

void MainView::makeFloor_2()
{
    qreal x=qrand()%1300;
    qreal y=qrand()%400;
    qreal num=qrand()%6;
    qreal i=num;
    Floor *floor_2=new Floor(100,100,0,0,0);
    floor_2->setPos(x-300,y+600);
    scene->addItem(floor_2);
    
    for(;num>2;--num){
        qreal mo=qrand()%100;
        if(i==num-1&&mo>=95){
            mo-=50;
        }
        if(mo<70){
            Bear *mush=new Bear(Deep*2,100,Deep/20+1,7,0);
            if(Deep<10)mush->HP=20;
            
            if(x-300<0){
                mush->setPos(x-300+400,y+600-40);
            }else if(x-300>1300-570){
                mush->setPos(x-300,y+600-40);
            }else{
                mush->setPos(x-300+250,y+600-40);
            }
            scene->addItem(mush);
        }
        else if(mo<95){
            Mushroom *mush=new Mushroom(Deep*3,100,Deep/15+2,7,0);
            if(Deep<10)mush->HP=30;
            
            if(x-300<0){
                mush->setPos(x-300+400,y+600-50);
            }else if(x-300>1300-570){
                mush->setPos(x-300,y+600-50);
            }else{
                mush->setPos(x-300+250,y+600-50);
            }
            scene->addItem(mush);
        }
        else{
            Pig *mush=new Pig(Deep*5,100,Deep/40+2,7,7);
            if(Deep<10)mush->HP=50;
            
            if(x-300<0){
                mush->setPos(x-300+400,y+600-150);
            }else if(x-300>1300-570){
                mush->setPos(x-300,y+600-150);
            }else{
                mush->setPos(x-300+250,y+600-150);
            }
            scene->addItem(mush);
        }
    }
}

void MainView::makeFloor_3()
{
    qreal x=qrand()%1300;
    qreal y=qrand()%400;
    qreal num=qrand()%8;
    qreal i=num;
    
    Floor *floor_2=new Floor(100,100,0,0,0);
    floor_2->setPos(x-300,y+1000);
    scene->addItem(floor_2);
    
    for(;num>2;--num){
        qreal mo=qrand()%100;
        if(i==num-1&&mo>=95){
            mo-=50;
        }
        if(mo<70){
            Bear *mush=new Bear(Deep*2,100,Deep/20+1,7,0);
            if(Deep<10)mush->HP=20;
            
            if(x-300<0){
                mush->setPos(x-300+400,y+1000-40);
            }else if(x-300>1300-570){
                mush->setPos(x-300,y+1000-40);
            }else{
                mush->setPos(x-300+250,y+1000-40);
            }
            scene->addItem(mush);
        }
        
        else{
            Mushroom *mush=new Mushroom(Deep*3,100,Deep/15+2,7,0);
            if(Deep<10)mush->HP=30;
            
            if(x-300<0){
                mush->setPos(x-300+400,y+1000-50);
            }else if(x-300>1300-570){
                mush->setPos(x-300,y+1000-50);
            }else{
                mush->setPos(x-300+250,y+1000-50);
            }
            scene->addItem(mush);
        }
    }
}

void MainView::slt_updata()
{
    scoreLab->setText(QString("Score : ")+QString::number(score));
    hpLab->setText(QString("HP : ")+QString::number(likoPlayer->HP));
    mpLab->setText(QString("MP : ")+QString::number(likoPlayer->MP));
    
    scene->setFocusItem(likoPlayer);
    
    if(likoPlayer->scenePos().ry()>700)
    {
        emit sig_moveItems();
    }
    
    QList<QGraphicsItem*>it=scene->items(Qt::DescendingOrder);
    foreach (QGraphicsItem* item, it) {
        Monster *mon=static_cast<Monster*>(item);
        if(mon->name()==4&&mon->a_state==1){
            Bullet *bul=new Bullet(100,100,Deep,10,0);
            if(bul->Atk>5)bul->Atk=5;
            if(mon->speedX>=0)bul->speedX=10;
            else bul->speedX=-10;
            bul->setPos(mon->scenePos().rx(),mon->scenePos().ry()+80);
            scene->addItem(bul);
        }
        if(mon->name()!=1&&mon->name()!=0&&mon->HP<=0){
            if(mon->name()==2){
                score+=1;
                likoPlayer->HP+=5;
                if(likoPlayer->HP>1000)likoPlayer->HP=1000;
                mon->deleteLater();
            }
            else if(mon->name()==4){
                score+=20;
                likoPlayer->MP+=10;
                if(likoPlayer->MP>100)likoPlayer->MP=100;
                mon->deleteLater();
            }
            else{
                score+=1;
                mon->deleteLater();
            }
        }
    }
    if(likoPlayer->HP<=0){
        emit sig_gameover();
    }
    if(likoPlayer->HP>0)
        scene->advance();
}

void MainView::slt_moveItems()
{
    makeFloor_3();
    
    QList<QGraphicsItem*>it=scene->items(Qt::DescendingOrder);
    foreach (QGraphicsItem* item, it) {
        Monster *mon=static_cast<Monster*>(item);
        mon->moveBy(0,-450);
        if(mon->MP<100)++mon->MP;
        if(mon->scenePos().ry()<-1540||mon->scenePos().ry()>1000
                ||mon->scenePos().rx()<-1000||mon->scenePos().rx()>2300){
            mon->deleteLater();
        }
    }
    
    int f=qrand()%100,speedx=qrand()%16,fish_y=qrand()%300;     //造鱼
    if(f<10){
        if(speedx==10)speedx=4;
        Fish *fish=new Fish(100,100,0,speedx-8,-20);
        if(speedx-10<0)
            fish->setPos(1300,fish_y+200);
        else
            fish->setPos(0,fish_y);
        scene->addItem(fish);
    }
    ++Deep;
    deepLab->setText(QString("Deep : ")+QString::number(Deep-1));
    //qDebug()<<"deep:  "<<Deep;
    makeFloor_2();
}

void MainView::slt_gameover()
{
    //qDebug()<<"ending";
    //setBackgroundBrush(Qt::white);
    gameover=new Gameover(this);
    /*Replay *rep=new Replay;
    scene->addItem(rep);
    rep->setZValue(2);*/
    //delete this;
    /*QGraphicsScene *endScene=new QGraphicsScene;
    gameover->setScene(endScene);
    Replay *rep=new Replay;
    rep->setPos(0,600);
    endScene->addItem(rep);*/
    
    /*QGraphicsView *end=new QGraphicsView;
    end->setScene(endScene);
    
    end->setBackgroundBrush(Qt::white);
    end->setFixedSize(1300,1000);*/
    QPixmap pix;
    if(score<=200){
        pix.load(":/new/prefix1/end1.JPG");
        //qDebug()<<"ending card";
    }
    else if(score<=400){
        pix.load(":/new/prefix1/end2.JPG");
    }
    else if(score<=600){
        pix.load(":/new/prefix1/end3.JPG");
    }
    else if(score<=900){
        pix.load(":/new/prefix1/end4.JPG");
    }
    else if(score<=1200){
        pix.load(":/new/prefix1/end5.JPG");
    }
    else
        pix.load(":/new/prefix1/end6.JPG");
    
    QLabel *endLab=new QLabel(gameover);
    endLab->setPixmap(pix);
    endLab->setGeometry(0,0,1300,1000);
    
    deepLab=new QLabel(gameover);
    scoreLab=new QLabel(gameover);
    QFont ft("Microsoft YaHei",40,55);
    QPalette pa;
    pa.setColor(QPalette::Text,Qt::red);
    deepLab->setPalette(pa);
    scoreLab->setPalette(pa);
    deepLab->setFont(ft);
    scoreLab->setFont(ft);
    deepLab->move(490,400);
    scoreLab->move(490,470);
    deepLab->setText(QString("Deep : ")+QString::number(Deep-1));
    scoreLab->setText(QString("Score : ")+QString::number(score));
    
    gameover->show();
    /*backLab=new QLabel(this);
      
    backBut=new QPushButton;
    backBut->setIcon(QIcon("F:/Qt/floorTest3/back.png"));
    backBut->setIconSize(QSize(134,108));
    backBut->setFlat(true);
    backBut->move(600,500);
    connect(backBut,SIGNAL(clicked()),this,SLOT(slo_back()));
    
    QGraphicsScene scene2;
    QGraphicsWidget *backWid=scene2.addWidget(backBut);
    scene2.addWidget(backWid);*/
    
    end_timer=new QTimer;
    end_timer->start(10000);
    connect(end_timer,SIGNAL(timeout()),this,SLOT(slt_back()));
}

void MainView::slt_back()
{
    delete this;
}





