#include "Hen.h"

Hen::Hen(int w, int h, int i, int r, int c) : Chicken(w, h, i, r, c)
{
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
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState()));
    animationTimer->start(190);
}

void Hen::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/hen1.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/hen2.png"));
    counter++;
}

void Hen::moveDown()
{
    int row = (index - 1) / column + 1;
    if(y() < height * 2 / 3 - 100 - (4 - row) * 100)
        setPos(x(), y() + 14);
}
