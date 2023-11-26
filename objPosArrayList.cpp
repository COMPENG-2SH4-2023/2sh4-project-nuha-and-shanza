#include "objPosArrayList.h"

#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

//NOTE:
//DELETE the IF statements for debugging later. Currently they are commented. -Nuha

objPosArrayList::objPosArrayList()
{
    sizeList = 0;  
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos [ARRAY_MAX_CAP]; //alist is array on heap


}

objPosArrayList::~objPosArrayList()
{
    delete [] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    /*
    if(sizeList == sizeArray)
    {
        cout << "[WARNING] List is Full, No Insertion Allowed." << endl;
        return;
    }
    */


    for(int i = sizeList; i > 0; i--)   
        aList[i] = aList[i - 1];  // shuffling towards the tail

    aList[0] = thisPos;
    sizeList++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    /*
    if(sizeList == sizeArray)
    {
        cout << "[WARNING] List is Full, No Insertion Allowed." << endl;
        return;
    }
    */

    aList[sizeList++] = thisPos;

}

void objPosArrayList::removeHead()
{
    /*
    if(sizeList == 0)
    {
        cout << "[WARNING] List is Empty, No Removal Allowed" << endl;
        return;
    }
    */

    for(int i = 0; i < sizeList - 1; i++)   
        aList[i] = aList[i + 1];  // shuffling towards the head

    sizeList--;   
}

void objPosArrayList::removeTail()
{
    /*
    if(sizeList == 0)
    {
        cout << "[WARNING] List is Empty, No Removal Allowed" << endl;
        return;
    }
    */

    sizeList--;  // lazy delete
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    /*
    if(sizeList == 0)
    {
        cout << "[WARNING] List is Empty, Cannot Search for Elements." << endl;
        return;
    }
    */
    
    returnPos = aList[0];

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    /*
    if(sizeList == 0)
    {
        cout << "[WARNING] List is Empty, Cannot Search for Elements." << endl;
        return;
    }
    */
    returnPos = aList[sizeList - 1];

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    /*
    if(sizeList == 0 || index < 0 || index >= sizeList)
    {
        cout << "[WARNING] Index Out of Bound, No Element Retrieval Allowed." << endl;
        return;
    }
    */
    returnPos = aList[index];

}
