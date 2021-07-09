#include "Meat.h"
#include "Game.h"
extern Game * game;
Meat::Meat()
{
    setPixmap(QPixmap(":/Icons/Images/drumsticChickenone.png")); // set icon for meat object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    timer->start(80); // move every 40 ms
}

void Meat::moveDown()
{
    if(y() < game->getHeight()-20)
        setPos(x(),y() + 30);
    else {
        scene()->removeItem(this);
        delete this;
    }
}
