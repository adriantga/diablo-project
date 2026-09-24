#pragma once

struct Character
{
    int health = 0;
    int physique = 1;
    int strength = 1;
    int skill = 1;
    
    void RestoreHealth() { health = GetMaxHealth(); }
    
    int GetAttackValue() const { return strength * skill; }
    int GetMaxHealth() const { return physique * 4 + strength * 6 + skill * 3; }
    int GetCarryCapacity() const { return strength + skill / 3; }
    int GetDefense() const { return physique + skill; }
};