#include "Player.h"
#include "MacUILib.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    //playerPos.setObjPos(3,3,'*');
    
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');

    //instantiate player list with size one 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    
}


Player::~Player()
{
    // delete any heap members here
   delete playerPosList; //We do not need [] since there is only one list. This calls on the destructor ~objPosArrayList 
   

}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos 
    //arrray list
    return playerPosList;

}

//This function was not used we can delete 
bool Player::checkFoodConsumption()
{
    objPos tempFood;
    mainFoodRef->getFoodPos(tempFood);

    objPos tempHead;
    playerPosList->getHeadElement(tempHead);

    MacUILib_printf("\nFood at %d %d\n", tempFood.x , tempFood.y);

    if (tempFood.x == tempHead.x && tempFood.y == tempHead.y )  
        return true;
    else return false;

}

//This function was also not used we can delete 
void Player::increasePlayerLength()
{
    objPos tempHead;
    playerPosList->getHeadElement(tempHead);
    playerPosList->insertHead(tempHead);

}

bool Player::checkSelfCollision()
{
    objPos tempHead;
    playerPosList->getHeadElement(tempHead);

    objPos tempBody;
    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempBody,i);
        if(tempBody.x == tempHead.x && tempBody.y == tempHead.y)
        {
            return true;
        }
    }

    return false;

}


void Player::updatePlayerDir()
{
    // PPA3 input processing logic     
    char input = mainGameMechsRef->getInput();

    //case switch to set myDir
    switch(input)
    {
        case ' ': //space bar to exit
            mainGameMechsRef->setExitTrue();
            break;

            case 27 : //esc key to exit
            mainGameMechsRef->setExitTrue(); 
            break;

        // w=119up a=97left s=115down d=100right
        case 'w' : //w,119
            if (myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
            
          

        case 'a' : //a, 97
            if (myDir != RIGHT && myDir != LEFT)
                myDir = LEFT;
            break;
            

        case 's' : //s,115
            if (myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
           
                
        case 'd' : //d,100
            if (myDir != RIGHT && myDir != LEFT)
                myDir = RIGHT;
            break;
            
          

        // Add more key processing here    
        default:
            break;
        
    }

    //clear input buffer
    mainGameMechsRef->clearInput();
}

void Player::movePlayer(Food* myFood) //accept reference to food object from Project.cpp
{
    
    objPos current; //holding position info of current head
    playerPosList->getHeadElement(current);

    objPos foodPos; //current food object
    myFood->getFoodPos(foodPos);

    // PPA3 Finite State Machine logic
    if (myDir == LEFT){ 
        current.x -= 1;
        //wrap around
        if (current.x < 1){
            current.x = mainGameMechsRef->getBoardSizeX()-2;
        }
    }

    else if (myDir == RIGHT){
        current.x +=1;
        if (current.x > mainGameMechsRef->getBoardSizeX()-2){
            current.x =1;
        }
    }
    else if (myDir == UP){
        current.y -= 1;
        if (current.y < 1){
            current.y = mainGameMechsRef->getBoardSizeY()-2;
        }
    }
    else if (myDir == DOWN){
        current.y += 1;
        if (current.y > mainGameMechsRef->getBoardSizeY()-2){
            current.y = 1;
        }
    
    }


    //suicide detection
    // objPos tempBody;

    // for(int i = 0; i < playerPosList->getSize(); i++)
    // {   
    //     playerPosList->getElement(tempBody,i+2);
    //     if(current.x == tempBody.x && current.y == tempBody.y);
    //         {
    //             mainGameMechsRef->setLoseFlag();
    //         }
    // }

    if (checkSelfCollision() == true)
    {
        mainGameMechsRef->setLoseFlag();
    }

    
    if (foodPos.x == current.x && foodPos.y == current.y) //if collided add head, increase score, generate new food 
    {
        playerPosList->insertHead(current);
        mainGameMechsRef->incrementScore();
        myFood->generateFood(playerPosList); 
        
    }
    else 
    {
        playerPosList->insertHead(current); //if not collided, add head and remove tail
        playerPosList->removeTail();
    } 
    

}

