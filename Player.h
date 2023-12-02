#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "Food.h"
#include "objPosArrayList.h"

class Player
{

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  //direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        
        objPosArrayList* getPlayerPos(); 
        void updatePlayerDir();
        void movePlayer(Food* myFood);  //accept reference to food object from project.cpp
        bool checkSelfCollision();
        

    private:
        
        //references to other classes 
        objPosArrayList *playerPosList;
        enum Dir myDir;

        GameMechs* mainGameMechsRef;

        Food* mainFoodRef; 

        
};

#endif