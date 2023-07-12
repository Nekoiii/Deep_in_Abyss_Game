#ifndef MUSHROOM_H
#define MUSHROOM_H
#include"monster.h"
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>
#include<QPixmap>

class Mushroom : public Monster
{
    Q_OBJECT
public:
    Mushroom(int hp,int mp,int atk,int speedx,int speedy);
    ~Mushroom();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int phase);
    
private:
    int mush_weight,mush_height;
    QPixmap mushPix;
    void changePix();
    int a_step;
};

#endif // MUSHROOM_H




































