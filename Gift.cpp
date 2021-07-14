#include "Gift.h"
#include "Game.h"
extern Game * game;

Gift::Gift(QTimer *t)
{
    setPixmap(QPixmap(":/Icons/Images/gift.png"));
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
}

void Gift::moveDown()
{
    if(y() < game->getHeight()-55)
        setPos(x(),y() + 20);
    else
        delete this;
}
