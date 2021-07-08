#include "Spaceship.h"
#include "Game.h"
#include <QDebug>
extern Game * game;

SpaceShip::SpaceShip()
{
    setFocus();

    setPixmap(QPixmap(":/Icons/Images/ship.png"));
    setPos(600 , 600);
    life = 3;
    meat = 0;
    shootMode = 0;
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
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPos(x() , y()-10);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x() , y()+10);
    }
    else if (event->key() == Qt::Key_Space)
    {
        shoot();
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
        bullet->setPos(x()+20,y()-150);
        scene()->addItem(bullet);

    }
}

void SpaceShip::Animation()
{
    timer = new QTimer();

}

void SpaceShip::stopAnimation()
{
    timer->stop();
}
