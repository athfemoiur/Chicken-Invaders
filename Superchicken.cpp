#include "Superchicken.h"
#include "Meat.h"
#include "Egg.h"

extern Game * game;
SuperChicken::SuperChicken(int w, int h, int i, int r, int c, QTimer *t, QTimer *t2) : Hen(w, h, i, r, c, t, t2)
{
    //
    isCollided = false;
    health = 4;
    setPixmap(QPixmap(":/Icons/Images/superchicken3.png")); // set icon for bullet object
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    connect(timer,SIGNAL(timeout()),this,SLOT(SuperChicken::changeState()));;

}



void SuperChicken::changeState()
{
    if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/superchicken3.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/superchicken4.png"));
    counter++;
}


