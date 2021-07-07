#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "QGraphicsPixmapItem"
#include <QKeyEvent>

class SpaceShip : public QGraphicsPixmapItem
{
public:
    SpaceShip();
    void increaseLife();
    void decreaseLife();
    int getLife() { return life; }

private:
    int life;

};

#endif // SPACESHIP_H
