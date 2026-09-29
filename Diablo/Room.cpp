#include "Room.h"

#include <iostream>

Room::Room(const char* aRoomName)
{
    myName = aRoomName;
}

void Room::AddConnection(const Room& aRoom)
{
    myConnections.push_back(aRoom);
    if (debug)
    {
        std::cout << "[" << GetName() << "] Added " << aRoom.GetName() << " to the list of connections!" << '\n';
    }
}

void Room::EnterCombat(const Diablo& aDiablo)
{
    std::cout << "Health -> " << aDiablo.player.GetHealth() << '\n';
    
    for (int i = 0; i < GetEnemyCount(); i++)
    {
        int enemyIndex = i + 1;
        Enemy enemy = myEnemies[i];
        
        std::cout << "[" << enemyIndex << "] Attack " << enemy.GetName() << "(" << enemy.GetHealth() << "/" << enemy.GetMaxHealth() << ")" << '\n';
    }
}
