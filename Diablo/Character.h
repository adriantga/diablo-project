#pragma once
#include <algorithm>
#include <iostream>

#include "Utilities.h"

class Character
{
    const int MAX_HEALTH = 100;
    int myHealth = 0;
    int myDamage = 10;
    
    void AdjustAmount(int& aAmount) { aAmount = Min(aAmount, 1);  }
    void ResetHealth() { myHealth = MAX_HEALTH; }
    
public:
    int GetHealth() const { return myHealth; }
    int GetDamage() const { return myDamage; }
    bool IsAlive() const { return myHealth > 0; }
    void SetDamage(int aDamage) { myDamage = aDamage; }
    void SetHealth(int aHealth) { myHealth = aHealth; }
    
    void Heal(int amount);
    void TakeDamage(int amount);
    void IncreaseDamage(int amount);
    
    Character()
    {
        ResetHealth();
        std::cout << "Initialized Character!" << '\n';
    }
};