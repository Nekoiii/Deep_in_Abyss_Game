#ifndef BEAR_H
#define BEAR_H
#include"monster.h"
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>
#include<QPixmap>

class Bear : public Monster
{
    Q_OBJECT
public:
    Bear(int hp,int mp,int atk,int speedx,int speedy);
    ~Bear();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int phase);
    
private:
    int bear_weight,bear_height;
    qreal bear_x,bear_y;
    QPixmap bearPix;
    void changePix();
    int a_step;
    
};

#endif // BEAR_H
