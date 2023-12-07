#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
#include "Veggie.h"
#include "FieldInhabitant.h"

class Captain : public Creature
{
private:
    int captain_x;
    int captain_y;
    vector<Veggie*> collected_Veggies;

public:
    Captain(int captain_x, int captain_y);

    void addVeggie(Veggie* veggie);

    int getcaptain_x();          
    int getcaptain_y(); 
    void setcaptain_coord(int, int); 
    vector<Veggie*> getCollected_Veggies();
    void setCollected_Veggies(bool);
};

#endif // CAPTAIN_H
