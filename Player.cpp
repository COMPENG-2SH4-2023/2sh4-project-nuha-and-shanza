#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(3,3,'*');
}


Player::~Player()
{
    // delete any heap members here
   //TO DO :
   // ASK TA how to deallocate memory from objPos and Player


}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos 
    //arrray list
    returnPos = playerPos;

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
            if (myDir != UP && myDir != DOWN){
                myDir = UP;
                break;
            }
            else myDir = myDir;
            break;

        case 'a' : //a, 97
            if (myDir != RIGHT && myDir != LEFT){
                myDir = LEFT;
                break;
            }
            else myDir = myDir;
            break;

        case 's' : //s,115
            if (myDir != UP && myDir != DOWN){
                myDir = DOWN;
                break;
            }
            else myDir = myDir;
            break;
                
        case 'd' : //d,100
            if (myDir != RIGHT && myDir != LEFT){
                myDir = RIGHT;
                break;
            } 
            else myDir = myDir;
            break;    
              

        // Add more key processing here    
        default:
            break;
        
    }
    //clear input buffer
    mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if (myDir == LEFT){      
        playerPos.x -= 1;
        //wrap around
        if (playerPos.x < 1){
            playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
        }
    }

    else if (myDir == RIGHT){
        playerPos.x +=1;
        if (playerPos.x > mainGameMechsRef->getBoardSizeX()-2){
            playerPos.x =1;
        }
    }
    else if (myDir == UP){
        playerPos.y -= 1;
        if (playerPos.y < 1){
            playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
        }
    }
    else if (myDir == DOWN){
        playerPos.y += 1;
        if (playerPos.y > mainGameMechsRef->getBoardSizeY()-2){
            playerPos.y = 1;
        }
    
    }

    
}

