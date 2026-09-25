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

const char* Room::GetRoomName() const
{
    return myRoomName;
}