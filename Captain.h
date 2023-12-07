#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
#include "Veggie.h"
#include "FieldInhabitant.h"

class Captain : public Creature
{
private: 
    // Member Variables
    int captain_x;
    int captain_y;
    vector<Veggie*> collected_Veggies;

public:
    // Constructor
    Captain(int captain_x, int captain_y); 

    // Member Functions
    void addVeggie(Veggie* veggie);

    // Getter and setter functions
    int getcaptain_x();          
    int getcaptain_y(); 
    void setcaptain_coord(int, int); 
    vector<Veggie*> getCollected_Veggies();
    void setCollected_Veggies();
};

#endif // CAPTAIN_H
