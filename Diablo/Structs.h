#pragma once

enum class CharacterType;

struct Character
{
    int health = 1;
    int damage = 1;
    int physique = 1;
    int strength = 1;
    int skill = 1;
    CharacterType characterType;
    
    int GetCarryCapacity()
    {
        return strength + skill / 3;
    }
    
    int GetAttackDamage()
    {
        return strength * skill;
    }
    
    int GetDefense()
    {
        return physique + skill;
    }
    
    int GetMaxHealth()
    {
        return physique * 4 + strength * 6 + skill * 3;
    }
};