#pragma once
#include "Room.h"

class Door
{
    Room myRoom;
    bool myIsLocked = false;
    
    // Implement this 
    int myRequiredStrength = 0;
    int myRequiredAgility = 0;
    
    Diablo myDiablo = {};
    
public:
    Door(const Room& aRoom, const Diablo& aDiablo);
    Door(const Room& aRoom, const Diablo& aDiablo, bool aIsLocked, int aStrength, int aAgility);
    int GetRequiredStrength() const { return myRequiredStrength; }
    int GetRequiredAgility() const { return myRequiredAgility; }
    Diablo GetGame() const { return myDiablo; }
    
    void OpenDoor(Diablo& aDiablo);
    
    bool IsLocked() const
    {
        return myIsLocked;
    }
    
    void SetLocked(bool aIsLocked, int aStrength = 0, int aAgility = 0)
    {
        myIsLocked = aIsLocked;
        myRequiredAgility = aAgility;
        myRequiredStrength = aStrength;
    }
    
    const char* GetRoomName() const
    {
        return myRoom.GetName();
    }
    
    Room& GetRoom()
    {
        return myRoom;
    }
    
    const Room& GetRoom() const
    {
        return myRoom;
    }
    
    void SetRoom(const Room& aRoom)
    {
        myRoom = aRoom;
    }
};