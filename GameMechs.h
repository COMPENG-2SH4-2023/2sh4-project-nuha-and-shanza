#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib> //provides srand() and rand()
#include <time.h> //provides time()

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        
        int score;
        int boardSizeX;
        int boardSizeY;

        //heap data members
        int **myGM;


    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); //destructor

        bool getExitFlagStatus();
        void setExitTrue();

        bool getLoseFlagStatus();
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        int getScore();
        void incrementScore();
      
};


#endif