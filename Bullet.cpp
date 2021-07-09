#include "Bullet.h"
#include "Game.h"
#include "Chicken.h"
#include "Hen.h"
#include "Egg.h"

extern Game * game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/Icons/Images/bullet.png")); // set icon for bullet object
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); // connect the timer to the move function
    timer->start(40); // move every 40 ms

}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid((*colliding_items[i])) == typeid(Chicken) || typeid((*colliding_items[i])) == typeid(Hen) ){


              game->updateStats();

              delete this;

              Chicken *temp = dynamic_cast<Chicken *>(colliding_items[i]);
              temp->decreaseHealth();
              if(temp->getHealth() == 0){
//                temp->setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));

                  if(typeid((*colliding_items[i])) == typeid(Chicken)){
                      game->increasePoint(5);
                  }
                  else if(typeid((*colliding_items[i])) == typeid(Hen)){
                      game->increasePoint(10);
                      dynamic_cast<Hen *>(temp)->isCollided = true;
                      dynamic_cast<Hen *>(temp)->dropMeat();
                      Hen::hens.remove(Hen::hens.indexOf(static_cast<Hen *>(colliding_items[i])));
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
            Egg::eggs.remove(Egg::eggs.indexOf(static_cast<Egg *>(colliding_items[i])));
            delete colliding_items[i];
        }
    }

    if(y() > 5)
        setPos(x(),y() - 50);
    else {
        scene()->removeItem(this);
        delete this;
    }

}
