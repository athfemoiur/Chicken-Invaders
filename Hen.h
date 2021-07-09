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


public slots:
    void changeState() override;

    void moveDown() override;







};

#endif // HEN_H
