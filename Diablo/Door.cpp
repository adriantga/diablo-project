#include "Door.h"

#include <iostream>

Door::Door(const Room& aRoom) : Door(aRoom, false, 0, 0)
{
    
}

Door::Door(const Room& aRoom, bool aIsLocked, int aStrength, int aAgility) : myRoom(aRoom.GetName())
{
    myRoom = aRoom;
    isLocked = aIsLocked;
    myRequiredStrength = aStrength;
    myRequiredAgility = aAgility;
}

void Door::OpenDoor(Diablo& aDiablo)
{
    if (isLocked)
    {
        std::cout << "The door is locked." << '\n';
        return;
    }
    
    std::cout << "------------------------------------ " << myRoom.GetName() << " ------------------------------------" << '\n';
    
    if (!myRoom.IsRoomCleared())
    {
        myRoom.EnterCombat(aDiablo);
        return;
    }
    
    for (int connection = 0; connection < myRoom.GetConnectionsCount(); connection++)
    {
        std::cout << "[" << connection + 1 << "] Enter " << myRoom.GetConnection(connection).GetName() << '\n';
    }
}
