#include "Spaceship.h"
#include "Game.h"
#include "Meat.h"
#include <QDebug>
#include "Egg.h"
#include "Hen.h"
#include "Gift.h"
#include "Superchicken.h"
extern Game * game;

SpaceShip::SpaceShip(QTimer *t , int l) : life(l) , shootMode(0)
{
    bcounter=0;
    heatTime =0;
    isHeated =false;
    setFocus(); // for focus of keyevents (space)
    setPixmap(QPixmap(":/Icons/Images/ship.png"));
    setPos(900 , 900);
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(collision())); // connect the timer to the move function

}

void SpaceShip::increaseLife()
{
    life ++;
}

void SpaceShip::decreaseLife()
{
    life --;
}




void SpaceShip::collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid((*colliding_items[i])) == typeid(Chicken) || typeid((*colliding_items[i])) == typeid(Hen)
                || typeid((*colliding_items[i])) == typeid(SuperChicken)){
            if(typeid((*colliding_items[i])) == typeid(Hen)){
                static_cast<Hen *>(colliding_items[i])->isCollided = true;
                Hen::hens.remove(Hen::hens.indexOf(static_cast<Hen *>(colliding_items[i]))); // removing hen from vector
            }
            else if(typeid((*colliding_items[i])) == typeid(SuperChicken)){
                dynamic_cast<SuperChicken *>(colliding_items[i])->isCollided = true;
                Hen::hens.remove(Hen::hens.indexOf(dynamic_cast<SuperChicken *>(colliding_items[i]))); // removing superchicken from vector
            }
                decreaseLife();
                game->time_collid = game->gTime; //getting collision time for explosion
                game->isCollided = true;
                game->effect->setMedia(QUrl("qrc:/Sounds/Sounds/explosion.wav"));
                game->effect->play();
                setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));
                game->updateStats();
                delete colliding_items[i]; // deleting collided item to spaceship
                game->setChickenNum(game->getChickenNum() - 1);
                if(getLife()==0){
                   game->lose();
                }

        }

        else if(typeid(*(colliding_items[i])) == typeid(Meat)){
            game->increaseMeat();
            game->updateStats(); // updating scorebored
            delete colliding_items[i];
        }
        else if(typeid(*(colliding_items[i])) == typeid(Gift)){
            shootMode = 1; // changing shoot mode to 2
            delete colliding_items[i];
        }

        else if(typeid(*(colliding_items[i])) == typeid(Egg)){
            decreaseLife();
            game->updateStats(); // updating life board
            game->time_collid = game->gTime;
            game->isCollided = true;
            game->effect->setMedia(QUrl("qrc:/Sounds/Sounds/explosion.wav"));
            game->effect->play();
            setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));
            Egg::eggs.remove(Egg::eggs.indexOf(static_cast<Egg *>(colliding_items[i]))); // removing egg from vector
            delete colliding_items[i];
            if(getLife()==0){
               game->lose();
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
        // shooting double
        bullet = new Bullet(timer);
        bullet->setPos(x()+15,y()-150);
        scene()->addItem(bullet);

        bullet = new Bullet(timer);
        bullet->setPos(x()+80,y()-150);
        scene()->addItem(bullet);
    }
    else
    {
        // shooting single
        bullet = new Bullet(timer);
        bullet->setPos(x()+45,y()-150);
        scene()->addItem(bullet);

    }
}

bool SpaceShip::getIsHeated() const
{
    return isHeated;
}

void SpaceShip::setIsHeated(bool value)
{
    isHeated = value;
}
// for handeling bullet cool down
int SpaceShip::getBcounter() const
{
    return bcounter;
}

void SpaceShip::setBcounter()
{
    bcounter++;
}

int SpaceShip::getHeatTime() const
{
    return heatTime;
}

void SpaceShip::setHeatTime(int value)
{
    heatTime = value;
}

void SpaceShip::subBcounter()
{
    if(bcounter >0)
        bcounter--;
}

void SpaceShip::resetBcounter()
{
    bcounter=0;
}
