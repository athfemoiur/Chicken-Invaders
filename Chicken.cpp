#include "Chicken.h"
#include "Spaceship.h"



Chicken::Chicken(int w, int h, int i, int r, int c, QTimer *t) : width(w), height(h), index(i), row(r), column(c)
{
    health = 1;
    setPixmap(QPixmap(":/Icons/Images/chicken3.png")); // set icon for chicken object
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState())); // conncet timer to change state function

}

void Chicken::moveDown()
{
    int row = (index - 1) / column + 1; // moving down the chicken based on row, columns and index
    if(y() < height * 2 / 3 - 100 - (4 - row) * 100)
        setPos(x(), y() + 16);
}
// animation method
void Chicken::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/chicken3.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/chicken4.png"));
    counter++;
}

int Chicken::getHealth() const
{
    return health;
}


void Chicken::decreaseHealth()
{
    health--;
}


