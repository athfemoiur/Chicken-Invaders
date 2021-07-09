#include "Spaceship.h"
#include "Game.h"
#include "Meat.h"
#include <QDebug>
#include "Egg.h"
#include "Hen.h"
extern Game * game;

SpaceShip::SpaceShip() : life(3) , shootMode(0)
{

    setFocus(); // for focus of keyevents (space)
    setPixmap(QPixmap(":/Icons/Images/ship.png"));
    setPos(600 , 600);
    timer =new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(collision())); // connect the timer to the move function
    timer->start(10); // move every 40 ms

}

void SpaceShip::increaseLife()
{
    life ++;
}

void SpaceShip::decreaseLife()
{
    life --;
}



void SpaceShip::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Space && game->isStarted  )
    {
        shoot();
   }
}

void SpaceShip::collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid((*colliding_items[i])) == typeid(Chicken) || typeid((*colliding_items[i])) == typeid(Hen)){
            if(typeid((*colliding_items[i])) == typeid(Hen)){
                static_cast<Hen *>(colliding_items[i])->isCollided = true;
                Hen::hens.remove(Hen::hens.indexOf(static_cast<Hen *>(colliding_items[i])));
            }
                decreaseLife();
                game->time_collid = game->gTime;
                game->isCollided = true;
                setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));
                game->updateStats();
                delete colliding_items[i];
                game->setChickenNum(game->getChickenNum() - 1);
                if(getLife()==0){
                   game->resetLevel();
                }

        }

        else if(typeid(*(colliding_items[i])) == typeid(Meat)){
            game->increaseMeat();
            game->updateStats();
            delete colliding_items[i];
        }
        else if(typeid(*(colliding_items[i])) == typeid(Egg)){
            decreaseLife();
            game->updateStats();
            game->updateStats();
            game->time_collid = game->gTime;
            game->isCollided = true;
            setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));
            Egg::eggs.remove(Egg::eggs.indexOf(static_cast<Egg *>(colliding_items[i])));
            delete colliding_items[i];
            if(getLife()==0){
               game->resetLevel();
            }
        }

    }
    if(game->getChickenNum() == 0){

        game->isLevFinished = true;
        return;
    }
}

void SpaceShip::shoot()
{
    if(shootMode == 1)
    {
        bullet = new Bullet();
        bullet->setPos(x(),y()+10);
        scene()->addItem(bullet);

        bullet = new Bullet();
        bullet->setPos(x()+25,y());
        scene()->addItem(bullet);
    }
    else
    {

        bullet = new Bullet();
        bullet->setPos(x()+45,y()-150);
        scene()->addItem(bullet);

    }
}
