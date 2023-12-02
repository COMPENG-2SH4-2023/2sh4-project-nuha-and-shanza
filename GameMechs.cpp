#include "GameMechs.h"
#include "MacUILib.h"
#include <iostream>
#include "Player.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 26; 
    boardSizeY = 13;
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
    return score;
}


void GameMechs::setExitTrue()
{
    getInput();
    if(input == 27) //if escape key is pressed, exit game
    {
        exitFlag = true;
    }
    
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
    exitFlag = true;    

}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0; //clear most recent input
}

void GameMechs::incrementScore()
{
    score++;
}


