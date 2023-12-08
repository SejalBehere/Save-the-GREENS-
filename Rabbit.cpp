#include "Rabbit.h"

Rabbit::Rabbit(int xRabbit, int yRabbit) : Creature("R",xRabbit, yRabbit)
{
    this->xRabbit = xRabbit;
    this->yRabbit = yRabbit;
}

int Rabbit::getR_xCoord()
{
    return xRabbit;
}

int Rabbit::getR_yCoord()
{
    return yRabbit;
}

void Rabbit::setRCoord(int xRabbit, int yRabbit)
{
    this->xRabbit = xRabbit;
    this->yRabbit = yRabbit;
}
