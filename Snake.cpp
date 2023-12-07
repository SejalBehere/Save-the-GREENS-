#include "Snake.h"

Snake::Snake(int x_snake, int y_snake) : Creature("S", x_snake, y_snake)
{
    this->x_snake = x_snake;
    this->y_snake = y_snake;
}

int Snake::getS_xCoord()
{
    return x_snake;
}

int Snake::getS_yCoord()
{
    return y_snake;
}

void Snake::setSCoord(int x_snake, int y_snake)
{
    this->x_snake = x_snake;
    this->y_snake = y_snake;
}