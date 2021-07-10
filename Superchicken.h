#ifndef SUPERCHICKEN_H
#define SUPERCHICKEN_H

#include "Hen.h"

class SuperChicken : public Hen
{
public:
    SuperChicken(int, int, int, int, int, QTimer *);

    // Chicken interface

public:
    void animation() override;
    bool isCollided;

public slots:
    void changeState() override;





};

#endif // SUPERCHICKEN_H
