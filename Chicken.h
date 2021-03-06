#ifndef CHICKEN_H
#define CHICKEN_H
#include "QGraphicsPixmapItem"
#include "QObject"
#include "QTimer"
#include "Game.h"

class Chicken :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Chicken(int, int, int, int, int, QTimer *);

    QTimer *timer; // timer for chicken movement

    void decreaseHealth();
    int getHealth() const;

public slots:
    virtual void moveDown();
    virtual void changeState();

protected:
    int width, height, counter = 0, index, row, column, health;
};

#endif // CHICKEN_H
