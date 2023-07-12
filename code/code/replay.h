#ifndef REPLAY_H
#define REPLAY_H
#include<QLabel>
#include<QGraphicsObject>
#include<QTime>
#include<QTimer>

class Replay : public QGraphicsItem
{
public:
    Replay();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
private:
    QPixmap pix;
};

#endif // REPLAY_H
