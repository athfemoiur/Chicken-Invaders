#include "Hen.h"
#include "Meat.h"
#include "Egg.h"

QVector <Hen*>Hen::hens;

extern Game * game;
Hen::Hen(int w, int h, int i, int r, int c) : Chicken(w, h, i, r, c)
{
    isCollided = false;
    health = 2;
    setPixmap(QPixmap(":/Icons/Images/hen1.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    animation();
    timer->start(150);
}

void Hen::animation()
{
    animationTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Hen::changeState()));
    animationTimer->start(190);
}

void Hen::dropMeat()
{

    Meat *meat = new Meat();
    meat->setPos(x() , y()+20);
    scene()->addItem(meat);
}

void Hen::dropEgg()
{
    Egg *egg = new Egg();
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


