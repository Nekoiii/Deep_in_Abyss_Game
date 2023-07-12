#ifndef MONSTER_H
#define MONSTER_H
#include<QGraphicsObject>

class Monster : public QGraphicsObject
{
public:
    Monster(){}
    Monster(int hp,int mp,int atk,int speedx,int speedy):
        HP(hp),MP(mp),Atk(atk),speedX(speedx),speedY(speedy){}
    Monster(int speedx,int speedy,QGraphicsItem *parent=0);
    
    virtual ~Monster(){}
    virtual int name()const=0;   // 0:Liko, 1:Floor, 2:Mushroom, 3:Bear, 4:Pig, 5:Fish, 6:Bullet
    int a_state;            //状态
    int HP,MP;
    int Atk;         //攻击力
    int speedX,speedY;
    
protected:
    int step;             //动画控制
    int step2;
    int a_step;
    
    
};

#endif // MONSTER_H
