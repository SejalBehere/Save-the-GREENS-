/*
Authors: Krupansh Shah, Sakshi Pol, Sejal Behere
Date: 12/07/2023
Discription: A farm game wherein the captain(you) have to collect as much veggies as possible before the rabbits wipe out your farm.
*/
#include "GameEngine.h"

int main()
{
    srand(time(0));
    GameEngine game;

    // game is initialized and user is ased for the file
    game.initializeGame();

    // game rules are displayed
    game.intro();

    int remaining_veggies = game.remainingVeggies();

    //while the veggies remain the field the game continues
    while(remaining_veggies>0)
    {
        cout << remaining_veggies << " veggies remaining. ";        //user gets to see the number of veggies in the field
        cout << "Current score: " << game.getScore() << endl;       //user gets to see its score

        game.printField();                                          //user sees the field displyed

        game.moveRabbits();                                         //rabbits move arround the field

        game.moveCaptain();                                         //user is asked where does it wishes to move

        game.moveSnake();

        remaining_veggies = game.remainingVeggies();                //remaining veggies are calculated
    }

    game.gameOver();                                                //stats are displayed
    
    return 0;
}