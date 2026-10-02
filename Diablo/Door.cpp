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
        std::cout << "[5] View inventory" << '\n';
        return;
    }
    
    if (!myRoom.IsRoomCleared())
    {
        myRoom.EnterCombat(aDiablo);
        return;
    }
    
    myRoom.DisplayRoom(aDiablo);
}

void Door::OpenDoor(Diablo& aDiablo, Room& aRoom)
{
    SetRoom(aRoom);
    OpenDoor(aDiablo);
}