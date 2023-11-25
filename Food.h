#ifndef FOOD_H
#define FOOD_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time()

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

using namespace std;


class Food
{
    private:
        objPos foodPos; //most recent food pos and ascii symbol
        
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
    
        int **myFood; //heap data members

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);

    
};


#endif