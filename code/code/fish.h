#ifndef FISH_H
#define FISH_H
#include"monster.h"
#include<QGraphicsObject>
#include<QPixmap>

class Fish : public Monster
{
    Q_OBJECT
public:
    Fish(int hp,int mp,int atk,int speedx,int speedy);
    ~Fish();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int phase);
    void fall();
    
private:
    int fish_weight,fish_height;
    QPixmap fishPix;
    
    
};

#endif // FISH_H











