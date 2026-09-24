#pragma once

#include "Utilities.h"

struct Character
{
    int health = 0;
    int physique = 1;
    int strength = 1;
    int skill = 1;
    
    int GetHealth() const { return health; }
    void RestoreHealth() { health = GetMaxHealth(); }
    int GetAttackValue() const { return strength * skill; }
    int GetMaxHealth() const { return physique * 4 + strength * 6 + skill * 3; }
    int GetCarryCapacity() const { return strength + skill / 3; }
    int GetDefense() const { return physique + skill; }
    bool IsAlive() const { return GetHealth() > 0; }
    
    void SetupAttributes()
    {
        physique = 1;
        strength = 1;
        skill = 1;
    }
    
    void TakeDamage(Character aCharacter)
    {
        int myDamage = aCharacter.GetAttackValue() - GetDefense();
        
        // Just for comparison
        int opponentDamage = GetAttackValue() - GetDefense();
        
        if (myDamage == opponentDamage || (myDamage == 0 || opponentDamage == 0))
        {
            myDamage = 1;
        }
        else
        {
            myDamage = Min(myDamage, 0);
        }
        
        health -= myDamage;
        health = Min(health, 0);
    }

    void IncreaseStrength()
    {
        strength++;
    }
    
    void IncreasePhysique()
    {
        physique++;
    }
    
    void IncreaseSkill()
    {
        skill++;
    }

};
