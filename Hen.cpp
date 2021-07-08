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

void Hen::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/hen1.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/hen2.png"));
    counter++;
}
