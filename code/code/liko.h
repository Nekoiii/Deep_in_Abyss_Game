#ifndef LIKO_H
#define LIKO_H
#include"monster.h"
#include<QLabel>
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>


class Liko : public Monster
{
    Q_OBJECT
public:
    Liko(int hp,int mp,int atk,int speedx,int speedy);
    ~Liko();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void fall();
    void advance(int phase);
    
private:
    qreal likoW,likoH;
    int jumpTimes;
    QPixmap LikoPix;
    QTimer *timer;
    QTime *KeyTime;
    int count;
    int count2;
                           //a_state——0: 站立，1：走路，2：短攻，3：长攻, 4：防御，5:魔法
    bool PressFlag;
    bool IfLeft;
    bool IfFall;
    int m_step,a_step;
    
    
    
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void changePix();
    
};

#endif // LIKO_H





















