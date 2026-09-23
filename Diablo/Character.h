#pragma once

#include <Windows.h>

#include "Enums.h"
#include "Utilities.h"

class Character
{
    // Private variables
    int myHealth = 0;
    int myDamage = 1;
    CharacterType myCharacterType;
    int myPhysique = 1;
    int mySkill = 1;
    int myStrength = 1;
    bool myIsImmortal = false;
    
    void AdjustAmount(int& aAmount) { aAmount = Min(aAmount, 1); }

public:
    // Getters
    int GetHealth() const { return myHealth; }
    int GetDamage() const { return myDamage * mySkill; }
    int GetDefense() const { return myPhysique + mySkill; }
    int GetCarryCapacity() const { return myStrength + mySkill / 3; }
    int GetMaxHealth() const { return myPhysique * 4 + myStrength * 6 + mySkill * 3; }
    CharacterType GetCharacterType() const { return myCharacterType; }

    bool IsImmortal() const { return myIsImmortal; }

    // Setters
    void Set(int& aTarget, int aAmount);
    void SetIsImmortal(bool aIsImmortal) { myIsImmortal = aIsImmortal; }

    void SetHealth(int aAmount) { Set(myHealth, aAmount); }
    void SetToFullHealth() { Set(myHealth, GetMaxHealth()); } 
    void SetSkill(int aAmount) { Set(mySkill, aAmount); }
    void SetPhysique(int aAmount) { Set(myPhysique, aAmount); }
    void SetStrength(int aAmount) { Set(myStrength, aAmount); }
    
    Character() = default;
    
    Character(CharacterType aCharacterType)
    {
        myCharacterType = aCharacterType;
        ResetCharacter();
    }
    
    void ResetCharacter()
    {
        SetToFullHealth();
        
        constexpr int DEFAULT_VALUE = 1;
        SetSkill(DEFAULT_VALUE);
        SetPhysique(DEFAULT_VALUE);
        SetStrength(DEFAULT_VALUE);
    }
    
    void Increase(int& aTarget, int aAmount)
    {
        AdjustAmount(aAmount);
        aTarget += aAmount;
    }
    
    void Decrease(int& aTarget, int aAmount)
    {
        AdjustAmount(aAmount);
        aTarget -= aAmount;
    }
    
    void IncreaseSkill(int aAmount) { Increase(mySkill, aAmount); }
    void IncreaseStrength(int aAmount) { Increase(myStrength, aAmount); }
    void IncreasePhysique(int aAmount) { Increase(myPhysique, aAmount); }
    void TakeDamage(int aAmount) { Decrease(myHealth, aAmount); }
    void Hurt(Character& aCharacter) { aCharacter.TakeDamage(GetDamage()); }
};