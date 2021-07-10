#include "Egg.h"
#include "Game.h"

extern Game *game;

QVector<Egg *>Egg::eggs;

Egg::Egg(QTimer *t)
{
    setPixmap(QPixmap(":/Icons/Images/egg.png")); // set icon for bullet object
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
//    timer->start(40); // move every 40 ms
    isHited = false;
}


void Egg::moveDown()
{
    if(y() < game->getHeight()-55)
        setPos(x(),y() + 44);
    else {
        setPixmap(QPixmap(":/Icons/Images/fEgg.png"));
        hitTime = game->gTime;
        isHited = true;
    }
}
