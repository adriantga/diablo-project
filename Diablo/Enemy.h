#pragma once
#include "Structs.h"

class Enemy
{
    Character myCharacter;
    
public:
    Enemy();
    
    Character GetCharacter() const { return myCharacter; }
    int GetHealth() const { return myCharacter.health; }
    bool IsAlive() const { return GetHealth() > 0; }
    void TakeDamage(Character aCharacter) { myCharacter.TakeDamage(aCharacter); }
    void RestoreHealth() { myCharacter.RestoreHealth(); }
    int GetDefense() const { return myCharacter.GetDefense(); }
    int GetMaxHealth() const { return myCharacter.GetMaxHealth(); }
};