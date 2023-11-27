#include "GameMechs.h"
#include "MacUILib.h"
#include <iostream>
#include "Player.h"



using namespace std;

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 20; //default board size  //change from 30x15
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX; 
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    delete[] myGM;
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    //from PPA 2
    if(MacUILib_hasChar() != 0) 
    {
        input = MacUILib_getChar();
        
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    //score stuff 
    return score;
}


void GameMechs::setExitTrue()
{
    getInput();
    if(input == 27)
    {
        exitFlag = true;
    }
    
}

void GameMechs::setLoseFlag()
{
    //only lose if die, not force exit
     //or put into switch case, probs easier

    loseFlag = true;
    exitFlag = true;    
    
    // if(input != 0) 
    // {
    //     if(input == 'x')
    //     {
    //         loseFlag = true;
    //         exitFlag = true;
    //     }
    // }


    
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0; //clear most recent input
    //call at end of player, maingamerref -> clearinput
}

void GameMechs::incrementScore()
{
    //i wasnt sure how to use length of playerPosList
    
    //score++ works but different than what manual says
    score++;
}


