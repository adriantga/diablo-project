#pragma once
#include "Room.h"

class Door
{
    Room myRoom;
    bool isLocked = false;
    
    // Implement this 
    int myRequiredStrength = 0;
    int myRequiredAgility = 0;
    
public:
    Door(const Room& aRoom);
    Door(const Room& aRoom, bool aIsLocked, int aStrength, int aAgility);
    
    void OpenDoor(Diablo& aDiablo);
    
    const char* GetRoomName() const
    {
        return myRoom.GetName();
    }
};