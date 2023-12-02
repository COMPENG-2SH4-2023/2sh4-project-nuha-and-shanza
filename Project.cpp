#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

//global scope
GameMechs* myGM; 
Player* myPlayer; 
Food* myFood;


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

    myGM = new GameMechs(26,13); //make board size 26,13
    myPlayer = new Player(myGM); // initialize on heap
    myFood = new Food(myGM);

    //call an instance of playerList from class Player
    objPosArrayList* playerList = myPlayer->getPlayerPos();
    myFood -> generateFood(playerList); 
    

}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer(myFood);

    myGM -> clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    bool drawn;

    objPos tempFoodPos;
    objPos printPlayer;
    objPos tempBody;

    myFood->getFoodPos(tempFoodPos);
    objPosArrayList* playerList = myPlayer->getPlayerPos();
    playerList->getHeadElement(printPlayer);
    
    
    // MacUILib_printf("board size: %dx%d, player pos: <%d, %d> + %c\n", myGM->getBoardSizeX(),myGM->getBoardSizeY(), printPlayer.x, printPlayer.y, printPlayer.symbol);
    
    MacUILib_printf("Welcome to Snake Game!\nPress ESC to exit\n");

    //draw border 
    for(int i = 0; i < myGM->getBoardSizeY(); i++) //look at each row, y coord
    {
        for(int j = 0; j < myGM->getBoardSizeX(); j++) //each column, x coord
        {
            drawn = false;

            for (int k = 0; k< playerList->getSize(); k++ ) //go through each element in playerlist
            {
                playerList->getElement(tempBody, k); //get element copy
                if (tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            //if player body drawn, do not draw anything below;
            if(drawn) continue;


            if(j == 0 || j == (myGM->getBoardSizeX() - 1) || i == 0 || i == (myGM->getBoardSizeY() - 1))
            {
                MacUILib_printf("%s","#");
            }

            else if(i == tempFoodPos.y && j == tempFoodPos.x)
            {
                MacUILib_printf("%c",tempFoodPos.getSymbol());
            }

            else
            {
                MacUILib_printf("%s"," ");
            }
            
        }
        MacUILib_printf("%s","\n");
        
    }
    
    //current score
    MacUILib_printf("Current Score: %d ", myGM->getScore());
    
    //game lost
    if(myGM->getLoseFlagStatus() == true) 
    {
        MacUILib_printf("\nOh No! Snake ran into itself\nYOU LOSE");
    }

    //exit game without losing
    if(myGM->getLoseFlagStatus() == false && myGM->getExitFlagStatus() == true) 
    {
        MacUILib_printf("\n(Forced Exit)\nGAME END");
    }

    //food pos debug message
    //  MacUILib_printf("\nfood pos: <%d, %d> + %c\n", tempFoodPos.x, tempFoodPos.y, tempFoodPos.symbol);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();  //uncomment if we want board deleted at end  
  
    MacUILib_uninit();

    //remove heap instances
    delete myGM;
    delete myPlayer;
    delete myFood;
}
