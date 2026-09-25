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
        
        bool hasOpposite = !myIsFirstRoom && myPreviousInput != -1;
        
        Door door = Door();
        myDoors.push_back(&door);
        door.SetPreviousRoom(this);
        
        std::cout << "[" << (doorIndex + 1) << "] Go " << myDirection << (hasOpposite ? "(go back)" : "") << '\n';
    }
}

bool Room::IsOppositeDirection(int i) const
{
    int result = 0;
    
    switch (i)
    {
    case 0: // N
        result = 2;
        break;
    case 1: // E
        result = 3;
        break;
    case 2: // S
        result = 0;
        break;
    case 3: // W
        result = 1;
        break;
    }
    
    return result;
}

void Room::OpenDoor(int aDoorIndex)
{
    this->myCachedInput = aDoorIndex;
    myDoors[aDoorIndex]->OpenDoor();
}
