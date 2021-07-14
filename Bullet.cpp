#include "Bullet.h"
#include "Game.h"
#include "Chicken.h"
#include "Hen.h"
#include "Egg.h"
#include "Superchicken.h"

extern Game * game;

Bullet::Bullet(QTimer *t)
{
    setPixmap(QPixmap(":/Icons/Images/bullet.png")); // set icon for bullet object
    timer = t;
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect the timer to the move function

}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); // get all of the colliding items

    // check all of the colliding items and do actions based on their types

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid((*colliding_items[i])) == typeid(Chicken) || typeid((*colliding_items[i])) == typeid(Hen)
                || typeid((*colliding_items[i])) == typeid(SuperChicken)){


              game->updateStats();

              delete this;

              Chicken *temp = dynamic_cast<Chicken *>(colliding_items[i]); // casting to access getHealth method
              temp->decreaseHealth();
              if(temp->getHealth() == 0){


                  if(typeid((*colliding_items[i])) == typeid(Chicken)){
                      game->increasePoint(5);
                  }
                  else if(typeid((*colliding_items[i])) == typeid(Hen)){
                      game->increasePoint(10);
                      dynamic_cast<Hen *>(temp)->isCollided = true;
                      dynamic_cast<Hen *>(temp)->dropMeat();
                      Hen::hens.remove(Hen::hens.indexOf(static_cast<Hen *>(colliding_items[i]))); // removing deleted hen from vector
                  }
                  else if(typeid((*colliding_items[i])) == typeid(SuperChicken)){
                      game->increasePoint(10);
                      dynamic_cast<SuperChicken *>(temp)->isCollided = true;
                      dynamic_cast<SuperChicken *>(temp)->dropMeat();
                      Hen::hens.remove(Hen::hens.indexOf(dynamic_cast<SuperChicken *>(colliding_items[i]))); //removing deleted supchick from vector
                  }

                  game->setChickenNum(game->getChickenNum() - 1);
                  delete colliding_items[i];
              }

              if(game->getChickenNum() == 0){

                  game->isLevFinished = true;
              }
              return;
        }
        else if (typeid((*colliding_items[i])) == typeid(Egg)) {
            game->increasePoint(5);
            game->updateStats();
            Egg::eggs.remove(Egg::eggs.indexOf(static_cast<Egg *>(colliding_items[i])));//removing deleted egg from vector
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    if(y() > 5)
        setPos(x(),y() - 50);
    else {
        scene()->removeItem(this);
        delete this;
    }

}
