#include "Door.h"

#include <iostream>
#include <vector>

Door::Door(std::vector<Room> aConnections)
{
    myConnections = aConnections;
}

void Door::AddConnection(Room aRoom)
{
    myConnections.push_back(aRoom);
}

void Door::OpenDoor()
{
    ShowConnections();
}

void Door::ClearConnections()
{
    myConnections.clear();
}

void Door::EnterRoom(int aIndex)
{
    Room room = GetConnection(aIndex);
    room.EnterRoom();
}

void Door::ShowConnections()
{
    for (int i = 0; i < myConnections.size(); i++)
    {
        std::cout << "[" << (i + 1) << "] Enter " << myConnections[i].GetRoomName() << '\n';
    }
}
