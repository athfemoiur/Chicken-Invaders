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
    int getLife() { return life; }
    int getMeat() { return meat; }
    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    Bullet *bullet;
    void shoot();
private:
    int life;
    int meat;
    int shootMode;

};

#endif // SPACESHIP_H
