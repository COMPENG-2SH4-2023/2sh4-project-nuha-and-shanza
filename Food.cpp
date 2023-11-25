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
    //random food generation (PPA3)
    //blockOff contains player pos


    //use isPosEqual() for comparing element by element
    //IDK HOW TO USE if(foodPos.isPosEqual(blockOff))
   
    foodPos.x = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
    foodPos.y = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1); 


}
    

void Food::getFoodPos(objPos &returnPos)
{
    //obtains current pos of food
    returnPos = foodPos;
}