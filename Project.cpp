#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
//global scope

GameMechs* myGM; //game mechanics pointer
Player* myPlayer;


// objPos myPos;

// bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26,13); //makes board size 26x13
    myPlayer = new Player(myGM);

    // myPos.setObjPos(2,3,'@');

}

void GetInput(void)
{
    
}

void RunLogic(void)
{

    myPlayer -> updatePlayerDir();
    myGM -> setExitTrue();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); //get player position


    MacUILib_printf("board size: %dx%d, player pos: <%d, %d> + %c\n", myGM->getBoardSizeX(),myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);
    //draw border 
    for(int i = 0; i < myGM->getBoardSizeY(); i++) //look at each row, y coord
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++) //each column, x coord
        {
            if(j == 0 || j == (myGM->getBoardSizeX() - 1) || i == 0 || i == (myGM->getBoardSizeY() - 1))
            {
                MacUILib_printf("%s","#");
            }

            //print character on board (iteration 0) 
            // else if(i == myPos.y && j == myPos.x)
            // {
            //     MacUILib_printf("%c",myPos.symbol);
            // }

            else
            {
                MacUILib_printf("%s"," ");
            }
            
        }
        MacUILib_printf("%s","\n");
        
    }
    
    myGM->incrementScore(); //score debug message

    //from tutorial
    // MacUILib_printf("object: <%d, %d> with %c\n", myPos.x, myPos.y, myPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
