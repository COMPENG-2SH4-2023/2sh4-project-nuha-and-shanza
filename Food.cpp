#include "Food.h"
#include "MacUILib.h"
#include <iostream>
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;

    foodPos.setObjPos(-1, -1, 'o'); //initialize foodPos outside game board
}

Food::~Food()
{
    delete[] myFood;
}

void Food::generateFood(objPosArrayList* blockOffList)
{
    // Seed the random integer generation function with current time.
    srand(time(NULL)); 
    int foodX, foodY;
    objPos tempPlayer;
    bool drawn;
    
    while(true)
    {
        drawn = false;
        //random coordinate generation
        foodX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
        foodY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1); 
    
        //if food is NOT on current player position, draw food on board
        for (int i = 0; i<blockOffList->getSize(); i++)
        {
            blockOffList->getElement(tempPlayer,i);
            if(foodX != tempPlayer.x && foodY != tempPlayer.y)
                {
                    foodPos.x = foodX;
                    foodPos.y = foodY;
                    drawn = true;
                    break;
                }

        }

       if (drawn)
        {
            break;  // Break out of the while loop when a suitable food position is found
        } 

    }

}
    

void Food::getFoodPos(objPos &returnPos)
{
    //obtains current position of food
    returnPos = foodPos;
}


void Food::updateFood()
{
    char input = mainGameMechsRef->getInput();

}