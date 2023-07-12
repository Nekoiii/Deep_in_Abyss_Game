#ifndef FLOOR_H
#define FLOOR_H
#include"monster.h"
#include<QGraphicsObject>
#include<QPixmap>
#include<QLabel>

typedef QList<QPixmap> QPixmaps;

class Floor : public Monster
{
    Q_OBJECT
public:
    ~Floor();
    Floor(int hp,int mp,int atk,int speedx,int speedy);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    
private:
    qreal floorX,floorY,floorW,floorH;
    //QPixmaps floorPixs;
    //QLabel *floorLab;
    QPixmap floorG1;
    
};

#endif // FLOOR_H





















