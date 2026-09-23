#pragma once
#include <vector>

#include "Door.h"

class Room
{
    std::vector<Door> doors;
    
public:
    void OpenDoor(int doorIndex);
};
