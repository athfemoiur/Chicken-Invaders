#ifndef CHICKEN_H
#define CHICKEN_H
#include "QGraphicsPixmapItem"
#include "QObject"

class Chicken :public QObject, public QGraphicsPixmapItem
{
public:
    Chicken();
};

#endif // CHICKEN_H
