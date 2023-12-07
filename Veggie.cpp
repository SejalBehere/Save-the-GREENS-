#include "Veggie.h"

Veggie::Veggie(string veggieName, string veggieChar, int veggiePoint) : FieldInhabitant (veggieChar)
{
    this->veggieName = veggieName;
    this->veggiePoint = veggiePoint;
}

string Veggie::getVeggieName()
{
    return veggieName;
}

int Veggie::getVeggiePoint()
{
    return veggiePoint;
}

void Veggie::setVeggieName(string veggieName)
{
    this->veggieName = veggieName;
}

void Veggie::setVeggiePoint(int veggiePoint)
{
    this->veggiePoint = veggiePoint;
}