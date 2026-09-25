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
        if (door.GetPreviousRoom() == nullptr) door.SetPreviousRoom(this);
        
        std::cout << "[" << (doorIndex + 1) << "] Go " << myDirection << '\n';
    }
    
    int input;
    ForceInput(input, 1, myDoorCount);
    OpenDoor(input - 1);
}


void Room::OpenDoor(int aDoorIndex)
{
    std::cout << aDoorIndex << '\n';
    
    if (aDoorIndex == myDoorCount - 1 && !myIsFirstRoom)
    {
        WriteLine("Went back!");
        Room(myDoors[aDoorIndex]->GetPreviousRoom()->GetDoorCount());
        return;
    }
    
    this->myCachedInput = aDoorIndex;
    myDoors[aDoorIndex]->OpenDoor();
}
