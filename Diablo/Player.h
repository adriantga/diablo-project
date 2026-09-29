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