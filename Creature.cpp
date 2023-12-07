#include "Creature.h"

Creature::Creature(string creature_symbol, int creature_x, int creature_y):FieldInhabitant(creature_symbol)
{

}

int Creature::getCreature_x()
{
    return creature_x;
}

int Creature::getCreature_y() 
{
    return creature_y;
}

// Setter function definitions
void Creature::setCreature_x(int creature_x)
{
    this->creature_x = creature_x;
}

void Creature::setCreature_y(int creature_y)
{
    this->creature_y = creature_y;
}
