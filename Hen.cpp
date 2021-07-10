#include "Hen.h"
#include "Meat.h"
#include "Egg.h"

QVector <Hen*>Hen::hens;

extern Game * game;
Hen::Hen(int w, int h, int i, int r, int c, QTimer *t) : Chicken(w, h, i, r, c, t)
{
    isCollided = false;
    health = 2;
    setPixmap(QPixmap(":/Icons/Images/hen1.png")); // set icon for bullet object
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    animation();
//    timer->start(150);
}

void Hen::animation()
{
    animationTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Hen::changeState()));
    animationTimer->start(190);
}

void Hen::dropMeat()
{

    Meat *meat = new Meat(timer);
    meat->setPos(x() , y()+20);
    scene()->addItem(meat);
}

void Hen::dropEgg()
{
    Egg *egg = new Egg(timer);
    egg->setPos(x() , y()+20);
    Egg::eggs.append(egg);
    scene()->addItem(egg);
}

void Hen::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/hen1.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/hen2.png"));
    counter++;
}


