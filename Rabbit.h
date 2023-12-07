#ifndef RABBIT_H
#define RABBIT_H

#include "Creature.h"

class Rabbit : public Creature
{
    private:
        int xRabbit, yRabbit;

    public:
        Rabbit(int, int);           // constructor taking in rabbit's and captain's position coordinates.
        int getR_xCoord();          // getter function for rabbits's x coordinate
        int getR_yCoord();          // getter function for rabbits's y coordinate
        void setRCoord (int, int);  //setter function for rabbit's coordinates.

};

#endif