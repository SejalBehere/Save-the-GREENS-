#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include "Veggie.h"
#include "Snake.h"
#include <cstdlib>
#include <ctime>

class GameEngine
{
    private:
        //variables to store the height, width of the field and score of the player.
        int height, width, score;

        //A FieldInhabitant triple pointer
        FieldInhabitant*** field;

        // number of rabbits and number of veggies initalized
        const int NUMBEROFVEGGIES = 30, NUMBEROFRABBITS = 5;

        Captain* captain_pointer;
        vector <Rabbit*> rabbit_pointer;
        vector <Veggie*> veggie_pointer;
        Snake* snake_pointer;

        //functions within initializeGame()
        void initVeggies();
        void initCaptain();
        void initRabbits();
        void initSnake();

        //functions to move Captain
        void moveCptVertical(int);
        void moveCptHorizontal(int);

    public:
        void initializeGame();
        void intro();
        void printField();
        void moveRabbits();
        void moveSnake();
        void moveCaptain();
        void gameOver();

        int getScore();     //return the players score
        int remainingVeggies(); //returns the veggies remaining on field


};
#endif