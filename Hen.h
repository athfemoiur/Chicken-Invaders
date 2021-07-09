#ifndef HEN_H
#define HEN_H
#include "Chicken.h"

class Hen : public Chicken
{
public:
    Hen(int, int, int, int, int);

    // Chicken interface

public:
    void animation() override;
    void dropMeat();
    void dropEgg();
    static QVector<Hen *> hens;

public slots:
    void changeState() override;






};

#endif // HEN_H
