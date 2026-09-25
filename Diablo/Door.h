#pragma once
#include "Room.h"

class Door
{
    Room *myPreviousRoom = nullptr;
    
public:
    void SetPreviousRoom(Room* aRoom);
    void OpenDoor();
};