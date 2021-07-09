#include "Meat.h"
#include "Game.h"
extern Game * game;
Meat::Meat()
{
    setPixmap(QPixmap(":/Icons/Images/drumsticChickenone.png")); // set icon for meat object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    timer->start(150); // move every 40 ms
}

void Meat::moveDown()
{
    if(y() < game->getHeight())
        setPos(x(),y() + 50);
    else {
        scene()->removeItem(this);
        delete this;
    }
}
