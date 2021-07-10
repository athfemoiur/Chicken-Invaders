#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Meat : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Meat(QTimer *);
    QTimer *timer;
public slots:
    void moveDown();
};

#endif // MEAT_H
