#pragma once

#include "Door.h"

class Door;

class Room
{
    const char* myRoomName = nullptr;
    
    // Stop acting fucking stupid
    Door myDoor;
    
public:
    // ---- Constructor x Destructor
    //~Room();
    Room(const char* aRoomName);
    void EnterRoom();
    void SetDoor(Door& aDoor);
    
    const char* GetRoomName() const;
    
    // Genuine fucking buffoon
    Door GetDoor() const
    {
        return myDoor;
    }
};
