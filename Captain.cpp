#include "Captain.h"

Captain::Captain(int captain_x, int captain_y) : Creature("V", captain_x, captain_y)
{
    this->captain_x = captain_x;
    this->captain_y = captain_y;     
}

void Captain::addVeggie(Veggie* veggie)
{
    collected_Veggies.push_back(veggie); 
}

int Captain::getcaptain_x()
{
    return captain_x;
}

int Captain::getcaptain_y()
{
    return captain_y;
}

vector<Veggie*> Captain::getCollected_Veggies()
{
    return collected_Veggies;
}

void Captain::setCollected_Veggies(bool less_than_five)
{
    if(less_than_five)
        collected_Veggies.clear();
    else
    {
        for(int i=0; i<5; i++)
        {
            collected_Veggies.pop_back();
        }
    }
}

void Captain::setcaptain_coord(int captain_x, int captain_y)
{
    this->captain_x = captain_x;
    this->captain_y = captain_y;
}
