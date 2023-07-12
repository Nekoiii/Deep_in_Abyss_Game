#ifndef GAMEOVER_H
#define GAMEOVER_H
#include<QWidget>
#include<QGraphicsView>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QLabel>
#include<QPushButton>
#include<QPixmap>

class Gameover : public QGraphicsView
{
public:
    Gameover(QWidget *parent);
private:
    QGraphicsScene *scene;
    QLabel *backLab;
    QPushButton *backBut;
};

#endif // GAMEOVER_H
