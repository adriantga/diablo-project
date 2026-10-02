#pragma once
#include <vector>
#include "Helpers.h"
#include "Item.h"
#include "Spell.h"

class Player
{
    Character myCharacter;
    std::vector<Item> myInventory;
    std::vector<ActiveSpell> myActiveSpells;

public:
    Player() = default;

    Character GetBaseCharacter() const { return myCharacter; }

    StatModifier GetTotalModifiers() const
    {
        StatModifier total;
        for (const auto& item : myInventory)
        {
            const auto& mod = item.GetModifiers();
            total.strength += mod.strength;
            total.agility += mod.agility;
            total.vitality += mod.vitality;
            total.attack += mod.attack;
            total.defense += mod.defense;
            total.maxHealth += mod.maxHealth;
            total.carryCapacity += mod.carryCapacity;
        }
        for (const auto& activeSpell : myActiveSpells)
        {
            const auto& mod = activeSpell.spell.GetModifiers();
            total.strength += mod.strength;
            total.agility += mod.agility;
            total.vitality += mod.vitality;
            total.attack += mod.attack;
            total.defense += mod.defense;
            total.maxHealth += mod.maxHealth;
            total.carryCapacity += mod.carryCapacity;
        }
        return total;
    }

    int GetStrength() const { return myCharacter.strength + GetTotalModifiers().strength; }
    int GetAgility() const { return myCharacter.agility + GetTotalModifiers().agility; }
    int GetVitality() const { return myCharacter.vitality + GetTotalModifiers().vitality; }

    int GetAttackValue() const
    {
        return GetStrength() * GetAgility() + GetTotalModifiers().attack;
    }

    int GetDefense() const
    {
        return GetVitality() + GetAgility() + GetTotalModifiers().defense;
    }

    int GetMaxHealth() const
    {
        return GetVitality() * 4 + GetStrength() * 6 + GetAgility() * 3 + GetTotalModifiers().maxHealth;
    }

    int GetCarryCapacity() const
    {
        return GetStrength() + (GetAgility() / 3) + GetTotalModifiers().carryCapacity;
    }

    int GetTotalWeight() const
    {
        int weight = 0;
        for (const auto& item : myInventory)
        {
            weight += item.GetWeight();
        }
        return weight;
    }

    bool CanCarry(const Item& aItem) const
    {
        return (GetTotalWeight() + aItem.GetWeight()) <= GetCarryCapacity();
    }

    bool AddItem(const Item& aItem)
    {
        if (!CanCarry(aItem))
        {
            return false;
        }
        myInventory.push_back(aItem);
        return true;
    }

    void RemoveItem(int aIndex)
    {
        if (aIndex >= 0 && aIndex < static_cast<int>(myInventory.size()))
        {
            myInventory.erase(myInventory.begin() + aIndex);
        }
    }

    const std::vector<Item>& GetInventory() const { return myInventory; }
    std::vector<Item>& GetInventory() { return myInventory; }

    void CastSpell(const Spell& aSpell)
    {
        myActiveSpells.push_back({ aSpell, aSpell.GetDuration() });
    }

    void TickSpells()
    {
        for (auto it = myActiveSpells.begin(); it != myActiveSpells.end();)
        {
            it->turnsRemaining--;
            if (it->turnsRemaining <= 0)
            {
                it = myActiveSpells.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    const std::vector<ActiveSpell>& GetActiveSpells() const { return myActiveSpells; }
    std::vector<ActiveSpell>& GetActiveSpells() { return myActiveSpells; }

    Character GetCharacter() const
    {
        Character c;
        c.health = GetHealth();
        c.strength = GetStrength();
        c.agility = GetAgility();
        c.vitality = GetVitality();
        return c;
    }

    bool IsAlive() const { return myCharacter.health > 0; }
    int GetHealth() const { return myCharacter.health; }
    
    void TakeDamage(int aDamage)
    {
        if (!IsAlive()) return;
        myCharacter.TakeDamage(aDamage);
    }
    
    void ResetHealth()
    {
        myCharacter.health = GetMaxHealth();
    }
    
    void AddStrength()
    {
        myCharacter.strength++;
    }
    
    void AddAgility()
    {
        myCharacter.agility++;
    }
    
    void AddVitality()
    {
        myCharacter.vitality++;
    }
    
    void SetStrength(int aStrength)
    {
        myCharacter.strength = aStrength;
    }
    
    void SetVitality(int aVitality)
    {
        myCharacter.vitality = aVitality;
    }
    
    void SetAgility(int aAgility)
    {
        myCharacter.agility = aAgility;
    }

    void SetHealth(int aHealth)
    {
        myCharacter.health = aHealth;
    }
};

struct Diablo
{
    Player player;
    Cheats cheats;
};