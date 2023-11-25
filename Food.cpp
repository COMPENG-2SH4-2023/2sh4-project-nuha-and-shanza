#include "Food.h"
#include "MacUILib.h"
#include <iostream>
#include "objPos.h"

using namespace std;

Food::Food()
{
    foodPos.setObjPos(-1, -1, 'o'); //initialize foodPos outside game board
    //^^dont display food
}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    //random food generation (PPA3)
    //blockOff contains player pos, NOT symbol

    //random x and y, not boarder and 0
    //isPosEqual() for comparing element by element


}

void getFoodPos(objPos &returnPos)
{
    //obtains current pos of food
    // returnPos = foodPos;
}