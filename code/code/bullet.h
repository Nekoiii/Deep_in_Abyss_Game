#ifndef BULLET_H
#define BULLET_H
#include"monster.h"
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>
#include<QPixmap>

class Bullet : public Monster
{
public:
    Bullet(int hp,int mp,int atk,int speedx,int speedy);
    ~Bullet();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int phase);
    
private:
    int bullet_weight,bullet_height;
    QPixmap bulletPix;
    void changePix();
    
    
};

#endif // BULLET_H











