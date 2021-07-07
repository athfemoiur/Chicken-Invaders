#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "QGraphicsPixmapItem"
#include "QKeyEvent"

class SpaceShip : public QGraphicsPixmapItem
{
public:
    SpaceShip();
    void increaseLife();
    void decreaseLife();
    int getLife() { return life; }
    int getMeat() { return meat; }

private:
    int life;
    int meat;

};

#endif // SPACESHIP_H
