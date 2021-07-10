#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet(QTimer *);
    QTimer * timer;

public slots:
    void move();
};

#endif // BULLET_H
