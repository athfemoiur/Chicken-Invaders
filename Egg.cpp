#include "Egg.h"
#include "Game.h"

extern Game *game;

QVector<Egg *>Egg::eggs;

Egg::Egg(QTimer *t)
{
    setPixmap(QPixmap(":/Icons/Images/egg.png")); // set icon for egg object
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    isHited = false;
}


void Egg::moveDown()
{
    if(y() < game->getHeight()-55)
        setPos(x(),y() + 22);
    else {
        setPixmap(QPixmap(":/Icons/Images/fEgg.png")); // changing to fried egg
        hitTime = game->gTime; // keeping hit time for removing fried egg
        isHited = true;
    }
}
