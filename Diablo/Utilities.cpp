#include "Utilities.h"

#include <iostream>

int Min(int aValue, int aMin)
{
    return aValue < aMin ? aMin : aValue;
}

void ShowStats(const Character& character, const Player& player)
{
    int maxHealth = character.GetMaxHealth();

    std::cout << "----------------------------- ATTRIBUTES -----------------------------" << '\n';
    std::cout << "Health: " << character.health << " / " << maxHealth << '\n';
    std::cout << "Strength: " << character.strength << '\n';
    std::cout << "Agility: " << character.agility << '\n';
    std::cout << "Vitality: " << character.vitality << '\n';
    std::cout << "----------------------------- MAIN STATS -----------------------------" << '\n';
    std::cout << "Attack: " << character.GetAttackValue() << '\n';
    std::cout << "Defense: " << character.GetDefense() << '\n';
    std::cout << "Max Health: " << maxHealth << '\n';
    std::cout << "Carry Capacity: " << player.GetCarryCapacity() << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
}

void ShowStats(const Character& character)
{
    int maxHealth = character.GetMaxHealth();

    std::cout << "----------------------------- ATTRIBUTES -----------------------------" << '\n';
    std::cout << "Health: " << character.health << " / " << maxHealth << '\n';
    std::cout << "Strength: " << character.strength << '\n';
    std::cout << "Agility: " << character.agility << '\n';
    std::cout << "Vitality: " << character.vitality << '\n';
    std::cout << "----------------------------- MAIN STATS -----------------------------" << '\n';
    std::cout << "Attack: " << character.GetAttackValue() << '\n';
    std::cout << "Defense: " << character.GetDefense() << '\n';
    std::cout << "Max Health: " << maxHealth << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
}

static void DoCommand(const char* aCommand)
{
    system(aCommand);
}

void Pause()
{
    DoCommand("pause");
}

void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int CalculateDamageTaken(Character aSelf, Character aOpponent)
{
    int result = aOpponent.GetAttackValue() - aSelf.GetDefense();
    result = Min(result, 1);
    return result;
}

void ForceInput(int& aInput, int aMin, int aMax)
{
    bool hasLimits = aMin != -1 && aMax != -1;
    
    if (!hasLimits)
    {
        std::cout << "Please enter a valid range(Was given: " << aMin << " : " << aMax << ")" << '\n';
        return;
    }
    
    std::cin >> aInput;
    bool isInRange = aInput >= aMin && aInput <= aMax;
    
    while (!isInRange)
    {
        while (std::cin.fail())
        {
            std::cout << "Invalid input. Please enter a valid integer." << '\n';
            ClearInput();
            std::cin >> aInput;
        }
        
        std::cin >> aInput;
        isInRange = aInput >= aMin && aInput <= aMax;
    }
}

namespace CharacterFactory
{
    Enemy CreateEnemy(const char* aEnemyName, int aStrength, int aAgility, int aVitality, Room& room)
    {
        Enemy result = aEnemyName;
    
        result.SetStrength(aStrength);
        result.SetAgility(aAgility);
        result.SetVitality(aVitality);
    
        result.ResetHealth();
    
        room.AddEnemy(result);
        return result;
    }

    Player CreatePlayer(int aStrength, int aAgility, int aVitality)
    {
        Player result = Player();
        result.SetStrength(aStrength);
        result.SetAgility(aAgility);
        result.SetVitality(aVitality);
        result.ResetHealth();
        return result;
    }    
}
