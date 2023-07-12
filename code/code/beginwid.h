#ifndef BEGINWID_H
#define BEGINWID_H
#include"mainview.h"
#include"help.h"
#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QLabel>
#include<QPalette>
#include<QIcon>
#include<QDebug>
#include<QMediaPlayer>
#include<QMediaPlaylist>

class beginWid : public QWidget
{
    Q_OBJECT
public:
    explicit beginWid(QWidget *parent = nullptr);
    
private:
    MainView *mainview;
    Help *help;
    QPushButton *startBut,*helpBut;
    QMediaPlayer *bgm;
    QMediaPlaylist *bgmList;
    
signals:
    
public slots:
    void slo_start();
    void slo_help();
    
};

#endif // BEGINWID_H











