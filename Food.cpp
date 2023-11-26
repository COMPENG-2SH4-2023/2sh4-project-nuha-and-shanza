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

void Food::generateFood(objPosArrayList* blockOffList) //Iteration 3
//void Food::generateFood(objPos blockOff)
{
    //use isPosEqual() for comparing element by element
    //IDK HOW TO USE if(foodPos.isPosEqual(blockOff))

    // Seed the random integer generation function with current time.
    

    srand(time(NULL)); 
    int foodX, foodY;
    objPos tempPlayer;
    bool drawn;
/*
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
*/

    //TODO:
        //update generate food
        //need to accept the player body array list
        //go through each array list element to ensure 
        //they are all blocked off from random food genetaion
        //(so a list of blocked off)
        //o	When generating food, iterate through every single objPos element in the playerPosList, and make sure the position of the new food doesn’t
        // overlap with any of the elements.
        
 
    
    while(true)
    {
        drawn = false;
        //random coordinate generation
        foodX = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
        foodY = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1); 
    
        //if food is NOT on playerpos
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
    //obtains current pos of food
    returnPos = foodPos;
}


//debugging 
void Food::updateFood()
{
    char input = mainGameMechsRef->getInput();

/* 
    if(input == 'n')
    {
        generateFood(foodPos);
        

    }
*/

}