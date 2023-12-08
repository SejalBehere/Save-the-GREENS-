#include "GameEngine.h"

void GameEngine::initializeGame()
{
    score = 0;
    initVeggies();
    initCaptain();
    initRabbits();
    initSnake();
}

void GameEngine::initVeggies()
{

/************************************************************************
 * Asking user for the file
 ************************************************************************/

string fileName;
cout << "Please enter the name of the vegetable point file: ";
cin >> fileName;

ifstream inStream(fileName);

   while (!inStream.is_open())
   {
       cout << fileName <<" does not exist! Please enter the name of the vegetable point file: ";
       cin >> fileName;

       inStream.open(fileName);
   }   

/*****************************************************************************************************
 * Store in the appropriate info - height and width of the field and geggie objects
 *****************************************************************************************************/
    int linenum=0, count = 0, numveggies = 0;
    string line, subline="empty";

    const int NUMBEROFVEGGIES =30;
    string veggieName, veggieChar; 
    int veggiePoint;

    while (!inStream.eof())  
    {
        linenum++;

        getline(inStream, line, '\n');

        stringstream inLine(line);

        getline(inLine,subline,',');

        if(linenum != 1)
            veggieName = subline;

        getline(inLine,subline,',');

        if(linenum == 1)
        {
            height = stoi(subline);
        }
        else
            veggieChar = subline;

        getline(inLine,subline,',');

        if(linenum == 1)
        {
            width = stoi(subline);

            //defining the 2D field inhabitant pointer after getting the height anf the wifth of the farm
            field = new FieldInhabitant**[height];
            for(int i=0; i<height; i++)
            {
                field[i] = new FieldInhabitant*[width];
                for(int j =0; j<width; j++)
                {
                    field[i][j] = nullptr;
                }
            }
        }
        else 
            veggiePoint = stoi(subline);

        if(linenum!=1)
        {
            Veggie* newVegitable = new Veggie (veggieName, veggieChar, veggiePoint);
            veggie_pointer.push_back(newVegitable);
        }
        
    }
    /*****************************************************************************************************
    * Randomly add veggies to the field
    *****************************************************************************************************/
    int veggie_num;
    int h, w;
    
    for(int i=0; i<NUMBEROFVEGGIES; i++)
    {
        veggie_num = rand()%veggie_pointer.size();
        do{
        h = rand()%height;
        w = rand()%width;
        } while(field[h][w]!=nullptr);

        field[h][w] = new Veggie (veggie_pointer[veggie_num]->getVeggieName(), veggie_pointer[veggie_num]->getInhabitant_symbol(), veggie_pointer[veggie_num]->getVeggiePoint());
    }

    inStream.close();
}

void GameEngine::initCaptain()
{
/*****************************************************************************************************
 * Add captain to the field
*****************************************************************************************************/
     int cap_x,cap_y;

    do{
        cap_y = rand()%height;
        cap_x = rand()%width;
      } while(field[cap_y][cap_x]!=nullptr);

    captain_pointer = new Captain(cap_x, cap_y);
    field[cap_y][cap_x] = captain_pointer;
}

void GameEngine::initRabbits()
{
/*****************************************************************************************************
 * Adding all 5 rabbits to the field
*****************************************************************************************************/
    int rabbit_x,rabbit_y;

    for(int i=0 ; i<NUMBEROFRABBITS; i++)
    {
        do{
            rabbit_y = rand()%height;
            rabbit_x = rand()%width;
        } while(field[rabbit_y][rabbit_x]!=nullptr);

        Rabbit* newRabbit = new Rabbit (rabbit_x, rabbit_y);
        rabbit_pointer.push_back(newRabbit);

        field[rabbit_y][rabbit_x] = rabbit_pointer[i];
    }

}

void GameEngine::initSnake()
{
    int x_snake, y_snake;
    do
    {
        y_snake = rand()%height;
        x_snake = rand()%width;
    } while(field[y_snake][x_snake]!=nullptr);

    snake_pointer = new Snake(x_snake, y_snake);
    field[y_snake][x_snake] = snake_pointer;
}

int GameEngine::remainingVeggies()
{
    int remainingveggie =0;
    for(int h=0; h<height; h++)
    {
        for(int w=0; w<width; w++)
        {
            if(Veggie* temp = dynamic_cast<Veggie*>(field[h][w]))
                remainingveggie++;
        }
    }
    return remainingveggie;
}

void GameEngine::intro()
{
    cout << "Welcome to Save the GREENS!!!" << endl;
    cout << "\nThe rabbits have invaded your garden and you must harvest as many vegetables as possible before the rabbits eat them all!"
         << "Each vegetable is worth a different number of points so go for the high score!" << endl;
    cout << "\nTo move the captain please enter the letter representing the direction you want the the captain to move in" << endl;
    cout << "To move the captain one slot up enter W/w" <<endl;
    cout << "To move the captain one slot down enter S/s" << endl;
    cout << "To move the captian one slot to the left enter A/a" << endl;
    cout << "To move the captain one slot to the right enter D/d" << endl;
    cout << "\nOnce the field is empty of all the veggies the game will end\n" << endl;
   
    cout << "List of possible veggies in the field" << endl;
    for (int i = 0; i < veggie_pointer.size(); i++) 
    {
        cout << veggie_pointer[i]->getInhabitant_symbol() << ": "<< veggie_pointer[i]->getVeggieName() 
        << ", " <<  veggie_pointer[i]->getVeggiePoint() << " points"<< endl;
    }
    cout << "\nCaptain Veggie is V, and the rabbits are R's." << endl;
    cout << "\nLet's start the game and help the good captain out. \n\nGood Luck!" << endl;
}

void GameEngine::printField()
{
    for (int i = 0; i < width+1; ++i) //Top border
        {cout << "##";}

    cout << endl;

    for (int i = 0; i < height; i++) 
    {
        cout << "#";  // Left border
        for (int j = 0; j < width; j++) 
        {
            if (field[i][j] != nullptr) 
                cout << field[i][j]->getInhabitant_symbol() << " ";  //Print the symbol of the veggie occupying the space
            else 
                cout << "  ";  //Print empty if there is no veggie in that space
        }
        cout << "#" << endl;  // Right border
    }

    for (int i = 0; i < width+1; i++) // Bottom border
        {cout << "##";} 

    cout << endl;
}

int GameEngine::getScore()
{
    //TODO return the players current score
    score = 0;

    vector<Veggie*> collected_vegg = captain_pointer->getCollected_Veggies();
    int size = collected_vegg.size();
    //cout << "\nnum of veggies in the basket: "<<size << endl;
    for(int i=0; i<size; i++)
    {
        score += collected_vegg[i]->getVeggiePoint();
    }

    collected_vegg.clear();

    return score;
}

void GameEngine::moveRabbits()
{
/*****************************************************************************************************
 * Moving all 5 rabbits and checking its boundary conditions
 *****************************************************************************************************/
    for(int i=0; i <NUMBEROFRABBITS; i++ )
    {
        int random_dir = rand()%8;

        Rabbit* rabbit = rabbit_pointer[i];
        int R_xold = rabbit_pointer[i]->getR_xCoord();
        int R_yold = rabbit_pointer[i]->getR_yCoord();
        int R_xnew = R_xold, R_ynew = R_yold;

        switch (random_dir) 
        {
            case 0:  // Down
                if (R_yold + 1 < height)
                    R_ynew = R_yold +1;
                break;

            case 1:  // down right diagonal
                if (R_xold + 1 < width && R_yold + 1 < height)
                {
                    R_ynew = R_yold + 1;
                    R_xnew = R_xold +1;
                }
                break;

            case 2:  // Right
                if (R_xold + 1 < width)
                    R_xnew = R_xold + 1 ;
                break;

            case 3:  // Up-right diagonal
                if (R_yold - 1 >= 0 && R_xold + 1 < width)
                {
                    R_ynew = R_yold - 1,
                    R_xnew = R_xold + 1;
                }
                break;

            case 4:  // Up
                if (R_yold -1 >= 0)
                    R_ynew= R_yold - 1;
                break;

            case 5:  // Up-left diagonal
                if (R_yold - 1 >= 0 && R_xold - 1 >=0)
                {
                    R_ynew = R_yold - 1;
                    R_xnew = R_xold - 1;
                }
                break;

            case 6:  // Left
                if (R_xold - 1 >= 0)
                    R_xnew = R_xold - 1;
                break;

            case 7:  // Down-left
                if(R_yold + 1 < height && R_xold - 1 >=0)
                {
                    R_ynew = R_yold + 1;
                    R_xnew = R_xold - 1;
                }
                break;
            
        }
        if (field[R_ynew][R_xnew] != nullptr) 
        {
            // Check if the new position is occupied by the Captain
            if(Captain* temp1 = dynamic_cast<Captain*>(field[R_ynew][R_xnew]))
            {
                // if captain is present at the new location then do not update the rabbit position
            }
            // Check if the new position is occupied by another rabbit
            else if(Rabbit* temp = dynamic_cast<Rabbit*>(field[R_ynew][R_xnew]))
            {
                // if another is present at the new location then do not update the rabbit position
            }

            //Check if the new position is occupied by a Veggie
            else if (Veggie* veggie = dynamic_cast<Veggie*>(field[R_ynew][R_xnew])) 
            {
                // The new position is occupied by a Veggie
                // Remove the Veggie from the field and add the Rabbit in its place
                field[R_ynew][R_xnew] = nullptr;
                rabbit_pointer[i]->setRCoord(R_xnew, R_ynew);       // Update the Rabbit's position
                field[R_ynew][R_xnew] = rabbit_pointer[i] ;         // Update the field
                field[R_yold][R_xold] = nullptr;                    // remove the rabbits previous position from the field.
            } 
        }
        else if (field[R_ynew][R_xnew] == nullptr)
        {
            // update the previous rabbit position to nullptr and move the Rabbit to the new position
            rabbit_pointer[i]->setRCoord(R_xnew, R_ynew);
            field[R_ynew][R_xnew] = rabbit_pointer[i];
            field[R_yold][R_xold] = nullptr;
        }
            
    }
}

void GameEngine::moveSnake()
{
    int snake_xold = snake_pointer->getS_xCoord();
    int snake_yold = snake_pointer->getS_yCoord();
    int snake_xnew = snake_xold;
    int snake_ynew = snake_yold;

    // Get the position of the captain
    int captain_x = captain_pointer->getcaptain_x();
    int captain_y = captain_pointer->getcaptain_y();

    //Calculate the distance between the position of the captain and the snake
    int horizontal_distance = captain_x - snake_pointer->getS_xCoord();
    int vertical_distance = captain_y - snake_pointer->getS_yCoord();
    
    if (abs(horizontal_distance) > abs(vertical_distance))
    {
        if (horizontal_distance > 0)
        {
            // Move right
            snake_xnew = snake_xold + 1;
            snake_ynew = snake_yold;
        }
        else
        {
            // Move left
            snake_xnew = snake_xold - 1;
            snake_ynew = snake_yold;
        }
    }
    else if(abs(horizontal_distance) < abs(vertical_distance))
    {
        // Move vertically
        if (vertical_distance > 0)
        {
            // Move down
            snake_ynew = snake_yold + 1;
            snake_xnew = snake_xold;
        }
        else
        {
            // Move up
            snake_ynew = snake_yold - 1;
            snake_xnew = snake_xold;
        }
    }
    else
    {
        snake_xnew = snake_xold;
        snake_ynew = snake_yold; 
    }
    //cout << "ifelse completed"<< snake_ynew << " " <<snake_xnew<<endl;

    if(snake_xnew >= 0 && snake_xnew < width && snake_ynew >= 0 && snake_ynew < height)
    {
        if(field[snake_ynew][snake_xnew] == nullptr)
        {
            snake_pointer->setSCoord(snake_xnew, snake_ynew);      // Update Snake's position
            field[snake_yold][snake_xold] = nullptr;               // set the old field posiiton to null
            field[snake_ynew][snake_xnew] = snake_pointer;         // update the snake position in field
        }

        //Check if the new position is empty
        else if (field[snake_ynew][snake_xnew] != nullptr)
        {
            if (Captain* captain = dynamic_cast<Captain*>(field[snake_ynew][snake_xnew]))
            {
                vector<Veggie*> collected_vegg = captain_pointer->getCollected_Veggies();

                // Calculate the total points from the last 5 veggies
                int point_remove = 0;
                if(collected_vegg.size()<5)
                {
                    captain_pointer->setCollected_Veggies(1);
                }
                else
                {
                    captain_pointer->setCollected_Veggies(0);
                }
                cout << "Oops, you ran into a snake and lost veggies!" << endl;
                field[snake_yold][snake_xold] = nullptr;
                initSnake();
            } 
        }
        
    }
    
}

void GameEngine::moveCptVertical(int user_ip)
{
    int cap_xold, cap_xnew, cap_yold, cap_ynew;
    cap_xold= captain_pointer->getcaptain_x();
    cap_xnew = cap_xold;
    cap_yold = captain_pointer->getcaptain_y();
    cap_ynew = captain_pointer->getcaptain_y() + user_ip;

    // Check if the new position is empty
    if (field[cap_ynew][cap_xnew] == nullptr) 
        {
            captain_pointer->setcaptain_coord(cap_xnew, cap_ynew);      // Update Captain's position
            field[cap_yold][cap_xold] = nullptr;                        // set the old field posiiton to null
            field[cap_ynew][cap_xnew] = captain_pointer;                // update the captains position in field
        } 
    // Check if the posiition is occupied by a veggie
    else if (Veggie* veggie = dynamic_cast<Veggie*>(field[cap_ynew][cap_xnew])) 
        {
            // Add the veggie to captain's basket
            captain_pointer->addVeggie(veggie);
            cout << "Yummy! A delicious " << veggie->getVeggieName() << endl;

            // Update score
            vector<Veggie*> collected_vegg = captain_pointer->getCollected_Veggies();
            score += collected_vegg.back()->getVeggiePoint();
            cout << "Current score: " << score << endl;

            captain_pointer->setcaptain_coord(cap_xnew, cap_ynew);      // Update Captain's position
            field[cap_yold][cap_xold] = nullptr;                        // set the old field position to null
            field[cap_ynew][cap_xnew] = captain_pointer;                // update the captains position in field
        } 
    // Check if the posiition is occupied by a veggie   
    else if (Rabbit* rabbit = dynamic_cast<Rabbit*>(field[cap_ynew][cap_xnew])) 
        {
            // Captain encountered a rabbit
            cout << "Don't step on the bunnies!" << endl;
        } 
}

void GameEngine::moveCptHorizontal(int user_ip)
{
    int cap_xold, cap_xnew, cap_yold, cap_ynew;
    cap_xold = captain_pointer->getcaptain_x();
    cap_xnew = captain_pointer->getcaptain_x() + user_ip;
    cap_yold = captain_pointer->getcaptain_y();
    cap_ynew = cap_yold;

    // Check if the new position is empty
    if (field[cap_ynew][cap_xnew] == nullptr) 
    {
        captain_pointer->setcaptain_coord(cap_xnew, cap_ynew);      // Update Captain's position
        field[cap_yold][cap_xold] = nullptr;                        // set the old field posiiton to null
        field[cap_ynew][cap_xnew] = captain_pointer;                // update the captains position in field
    } 
    // Check if the posiition is occupied by a veggie
    else if (Veggie* veggie = dynamic_cast<Veggie*>(field[cap_ynew][cap_xnew])) 
    {
        // Add the veggie to captain's basket
        captain_pointer->addVeggie(veggie);
        cout << "Yummy! A delicious " << veggie->getVeggieName() << endl;

        // Update score
        vector<Veggie*> collected_vegg = captain_pointer->getCollected_Veggies();
        score += collected_vegg.back()->getVeggiePoint();
        cout << "Current score: " << score << endl;

        captain_pointer->setcaptain_coord(cap_xnew, cap_ynew);      // Update Captain's position
        field[cap_yold][cap_xold] = nullptr;                        // set the old field position to null
        field[cap_ynew][cap_xnew] = captain_pointer;                // update the captains position in field
    } 
    // Check if the posiition is occupied by a veggie   
    else if (Rabbit* rabbit = dynamic_cast<Rabbit*>(field[cap_ynew][cap_xnew])) 
    {
        // Captain encountered a rabbit
        cout << "Don't step on the bunnies!" << endl;
    }
    
}

void GameEngine::moveCaptain()
{
    string user_dir;
    char direction;

    cout<<"Enter direction (W, A, S, D): ";//The captain can move using these keys
    cin >> user_dir;

    direction = user_dir[0];

    switch (direction)//Switch case to change position according to user input
    {   
        case 'W':
        case 'w':
            if(captain_pointer->getcaptain_y()-1 >= 0)
            {   moveCptVertical(-1);       //captain moves up
            }
            else
                cout << "You can't move that way!" << endl;
            break;
        case 'S':
        case 's':
            if(captain_pointer->getcaptain_y()+1 < height)
            {   moveCptVertical(1);       //captain moves down
            }
            else
                cout << "You can't move that way!" << endl;
            break;
        case 'A':
        case 'a':
            if(captain_pointer->getcaptain_x()-1 >= 0)
            {   moveCptHorizontal(-1);    //captain moves left
            }
            else
                cout << "You can't move that way!" << endl;
            break;
        case 'D':
        case 'd':
            if(captain_pointer->getcaptain_x()+1 < width)
            { moveCptHorizontal(1);   //captain moves right
            }
            else
                cout << "You can't move that way!" << endl;
            break;
        default:
            cout << user_dir << " is not a valid option." << endl;         
    }
}

void GameEngine::gameOver()
{
    cout << "Game Over!\nYou managed to harvest the following vegetables:" << endl;

    vector<Veggie*> collected_vegg = captain_pointer->getCollected_Veggies();   //recieve the collected veggies
    int size = collected_vegg.size();

    for(int i=0; i<size; i++)
    {
        cout << collected_vegg[i]->getVeggieName() << endl;                     //print the name of all the collected veggies
    }

    cout << "Your score was: " << score;                                        //print the score
}

