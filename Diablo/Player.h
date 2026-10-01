#pragma once
#include "Helpers.h"

class Player
{
    Character myCharacter;
public:
    Character GetCharacter() const { return myCharacter; }
    int GetCarryCapacity() const { return myCharacter.strength + myCharacter.agility / 3; }
    bool IsAlive() const { return myCharacter.IsAlive(); }
    int GetHealth() const { return myCharacter.GetHealth(); }
    int GetMaxHealth() const { return myCharacter.GetMaxHealth(); }
    int GetStrength() const { return myCharacter.strength; }
    int GetAgility() const { return myCharacter.agility; }
    int GetVitality() const { return myCharacter.vitality; }
    int GetAttackValue() const { return myCharacter.GetAttackValue(); }
    int GetDefense() const { return myCharacter.GetDefense(); }
    
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
    Cheats cheats;
};