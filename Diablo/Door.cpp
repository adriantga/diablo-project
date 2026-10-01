#include "Door.h"

#include <iostream>

#include "Utilities.h"

Door::Door(const Room& aRoom, const Diablo& aDiablo) : Door(aRoom, aDiablo, false, 0, 0)
{
    
}

Door::Door(const Room& aRoom, const Diablo& aDiablo, bool aIsLocked, int aStrength, int aAgility) : myRoom(aRoom.GetName(), aDiablo)
{
    myRoom = aRoom;
    myDiablo = aDiablo;
    myIsLocked = aIsLocked;
    myRequiredStrength = aStrength;
    myRequiredAgility = aAgility;
}

void Door::OpenDoor(Diablo& aDiablo)
{
    ClearScreen();
    if (myIsLocked)
    {
        std::cout << "The door is locked. What do you want to do?" << '\n';
        std::cout << "[1] Try to break the door" << '\n';
        std::cout << "[2] Try to pick the lock" << '\n';
        std::cout << "[3] Go back" << '\n';
        std::cout << "[4] View stats" << '\n';
        return;
    }
    
    if (!myRoom.IsRoomCleared())
    {
        myRoom.EnterCombat(aDiablo);
        return;
    }
    
    std::cout << "------------------------------------ " << myRoom.GetName() << " ------------------------------------" << '\n';
    
    for (int connection = 0; connection < myRoom.GetConnectionsCount(); connection++)
    {
        std::cout << "[" << connection + 1 << "] Enter " << myRoom.GetConnection(connection).GetName() << '\n';
    }
    std::cout << "[" << myRoom.GetConnectionsCount() + 1 << "] View stats" << '\n';
}
