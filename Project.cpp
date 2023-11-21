#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

objPos myPos;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    myPos.setObjPos(2,3,'@');

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    //draw border 
       for(int i = 0; i < 10; i++) //look at each row, y coord
    {
        for(int j = 0; j < 20; j++) //each column, x coord
        {
            if(j == 0 || j == 19 || i == 0 || i == 9)
            {
                MacUILib_printf("%s","#");
            }

            //print character on board (iteration 0) 
            else if(i == myPos.y && j == myPos.x)
            {
                MacUILib_printf("%c",myPos.symbol);
            }

            else
            {
                MacUILib_printf("%s"," ");
            }
            
        }
        MacUILib_printf("%s","\n");
    }

    //from tutorial
    MacUILib_printf("object: <%d, %d> with %c\n", myPos.x, myPos.y, myPos.symbol);
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
