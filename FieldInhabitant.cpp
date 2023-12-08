#include "FieldInhabitant.h"

FieldInhabitant::FieldInhabitant(string Inhabitant_symbol) //constructor
 {
    this->Inhabitant_symbol = Inhabitant_symbol;
 }

FieldInhabitant::~FieldInhabitant() //Virtual Deconstructor
{

}

string FieldInhabitant::getInhabitant_symbol() //Getter function
{
    return Inhabitant_symbol;
}

void FieldInhabitant::setInhabitant_symbol(string Inhabitant_symbol)//Setter function
{
    this->Inhabitant_symbol = Inhabitant_symbol;
}