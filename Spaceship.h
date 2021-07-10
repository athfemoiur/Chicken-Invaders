#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "Bullet.h"
class SpaceShip :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpaceShip(QTimer *);
    void increaseLife();
    void decreaseLife();
    int getLife() { return life; }
public slots:
    void collision();



private:
    Bullet *bullet;
    QTimer *timer;
public:
    void shoot();

private:
    int life, shootMode;

};

#endif // SPACESHIP_H
