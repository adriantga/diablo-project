#pragma once
#include "Helpers.h"
#include "Player.h"

class Enemy
{
    Character myCharacter;
    const char* myName;
    
public:
    Enemy(const char* aEnemyName);
    Character GetCharacter() const { return myCharacter; }
    const char* GetName() const { return myName; }
    bool IsAlive() const { return myCharacter.IsAlive(); }
    int GetHealth() const { return myCharacter.GetHealth(); }
    int GetMaxHealth() const { return myCharacter.GetMaxHealth(); }

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

struct Diablo
{
    Player player;
};
