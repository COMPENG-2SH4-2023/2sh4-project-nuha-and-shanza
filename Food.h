#ifndef FOOD_H
#define FOOD_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time()

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class Food
{
    private:
        objPos foodPos; //most recent food pos and ascii symbol

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);

};


#endif