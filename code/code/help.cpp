#include "help.h"
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include<QPalette>
#include<QIcon>
#include<QDebug>
#include<QMovie>
#include<QScopedPointer>

Help::Help(QWidget *parent):QDialog(parent)
{
    setFixedSize(1300,1000);
    QPalette palette;
    palette.setBrush(QPalette::Foreground,Qt::white);
    this->setPalette(palette);
    
    moveBut=new QPushButton(this);
    moveBut->setIcon(QIcon(":/new/prefix1/move.png"));
    moveBut->setIconSize(QSize(244,95));
    moveBut->setFlat(true);
    moveBut->move(100,100);
    defBut=new QPushButton(this);
    defBut->setIcon(QIcon(":/new/prefix1/def.png"));
    defBut->setIconSize(QSize(244,95));
    defBut->setFlat(true);
    defBut->move(100,250);
    cBut=new QPushButton(this);
    cBut->setIcon(QIcon(":/new/prefix1/C.png"));
    cBut->setIconSize(QSize(244,95));
    cBut->setFlat(true);
    cBut->move(100,400);
    xBut=new QPushButton(this);
    xBut->setIcon(QIcon(":/new/prefix1/X.png"));
    xBut->setIconSize(QSize(244,95));
    xBut->setFlat(true);
    xBut->move(100,550);
    xlongBut=new QPushButton(this);
    xlongBut->setIcon(QIcon(":/new/prefix1/X_long.png"));
    xlongBut->setIconSize(QSize(244,95));
    xlongBut->setFlat(true);
    xlongBut->move(100,700);
    aBut=new QPushButton(this);
    aBut->setIcon(QIcon(":/new/prefix1/A.png"));
    aBut->setIconSize(QSize(244,95));
    aBut->setFlat(true);
    aBut->move(100,850);
    backBut=new QPushButton(this);
    backBut->setIcon(QIcon(":/new/prefix1/back.png"));
    backBut->setIconSize(QSize(134,108));
    backBut->setFlat(true);
    backBut->move(10,0);
    
    gifLab=new QLabel(this);
    gifLab->setFixedSize(800,800);
    gifLab->move(500,100);
    gifMov=new QMovie(":/new/prefix1/standGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
    
    connect(moveBut,SIGNAL(clicked()),this,SLOT(slo_moveGif()));
    connect(defBut,SIGNAL(clicked()),this,SLOT(slo_defGif()));
    connect(cBut,SIGNAL(clicked()),this,SLOT(slo_cGif()));
    connect(xBut,SIGNAL(clicked()),this,SLOT(slo_xGif()));
    connect(xlongBut,SIGNAL(clicked()),this,SLOT(slo_xlongGif()));
    connect(aBut,SIGNAL(clicked()),this,SLOT(slo_aGif()));
    connect(backBut,SIGNAL(clicked()),this,SLOT(slo_back()));
    
}

void Help::slo_back()
{
    delete this;
}

void Help::slo_moveGif()
{
    gifMov=new QMovie(":/new/prefix1/moveGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}

void Help::slo_defGif()
{
    gifMov=new QMovie(":/new/prefix1/defGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}

void Help::slo_cGif()
{
    gifMov=new QMovie(":/new/prefix1/jumpGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}

void Help::slo_xGif()
{
    gifMov=new QMovie(":/new/prefix1/attackGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}

void Help::slo_xlongGif()
{
    gifMov=new QMovie(":/new/prefix1/dashGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}

void Help::slo_aGif()
{
    gifMov=new QMovie(":/new/prefix1/magicGif.gif");
    gifMov->setScaledSize(gifLab->size());
    gifLab->setMovie(gifMov);
    gifMov->start();
}














