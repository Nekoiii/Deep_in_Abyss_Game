#ifndef PIG_H
#define PIG_H
#include"monster.h"
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>
#include<QPixmap>

class Pig : public Monster
{
    Q_OBJECT
public:
    Pig(int hp,int mp,int atk,int speedx,int speedy);
    ~Pig();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int phase);
    
private:
    int pig_weight,pig_height;
    QPixmap pigPix;
    void changePix();
    int a_step;
};

#endif // PIG_H
