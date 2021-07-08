#include "Bullet.h"
#include "Game.h"
#include "Chicken.h"
#include "QThread"
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
        if (typeid((*colliding_items[i])) == typeid(Chicken)){

              game->increasePoint();
              game->updateStats();

              delete this;
              delete colliding_items[i];

              if(game->getScore() == game->getChickenNum()*5 && game->getLevel() == 0){
                  int w= game->getWidth();
                  int h = game->getHeight();
                  delete game;
                  game = new Game(w , h , 1 );
                  game->show();

              }else if(game->getScore() == game->getChickenNum()*5 && game->getLevel()==1){
                  game->close();
              }
            // return (all code below refers to a non existint bullet)
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
