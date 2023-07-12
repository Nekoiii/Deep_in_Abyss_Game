#include "replay.h"
#include<QPainter>

Replay::Replay()
{
    pix.load(":/new/prefix1/back.png");
}

QRectF Replay::boundingRect()const
{
    return QRectF(0,0,200,163);
}

void Replay::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,pix);
}







