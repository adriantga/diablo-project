#pragma once
#include "Structs.h"

class Player
{
    Character myCharacter;
    
public:
    Player();

    Character GetCharacter() const { return myCharacter; }
    
    int GetHealth() const { return myCharacter.GetHealth(); }
    bool IsAlive() const { return GetHealth() > 0; }
    void TakeDamage(Character aCharacter) { myCharacter.TakeDamage(aCharacter); }
    void RestoreHealth() { myCharacter.RestoreHealth(); }
    int GetDefense() const { return myCharacter.GetDefense(); }
    int GetCarryCapacity() const { return myCharacter.GetCarryCapacity(); }
    int GetMaxHealth() const { return myCharacter.GetMaxHealth(); }
    
    void IncreaseStrength() { myCharacter.IncreaseStrength(); }
    void IncreaseSkill() { myCharacter.IncreaseSkill(); }
    void IncreasePhysique() { myCharacter.IncreasePhysique(); }
    
};