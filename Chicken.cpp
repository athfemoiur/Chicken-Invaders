#include "Chicken.h"


Chicken::Chicken(int w, int h) : width(w), height(h)
{

    setPixmap(QPixmap(":/Icons/Images/chicken3.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    timer->start(150); // move every 100 ms
    animation();
}

void Chicken::moveDown()
{
    if(y() < height * 2 / 3 - 100)
        setPos(x(), y() + 35);;
}

void Chicken::changeState()
{   if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/chicken3.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/chicken4.png"));
    counter++;
}

void Chicken::animation()
{
    animationTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState()));
    animationTimer->start(3500);
}


