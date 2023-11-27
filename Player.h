#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "Food.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        //void getPlayerPos(objPos &returnPos); Upgrade this in iteration 3.
        objPosArrayList* getPlayerPos(); //upgraded previous statement
        void updatePlayerDir();
        void movePlayer(Food* myFood);  //accept reference to food object from project.cpp
        bool checkFoodConsumption();
        void increasePlayerLength();
        bool checkSelfCollision();
        
        //Lastly, add self collision check function
        //- if self collided 
        //set lose flag and exit flag to true (through GM)
        // this will break program loop and ened the game

        //if ending - you need to differentiate end game state
        //LOST - display lost message
        //otherwise, display ENDGAME message only


    private:
        //objPos playerPos; Upgrade this in iteration 3.       
        objPosArrayList *playerPosList; //upgraded previous statement
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        Food* mainFoodRef;

        
};

#endif