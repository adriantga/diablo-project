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
    
    void TakeDamage(Character aCharacter)
    {
        int damage = aCharacter.GetAttackValue() - GetDefense();
        damage = Min(damage, 0);
        
        health -= damage;
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
