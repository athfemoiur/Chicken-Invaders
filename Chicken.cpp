#include "Chicken.h"
#include "Spaceship.h"
#include "Game.h"
extern Game *game;
Chicken::Chicken(int w, int h, int i, int r, int c) : width(w), height(h), index(i), row(r), column(c)
{
    setPixmap(QPixmap(":/Icons/Images/chicken3.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    animation();
    timer->start(150); // move every 100 ms

}

void Chicken::moveDown()
{
    int row = (index - 1) / column + 1;
    if(y() < height * 2 / 3 - 100 - (4 - row) * 100)
        setPos(x(), y() + 40);;
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
    animationTimer->start(2500);
}


