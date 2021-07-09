#include "Superchicken.h"
#include "Meat.h"
#include "Egg.h"

extern Game * game;
SuperChicken::SuperChicken(int w, int h, int i, int r, int c) : Hen(w, h, i, r, c)
{
    isCollided = false;
    health = 4;
    setPixmap(QPixmap(":/Icons/Images/superchicken1.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    animation();
    timer->start(150);
}

void SuperChicken::animation()
{
    animationTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(SuperChicken::changeState()));
    animationTimer->start(190);
}

void SuperChicken::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/superchicken1.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/superchicken2.png"));
    counter++;
}


