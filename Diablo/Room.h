#pragma once
#include <vector>

class Room
{
    const char* myRoomName = nullptr;
    std::vector<Room> myConnections = {};
    
public:
    // ---- Constructors x Destructor
    Room(const char* aRoomName);
    Room(const char* aRoomName, std::vector<Room> aConnections);
    
    // ---- Methods
    void AddConnection(Room aRoom);
    const char* GetRoomName() const;
};
