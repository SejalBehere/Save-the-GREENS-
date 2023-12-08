#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include <string>

class FieldInhabitant 
{
private:
    string Inhabitant_symbol;

public:
    FieldInhabitant(string Inhabitant_symbol);
    virtual ~FieldInhabitant();
    
    string getInhabitant_symbol();
    void setInhabitant_symbol(string Inhabitant_symbol);
};

#endif // FIELDINHABITANT_H