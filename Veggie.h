#ifndef VEGGIE_H
#define VEGGIE_H

#include "FieldInhabitant.h"

class Veggie : public FieldInhabitant
{
    private:
    string veggieName;
    int veggiePoint;

    public:
        Veggie(string, string, int);    // constructor that takes in veggie name, veggie char and points associated.
        string getVeggieName();
        void setVeggieName(string);
        int getVeggiePoint();
        void setVeggiePoint(int);

};

#endif
