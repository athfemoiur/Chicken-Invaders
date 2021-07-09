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

public slots:
    void changeState() override;






};

#endif // HEN_H
