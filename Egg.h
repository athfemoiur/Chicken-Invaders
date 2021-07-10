#ifndef EGG_H
#define EGG_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class Egg :public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Egg(QTimer *);
    QTimer *timer;
    int hitTime;
    bool isHited;
    static QVector<Egg *> eggs;

public slots:
    void moveDown();
};

#endif // EGG_H
