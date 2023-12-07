#ifndef SNAKE_H
#define SNAKE_H

#include "Creature.h"

class Snake: public Creature
{
    private:
        int x_snake, y_snake;

    public:
        Snake(int, int);
        int getS_xCoord();          
        int getS_yCoord();          
        void setSCoord (int, int); 
};

#endif //For SNAKE_H