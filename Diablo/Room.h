#pragma once
#include <iostream>
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
    void SetConnections(std::vector<Room> aConnections);
    void ShowConnections();
    void AddConnection(Room aRoom);
    const char* GetRoomName() const;
    void AddConnections(std::vector<Room> aConnections);
    
    std::vector<Room> GetConnections() const { return myConnections; }
    
    int GetConnectionCount() const
    {
        return int(myConnections.size());
    }
    
    Room GetConnection(int aIndex)
    {
        std::cout << "Index: " << aIndex << '\n';
        std::cout << "Connection: " << myConnections.at(aIndex).GetRoomName() << '\n';
        return myConnections.at(aIndex);
    }
};
