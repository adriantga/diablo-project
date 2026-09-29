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
    
public:
    // For logging!
    bool debug = false;
    
    Room(const char* aRoomName);
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
        // Implement this.
    }
    
    bool IsRoomCleared() const
    {
        return myEnemies.empty();
    }
    
    Enemy GetEnemy(int aIndex) const
    {
        return myEnemies.at(aIndex);
    }
    
    int GetEnemyCount() const { return static_cast<int>(myEnemies.size()); }
};
