#include "Room.h"

#include <iostream>

#include "Utilities.h"

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

// This destructor bullshit is pissing me off.
// You can shove that error prompt up your ass.
//Room::~Room()
//{
//    delete myRoomName;
//    WriteLine("Cleaned up Room!");
//}

Room::Room(const char* aRoomName)
{
    this->myRoomName = aRoomName;
}

void Room::EnterRoom()
{
    std::cout << "Entered room: " << myRoomName << '\n';
}

const char* Room::GetRoomName() const
{
    return myRoomName;
}