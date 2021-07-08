#include "Bullet.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/Icons/Images/bullet.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect the timer to the move function
    timer->start(40); // move every 100 ms

}

void Bullet::move()
{
//    QList<QGraphicsItem *> colliding_items = collidingItems();

//    for (int i = 0, n = colliding_items.size(); i < n; ++i){
//        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
//            colliding_items[i]->setVisible(false);
//            game->increasePoints();
//            game->updateStats();
//            delete this;
//            // return (all code below refers to a non existint bullet)
//            return;
//        }
//    }

    if(y() > 5)
        setPos(x(),y() - 50);
    else {
        scene()->removeItem(this);
        delete this;
    }

}
