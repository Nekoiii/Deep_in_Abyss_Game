#include "beginwid.h"
#include"mainview.h"
#include "help.h"
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include<QPalette>
#include<QIcon>
#include<QDebug>
#include<QMediaPlayer>
#include<QMediaPlaylist>

beginWid::beginWid(QWidget *parent) : QWidget(parent)
{
    bgmList=new QMediaPlaylist;
    bgmList->addMedia(QUrl::fromLocalFile("../Abyss/MP3a.mp3"));
    bgmList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    
    
    bgm=new QMediaPlayer(this);
    bgm->setVolume(3);
    bgm->setPlaylist(bgmList);
    bgm->play();
    
    setFixedSize(1300,1000);
    QPalette palette;
    palette.setBrush(QPalette::Background,
                     QBrush(QPixmap(":/new/prefix1/beginning.jpg").scaled(this->size())));
    this->setPalette(palette);
    
    startBut=new QPushButton(this);
    startBut->setIcon(QIcon(":/new/prefix1/start.png"));
    startBut->setIconSize(QSize(134,108));
    startBut->setGeometry(200,280,134,108);
    startBut->setFlat(true);
    
    helpBut=new QPushButton(this);
    helpBut->setIcon(QIcon(":/new/prefix1/help.png"));
    helpBut->setIconSize(QSize(134,108));
    helpBut->setGeometry(430,280,134,108);
    helpBut->setFlat(true);
    
    connect(startBut,SIGNAL(clicked()),this,SLOT(slo_start()));
    connect(helpBut,SIGNAL(clicked()),this,SLOT(slo_help()));
    
}

void beginWid::slo_start()
{
    bgm->stop();
    mainview=new MainView(this);
    mainview->show();
}

void beginWid::slo_help()
{
    help=new Help(this);
    help->show();
}














