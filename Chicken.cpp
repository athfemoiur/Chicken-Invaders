#include "Chicken.h"
#include "Spaceship.h"
#include "Game.h"

extern Game *game;

Chicken::Chicken(int w, int h, int i, int r, int c) : width(w), height(h), index(i), row(r), column(c)
{

    setPixmap(QPixmap(":/Icons/Images/chicken3.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveDown())); // connect the timer to the move function
    timer->start(150); // move every 100 ms
    animation();
}

void Chicken::moveDown()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(SpaceShip)){
                game->ship->decreaseLife();
                game->ship->setPixmap(QPixmap(":/Icons/Images/121-1215915_explosion-clip-art-at-explode-icon.png"));
                game->ship->setPixmap(QPixmap(":/Icons/Images/ship.png"));
            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    int row = (index - 1) / column + 1;
    if(y() < height * 2 / 3 - 100 - (4 - row) * 100)
        setPos(x(), y() + 35);;
}

void Chicken::changeState()
{   if(counter % 2 == 0)
        setPixmap(QPixmap(":/Icons/Images/chicken3.png"));
    else
        setPixmap(QPixmap(":/Icons/Images/chicken4.png"));
    counter++;
}

void Chicken::animation()
{
    animationTimer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState()));
    animationTimer->start(3500);
}


