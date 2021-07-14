#ifndef HEN_H
#define HEN_H
#include "Chicken.h"

class Hen : public Chicken
{
public:
    Hen(int, int, int, int, int, QTimer *, QTimer *);

    // Chicken interface

public:
    QTimer *eggMeatTimer;

    void dropMeat();
    void dropEgg();
    static QVector<Hen *> hens; // keeps track of hens for choosing random egg drop function
    bool isCollided;

public slots:
    void changeState() override;

};

#endif // HEN_H
