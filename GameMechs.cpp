#include "GameMechs.h"
#include "MacUILib.h"
#include <iostream>

using namespace std;

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30; //default board size
    boardSizeY = 15;
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
    if(getInput() == 27)
    {
        exitFlag = true;
    }
    
}

void GameMechs::setLoseFlag()
{
    //only lose if die, not force exit
    loseFlag = true;
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
    getInput();
    if(input != 0) //or put into switch case, probs easier
    {
        if(input = '1')
        {
            score++;
        }
    }
    cout << "current score: " << score << endl;
    clearInput();
    
    
}


