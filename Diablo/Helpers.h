#pragma once
int Min(int aValue, int aMin);

struct StatModifier
{
    int strength = 0;
    int agility = 0;
    int vitality = 0;
    int attack = 0;
    int defense = 0;
    int maxHealth = 0;
    int carryCapacity = 0;
};

struct Character
{
    int health = 1;
    int strength = 1;
    int agility = 1;
    int vitality = 1;
    
    int GetHealth() const
    {
        return health;
    }
    
    void TakeDamage(int aDamage)
    {
        aDamage = Min(aDamage, 1);
        health -= aDamage;
    }
    
    int GetAttackValue() const
    {
        return strength * agility;
    }
    
    int GetMaxHealth() const
    {
        return vitality * 4 + strength * 6 + agility * 3;
    }
    
    int GetDefense() const
    {
        return vitality + agility;
    }
    
    void ResetHealth()
    {
        health = GetMaxHealth();
    }
    
    bool IsAlive() const
    {
        return health > 0;
    }
};

struct Cheats
{
    bool isImmortal = false;
    bool isOneHit = false;

    const char* GetState(bool aIsActive) const
    {
        return aIsActive ? "YES" : "NO";
    }
};