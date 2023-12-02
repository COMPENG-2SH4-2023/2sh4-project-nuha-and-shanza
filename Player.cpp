#include "Player.h"
#include "MacUILib.h"
#include "Food.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');

    //instantiate player list with size one 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    
}


Player::~Player()
{
    
   delete playerPosList; //We do not need [] since there is only one list. This calls on the destructor ~objPosArrayList 
   

}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos array list
    return playerPosList;

}


bool Player::checkSelfCollision()
{
    objPos tempHead;
    objPos tempBody;

    playerPosList->getHeadElement(tempHead);

    for(int i = 1; i < playerPosList->getSize(); i++) 
    {
        playerPosList->getElement(tempBody,i);
        //check if head collides with any part of snake body
        if(tempBody.x == tempHead.x && tempBody.y == tempHead.y)
        {
            return true;
        }
    }

    return false;

}


void Player::updatePlayerDir()
{ 
    char input = mainGameMechsRef->getInput();


    switch(input)
    {
        case 27 : //esc key to exit
        mainGameMechsRef->setExitTrue(); 
        break;

        case 'w' : 
            if (myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
            
        case 'a' : 
            if (myDir != RIGHT && myDir != LEFT)
                myDir = LEFT;
            break;

        case 's' :
            if (myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
           
                
        case 'd' : 
            if (myDir != RIGHT && myDir != LEFT)
                myDir = RIGHT;
            break;
            
         
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

    // Finite State Machine logic
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

