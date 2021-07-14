#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "Bullet.h"
class SpaceShip :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpaceShip(QTimer * , int =3);
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
    bool getIsHeated() const;
    void setIsHeated(bool value);
    int getBcounter() const;
    void setBcounter();
    int getHeatTime() const;
    void setHeatTime(int value);
    void subBcounter();
    void resetBcounter();

private:
    int life, shootMode , bcounter , heatTime;
    bool isHeated;

};

#endif // SPACESHIP_H
