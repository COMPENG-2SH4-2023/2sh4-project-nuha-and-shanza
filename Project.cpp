#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
//global scope

GameMechs* myGM; //game mechanics pointer
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

    myGM = new GameMechs(20,10); //makes board size 20x10
    myPlayer = new Player(myGM); // initialize on heap
    myFood = new Food(myGM);

    objPos playerPos;
    objPos foodPos;
  
    myPlayer->getPlayerPos(playerPos); //get player position and store in temp Pos
    myFood -> generateFood(playerPos);
    

}

void GetInput(void)
{
    myGM->getInput();
    myFood->updateFood(); //press 'n' to update food 
}

void RunLogic(void)
{

    myGM -> incrementScore(); //press '1' 
    myGM -> setLoseFlag(); //press 'x' to lose game

    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();

    myGM -> clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); //get player position and store in temp Pos
    
    objPos tempFoodPos;
    myFood->getFoodPos(tempFoodPos);
    
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

           else if (i == tempPos.y && j == tempPos.x)
           {
                MacUILib_printf("%c", tempPos.getSymbol());
           }

           //for random food, not sure of correct 
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
    
    //score debug message
    MacUILib_printf("current score %d ", myGM->getScore());
    
    //loseflag debugger
    if(myGM->getLoseFlagStatus() == true) 
    {
        MacUILib_printf("\nyou lose");
    }

    //food pos debug message
     MacUILib_printf("\nfood pos: <%d, %d> + %c\n", tempFoodPos.x, tempFoodPos.y, tempFoodPos.symbol);
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
