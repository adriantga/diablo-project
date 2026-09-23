#pragma once
#include <vector>

#include "Door.h"

class Room
{
    std::vector<Door> doors;
    
    // Minimum and maximum enemy count are both inside of the 'GameData' struct
    // This is to prevent silly bugs from occuring.
    
    int myEnemyCount = 0;
    
public:
    void OpenDoor(int doorIndex);
    
    // Spawns enemies and such
    void Enter();
};
