#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "Bullet.h"
class SpaceShip : public QGraphicsPixmapItem
{
public:
    SpaceShip();
    void increaseLife();
    void decreaseLife();
    void increaseMeat();
    void resetMeat();
    int getLife() { return life; }
    int getMeat() { return meat; }
    void collision();
private:
    void keyPressEvent(QKeyEvent * event);// for Handlening Movement

private:
    Bullet *bullet;
    QTimer *timer;
private:
    void shoot();
private:
    int life, meat, shootMode;

};

#endif // SPACESHIP_H
