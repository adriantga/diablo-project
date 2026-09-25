#include "Room.h"

#include <iostream>

#include "Door.h"
#include "Utilities.h"

Room::Room(bool myIsFirstRoom) : Room(myDoorCount = GetRandomNumber(myMinDoorCount = 2, myMaxDoorCount = 4), myIsFirstRoom)
{
}

Room::Room(int aDoorCount, bool myIsFirstRoom)
{
    this->myIsFirstRoom = myIsFirstRoom;
    this->myDoorCount = aDoorCount;
    
    if (myIsFirstRoom)
    {
        WriteLine("This is the first room");
    }
    
    aDoorCount = Min(aDoorCount, myMinDoorCount);
    for (int doorIndex = 0; doorIndex < aDoorCount; doorIndex++)
    {
        myDirection = GetDirection(doorIndex);
        
        if (!myIsFirstRoom && doorIndex == aDoorCount - 1)
        {
            myDirection = "Back";
        }
        
        Door door = Door();
        myDoors.push_back(&door);
        
        std::cout << "[" << (doorIndex + 1) << "] Go " << myDirection << '\n';
    }
    
    int input;
    ForceInput(input, 1, myDoorCount);
    OpenDoor(input - 1);
}

void Room::OpenDoor(int aDoorIndex)
{
    Door door = *myDoors[aDoorIndex];
    
    this->myCachedInput = aDoorIndex;
    if (aDoorIndex == myDoorCount - 1 && !myIsFirstRoom && door.GetPreviousRoom() != nullptr)
    {
        int doorCount = myDoors[aDoorIndex]->GetPreviousRoom()->GetDoorCount();
        std::cout << doorCount << '\n';
        return;
    }
    
    myDoors[aDoorIndex]->OpenDoor();
}