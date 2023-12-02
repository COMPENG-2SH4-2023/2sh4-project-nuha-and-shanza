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
    // Seed the random integer generation function with current time
    srand(time(NULL)); 

    int foodX, foodY;
    objPos tempPlayer;
    bool setFood = false;
    
    while(setFood == false) //keep generating random coordinates
    {
        setFood = true;
        
        //random item generation
        foodX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
        foodY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1); 

        for (int i = 0; i<blockOffList->getSize(); i++)
        {
            blockOffList->getElement(tempPlayer,i); //get each element of player

            if(foodX == tempPlayer.x && foodY == tempPlayer.y)
            {
                //if food is generated anywhere on snake body, do not set it as food position
                setFood = false;
                break; //generate new coordinate for food
            }
         
        }
    }
    //food position set in randomly generated coordinate
    foodPos.x = foodX;
    foodPos.y = foodY;

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