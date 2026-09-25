#include "Door.h"

#include "Utilities.h"

void Door::SetPreviousRoom(Room* aRoom)
{
    myPreviousRoom = aRoom;
}

void Door::OpenDoor()
{
    WriteLine("Door has been opened!");
    Room();
}