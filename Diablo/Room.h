#pragma once
#include <vector>

class Room
{
    const char* myRoomName = nullptr;
    std::vector<Room> myConnections = {};
    
public:
    // ---- Constructor x Destructor
    //~Room();
    Room(const char* aRoomName);
    void EnterRoom();
    
    const char* GetRoomName() const;
    
    std::vector<Room> GetConnections() const { return myConnections; }
};