#include "Room.h"

#include <iostream>

#include "Utilities.h"

Room::Room(const char* aRoomName)
{
    myName = aRoomName;
}

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
    std::cout << "[" << GetEnemyCount() + 2 << "] View inventory" << '\n';
}

void Room::DisplayRoom(const Diablo& /*aDiablo*/) const
{
    ClearScreen();
    std::cout << "------------------------------------ " << GetName() << " ------------------------------------" << '\n';
    
    int optionNumber = 1;

    for (int connection = 0; connection < GetConnectionsCount(); connection++)
    {
        std::cout << "[" << optionNumber++ << "] Enter " << GetConnection(connection).GetName() << '\n';
    }

    for (size_t i = 0; i < myChests.size(); ++i)
    {
        if (!myChests[i].IsOpen())
        {
            std::cout << "[" << optionNumber++ << "] Open Chest: " << myChests[i].GetName() << '\n';
        }
    }

    for (size_t i = 0; i < myItems.size(); ++i)
    {
        std::cout << "[" << optionNumber++ << "] Pick up " << myItems[i].GetName() << " (Weight: " << myItems[i].GetWeight() << ")";
        std::string modStr = FormatModifiers(myItems[i].GetModifiers());
        if (!modStr.empty())
        {
            std::cout << " [" << modStr << "]";
        }
        std::cout << '\n';
    }

    for (size_t i = 0; i < mySpells.size(); ++i)
    {
        std::cout << "[" << optionNumber++ << "] Read Spell: " << mySpells[i].GetName() << " (Duration: " << mySpells[i].GetDuration() << " turns)";
        std::string modStr = FormatModifiers(mySpells[i].GetModifiers());
        if (!modStr.empty())
        {
            std::cout << " [" << modStr << "]";
        }
        std::cout << '\n';
    }

    std::cout << "[" << optionNumber++ << "] View stats" << '\n';
    std::cout << "[" << optionNumber++ << "] View inventory" << '\n';
}