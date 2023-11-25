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

void Food::generateFood(objPos blockOff)
{
    //use isPosEqual() for comparing element by element
    //IDK HOW TO USE if(foodPos.isPosEqual(blockOff))

    // Seed the random integer generation function with current time.
    srand(time(NULL)); 
    int foodX, foodY;

    while(true)
    {
        //random coordinate generation
        foodX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
        foodY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1); 
    
        //if food is NOT on playerpos
        if(foodX != blockOff.x && foodY != blockOff.y)
        {
            foodPos.x = foodX;
            foodPos.y = foodY;
            break;
        }

    }
   

}
    

void Food::getFoodPos(objPos &returnPos)
{
    //obtains current pos of food
    returnPos = foodPos;
}


void Food::updateFood()
{
    char input = mainGameMechsRef->getInput();

    if(input == 'n')
    {
        generateFood(foodPos);
    }

}