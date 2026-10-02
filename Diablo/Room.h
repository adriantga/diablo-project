#pragma once
#include <iostream>
#include <vector>

#include "Chest.h"
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "Spell.h"

class Room
{
    std::vector<Room> myConnections = {};
    const char* myName = nullptr;
    
    // I think this could be a better way to handle rooms.
    int myId = -1;
    
    std::vector<Enemy> myEnemies = {};
    std::vector<Item> myItems = {};
    std::vector<Spell> mySpells = {};
    std::vector<Chest> myChests = {};
    Diablo myDiablo = {};
    
public:
    // For logging!
    bool debug = false;
    
    Diablo GetGame() const
    {
        return myDiablo;
    }
    
    Room(const char* aRoomName, const Diablo& aDiablo);
    Room(const char* aRoomName = "Room");
    void AddConnection(const Room& aRoom);
    void EnterCombat(const Diablo& aDiablo);
    void DisplayRoom(const Diablo& aDiablo) const;
    
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

    void AddItem(const Item& aItem)
    {
        myItems.push_back(aItem);
    }

    void RemoveItem(int aIndex)
    {
        if (aIndex >= 0 && aIndex < static_cast<int>(myItems.size()))
        {
            myItems.erase(myItems.begin() + aIndex);
        }
    }

    const std::vector<Item>& GetItems() const { return myItems; }
    std::vector<Item>& GetItems() { return myItems; }
    int GetItemCount() const { return static_cast<int>(myItems.size()); }

    void AddSpell(const Spell& aSpell)
    {
        mySpells.push_back(aSpell);
    }

    void RemoveSpell(int aIndex)
    {
        if (aIndex >= 0 && aIndex < static_cast<int>(mySpells.size()))
        {
            mySpells.erase(mySpells.begin() + aIndex);
        }
    }

    const std::vector<Spell>& GetSpells() const { return mySpells; }
    std::vector<Spell>& GetSpells() { return mySpells; }
    int GetSpellCount() const { return static_cast<int>(mySpells.size()); }

    void AddChest(const Chest& aChest)
    {
        myChests.push_back(aChest);
    }

    void RemoveChest(int aIndex)
    {
        if (aIndex >= 0 && aIndex < static_cast<int>(myChests.size()))
        {
            myChests.erase(myChests.begin() + aIndex);
        }
    }

    const std::vector<Chest>& GetChests() const { return myChests; }
    std::vector<Chest>& GetChests() { return myChests; }
    int GetChestCount() const { return static_cast<int>(myChests.size()); }

    int GetUnopenedChestCount() const
    {
        int count = 0;
        for (const auto& chest : myChests)
        {
            if (!chest.IsOpen()) count++;
        }
        return count;
    }

    int GetUnopenedChestIndex(int aUnopenedOrdinal) const
    {
        int count = 0;
        for (size_t i = 0; i < myChests.size(); ++i)
        {
            if (!myChests[i].IsOpen())
            {
                if (count == aUnopenedOrdinal)
                {
                    return static_cast<int>(i);
                }
                count++;
            }
        }
        return -1;
    }
};
