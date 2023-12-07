#include "Captain.h"

Captain::Captain(int captain_x, int captain_y) : Creature("V", captain_x, captain_y) //Constructor defintion
{
    this->captain_x = captain_x;
    this->captain_y = captain_y;     
}

void Captain::addVeggie(Veggie* veggie) //Member funtion definition
{
    collected_Veggies.push_back(veggie); 
}

//Getter funtion definitions
int Captain::getcaptain_x()
{
    return captain_x;
}

int Captain::getcaptain_y()
{
    return captain_y;
}

// Member funtion
vector<Veggie*> Captain::getCollected_Veggies()
{
    return collected_Veggies;
}

// Setter funtion definitions
void Captain::setCollected_Veggies()
{

}

void Captain::setcaptain_coord(int captain_x, int captain_y)
{
    this->captain_x = captain_x;
    this->captain_y = captain_y;
}
