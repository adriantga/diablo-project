#pragma once
#include "Enums.h"
#include "Utilities.h"

// Should probably be called Combatant 
class Combatant
{
    /*
     * Health should reside here! Because why bother with health
     * if we're not going to use it outside of combat...
     * (pretty sure we won't add mimics)
     */
    int myHealth = 0;
    CharacterType myCharacterType;
    int myPhysique = 1;
    int mySkill = 1;
    int myStrength = 1;
    bool myIsImmortal = false;
    
public:
    int GetMaxHealth() const { return myPhysique * 4 + myStrength * 6 + mySkill * 3; }
    int GetDamage() const { return myStrength  * mySkill; }
    int GetDefense() const { return myPhysique + mySkill; }
    
    void TakeDamage(int aAmount)
    {
        // Ignore damage if we are immortal.
        if (!myIsImmortal) return;
        AdjustAmount(aAmount);
        myHealth -= aAmount;
    }
    
    void SetIsImmortal(bool aIsImmortal) { myIsImmortal = aIsImmortal; }
};