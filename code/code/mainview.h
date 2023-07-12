#ifndef MAINVIEW_H
#define MAINVIEW_H
#include<QWidget>
#include<QGraphicsView>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QLabel>
#include<QPushButton>
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QMediaPlaylist>
#include"liko.h"
#include"floor.h"
#include"gameover.h"
#include"replay.h"

class MainView : public QGraphicsView
{
    Q_OBJECT
public:
    MainView(QWidget *parent);
    
private:
    QGraphicsScene *scene;
    Gameover *gameover;
    QTimer *m_timer,*move_timer,*end_timer;
    Liko *likoPlayer;
    Replay *rep;
    int randx,randy;
    int Deep;
    //QSoundEffect *bgm;
    QMediaPlayer *bgm;
    QMediaPlaylist *bgmList;
    
protected:
    void makeFloor();
    void makeFloor_2();
    void makeFloor_3();
    int score;
    QLabel *deepLab,*scoreLab,*hpLab,*mpLab;
    //QLabel *backLab;
    //QPushButton *backBut;
    
signals:
    void sig_moveItems();
    void sig_gameover();
    
protected slots:
    void slt_updata();
    void slt_moveItems();
    void slt_gameover();
    void slt_back();
    
};

#endif // MAINVIEW_H













