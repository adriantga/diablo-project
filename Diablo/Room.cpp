#include "Room.h"

#include <iostream>

#include "Utilities.h"

Room::Room(const char* aRoomName, const Diablo& aDiablo)
{
    myName = aRoomName;
    myDiablo = aDiablo;
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
    ClearScreen();
    std::cout << "------------------------------------ " << GetName() << " ------------------------------------" << '\n';
    std::cout << "Health -> " << aDiablo.player.GetHealth() << " / " << aDiablo.player.GetMaxHealth() << '\n';
    
    for (int i = 0; i < GetEnemyCount(); i++)
    {
        int enemyIndex = i + 1;
        const Enemy& enemy = myEnemies[i];
        
        std::cout << "[" << enemyIndex << "] Attack " << enemy.GetName() << " (" << enemy.GetHealth() << " / " << enemy.GetMaxHealth() << ")" << '\n';
    }
    std::cout << "[" << GetEnemyCount() + 1 << "] View stats" << '\n';
}
