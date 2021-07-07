#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet();

    Bullet(int x, int y);

    QTimer * timer;

public slots:
//    void move();
//    void moveE();
};

#endif // BULLET_H
