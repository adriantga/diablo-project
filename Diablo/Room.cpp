#include "Room.h"

#include <iostream>

// ------------------------------- ENTRANCE THINGS -------------------------------
// Entrance leads to:
// - Cathedral
//
// Cathedral leads to:
// - Entrance
// - Armory
//
// --------------------------------- OTHER ROOMS ---------------------------------
// Armory lead to 
// - Cathedral
// - Kitchen
//
// Kitchen leads to
// - Cells
// - Armory
//
// Cells
// - Kitchen
// -------------------------------------------------------------------------------

Room::Room(const char* aRoomName) : Room(aRoomName, {})
{
}

Room::Room(const char* aRoomName, std::vector<Room> aConnections)
{
    this->myRoomName = aRoomName;
    this->myConnections = aConnections;
}

void Room::AddConnection(Room aRoom)
{
    myConnections.push_back(aRoom);
}

void Room::ShowConnections()
{
    for (int connection = 0; connection < myConnections.size(); connection++)
    {
        int displayedIndex = connection + 1;
        std::cout << "[" << displayedIndex << "] Enter " << myConnections[connection].GetRoomName() << '\n';
    }
}

void Room::SetConnections(std::vector<Room> aConnections)
{
    myConnections = aConnections;
}

void Room::AddConnections(std::vector<Room> aConnections)
{
    myConnections.insert(myConnections.end(), aConnections.begin(), aConnections.end());
}

const char* Room::GetRoomName() const
{
    return myRoomName;
}