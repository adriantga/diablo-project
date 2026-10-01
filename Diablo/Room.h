#pragma once
#include <iostream>
#include <vector>

#include "Enemy.h"

class Room
{
    std::vector<Room> myConnections = {};
    const char* myName = nullptr;
    
    // I think this could be a better way to handle rooms.
    int myId = -1;
    
    std::vector<Enemy> myEnemies = {};
    Diablo myDiablo = {};
    
public:
    // For logging!
    bool debug = false;
    
    Diablo GetGame() const
    {
        return myDiablo;
    }
    
    Room(const char* aRoomName, const Diablo& aDiablo);
    void AddConnection(const Room& aRoom);
    void EnterCombat(const Diablo& aDiablo);
    
    void SetId(const int aId)
    {
        myId = aId;
    }
    
    int GetId() const
    {
        return myId;
    }
    
    const char* GetName() const
    {
        return myName;
    }
    
    int GetConnectionsCount() const
    {
        return static_cast<int>(myConnections.size());
    }
    
    Room GetConnection(int aIndex) const
    {
        return myConnections[aIndex];
    }
    
    void ClearConnections()
    {
        myConnections.clear();
    }
    
    void SetConnections(const std::vector<Room>& aConnections)
    {
        myConnections = aConnections;
    }
    
    std::vector<Room> GetConnections()
    {
        return myConnections;
    }
    
    void AddEnemy(const Enemy& aEnemy)
    {
        myEnemies.push_back(aEnemy);
        if (debug)
        {
            std::cout << "[" << GetName() << "] Added enemy '" << aEnemy.GetName() << "' to the room!" << '\n';
        }
    }
    
    void RemoveEnemy(int aIndex)
    {
        if (aIndex >= 0 && aIndex < static_cast<int>(myEnemies.size()))
        {
            myEnemies.erase(myEnemies.begin() + aIndex);
        }
    }
    
    bool IsRoomCleared() const
    {
        return myEnemies.empty();
    }
    
    Enemy GetEnemy(int aIndex) const
    {
        return myEnemies.at(aIndex);
    }
    
    Enemy& GetEnemyRef(int aIndex)
    {
        return myEnemies.at(aIndex);
    }

    const std::vector<Enemy>& GetEnemies() const
    {
        return myEnemies;
    }

    std::vector<Enemy>& GetEnemies()
    {
        return myEnemies;
    }

    void RemoveDeadEnemies()
    {
        for (auto it = myEnemies.begin(); it != myEnemies.end();)
        {
            if (!it->IsAlive())
            {
                it = myEnemies.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    
    int GetEnemyCount() const { return static_cast<int>(myEnemies.size()); }
};
