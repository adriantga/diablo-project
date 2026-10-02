#pragma once
#include "Helpers.h"
#include "Item.h"

class Enemy
{
    Character myCharacter;
    const char* myName;
    bool myHasLoot = false;
    Item myLoot;
    int myDropChance = 100;
    
public:
    Enemy(const char* aEnemyName);
    Character GetCharacter() const { return myCharacter; }
    const char* GetName() const { return myName; }
    bool IsAlive() const { return myCharacter.IsAlive(); }
    int GetHealth() const { return myCharacter.GetHealth(); }
    int GetMaxHealth() const { return myCharacter.GetMaxHealth(); }
    int GetStrength() const { return myCharacter.strength; }
    int GetAgility() const { return myCharacter.agility; }
    int GetVitality() const { return myCharacter.vitality; }
    int GetAttackValue() const { return myCharacter.GetAttackValue(); }
    int GetDefense() const { return myCharacter.GetDefense(); }

    void SetLoot(const Item& aLoot, int aDropChance = 100)
    {
        myLoot = aLoot;
        myHasLoot = true;
        myDropChance = aDropChance;
    }

    bool HasLoot() const { return myHasLoot; }
    const Item& GetLoot() const { return myLoot; }
    int GetDropChance() const { return myDropChance; }
    
    void TakeDamage(int aDamage)
    {
        if (!myCharacter.IsAlive()) return;
        myCharacter.TakeDamage(aDamage);
    }
    
    void ResetHealth()
    {
        myCharacter.ResetHealth();
    }
    
    
    void AddStrength()
    {
        myCharacter.strength++;
    }
    
    void AddAgility()
    {
        myCharacter.agility++;
    }
    
    void AddVitality()
    {
        myCharacter.vitality++;
    }
    
    void SetStrength(int aStrength)
    {
        myCharacter.strength = aStrength;
    }
    
    void SetVitality(int aVitality)
    {
        myCharacter.vitality = aVitality;
    }
    
    void SetAgility(int aAgility)
    {
        myCharacter.agility = aAgility;
    }
};