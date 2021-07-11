#include "Gift.h"
#include "Game.h"
extern Game * game;

Gift::Gift(QTimer *t)
{
    setPixmap(QPixmap(":/Icons/Images/gift.png"));
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
//    timer->start(40); // move every 40 ms
}

void Gift::moveDown()
{
    if(y() < game->getHeight()-55)
        setPos(x(),y() + 20);
    else
        delete this;
}
