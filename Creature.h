#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h"

class Creature : public FieldInhabitant 
{
private:
    // Member variables
    int creature_x, creature_y;
    string creature_symbol;

public:
    // Constructor
    Creature(string creature_symbol, int creature_x, int creature_y);

    // Getter functions
    int getCreature_x();
    int getCreature_y();

    // Setter functions
    void setCreature_x(int creature_x);
    void setCreature_y(int creature_y);
};

#endif // CREATURE_H
