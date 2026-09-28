#pragma once
#include <vector>
#include "Room.h"

class Room;

class Door
{
    std::vector<Room*> myConnections = {};
    void ShowConnections();
    
public:
    Door() = default;
    Door(std::vector<Room*> aConnections);
    void AddConnection(Room aRoom);
    void OpenDoor();
    void ClearConnections();
    
    void EnterRoom(int aIndex);
    
    int GetConnectionCount() const
    {
        return int(myConnections.size());
    }
    
    Room* GetConnection(int aIndex)
    {
        return myConnections.at(aIndex);
    }
};