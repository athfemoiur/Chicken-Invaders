#include "Hen.h"
#include "Meat.h"
#include "Egg.h"

QVector <Hen*>Hen::hens;

extern Game * game;
Hen::Hen(int w, int h, int i, int r, int c, QTimer *t, QTimer *t2) : Chicken(w, h, i, r, c, t)
{
    eggMeatTimer = t2;
    isCollided = false;
    health = 2;
    setPixmap(QPixmap(":/Icons/Images/chicken1.png")); // set icon for bullet object
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

    Meat *meat = new Meat(eggMeatTimer);
    meat->setPos(x() , y()+20);
    scene()->addItem(meat);
}

void Hen::dropEgg()
{
    Egg *egg = new Egg(eggMeatTimer);
    egg->setPos(x() + 24 , y()+20);
    Egg::eggs.append(egg);
    scene()->addItem(egg);
}

void Hen::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/chicken1.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/chicken2.png"));
    counter++;
}


