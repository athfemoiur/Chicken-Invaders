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

    Chicken(int, int, int, int, int);
    QTimer *timer;
    QTimer *animationTimer;
    void animation();

public slots:
    void moveDown();
    void changeState();

private:
    int width;
    int height;
    int counter = 0;
    int index;
    int row;
    int column;
};

#endif // CHICKEN_H
