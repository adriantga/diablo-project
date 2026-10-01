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

void ShowStats(const Diablo& diablo)
{
    ShowStats(diablo.player.GetCharacter(), diablo.player);
    std::cout << "----------------------------- CHEAT CODES ----------------------------" << '\n';
    std::cout << "Immortality (skill issue): " << diablo.cheats.GetState(diablo.cheats.isImmortal) << '\n';
    std::cout << "One-Hit Kill (magic trick): " << diablo.cheats.GetState(diablo.cheats.isOneHit) << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
}

static void DoCommand(const char* aCommand)
{
    system(aCommand);
}

void ClearScreen()
{
    DoCommand("cls");
}

void Pause()
{
    DoCommand("pause");
    ClearScreen();
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

bool HandleCheatCode(const std::string& aInput, Diablo& aDiablo)
{
    if (aInput == "skill issue")
    {
        aDiablo.cheats.isImmortal = !aDiablo.cheats.isImmortal;
        std::cout << "[CHEAT] Immortality is now: " << aDiablo.cheats.GetState(aDiablo.cheats.isImmortal) << '\n';
        return true;
    }
    if (aInput == "magic trick")
    {
        aDiablo.cheats.isOneHit = !aDiablo.cheats.isOneHit;
        std::cout << "[CHEAT] Instant kill is now: " << aDiablo.cheats.GetState(aDiablo.cheats.isOneHit) << '\n';
        return true;
    }
    return false;
}

void ForceInput(int& aInput, int aMin, int aMax)
{
    bool hasLimits = aMin != -1 && aMax != -1;
    
    if (!hasLimits)
    {
        std::cout << "Please enter a valid range(Was given: " << aMin << " : " << aMax << ")" << '\n';
        return;
    }
    
    std::string line;
    while (true)
    {
        if (!std::getline(std::cin, line))
        {
            ClearInput();
            continue;
        }

        size_t first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
        {
            continue;
        }
        size_t last = line.find_last_not_of(" \t\r\n");
        line = line.substr(first, (last - first + 1));

        try
        {
            size_t idx = 0;
            int val = std::stoi(line, &idx);
            if (idx == line.length() && val >= aMin && val <= aMax)
            {
                aInput = val;
                return;
            }
        }
        catch (...)
        {
        }

        std::cout << "Invalid input. Please enter a valid integer between " << aMin << " and " << aMax << ": " << '\n';
    }
}

void ForceInput(int& aInput, Diablo& aDiablo, int aMin, int aMax)
{
    bool hasLimits = aMin != -1 && aMax != -1;
    
    if (!hasLimits)
    {
        std::cout << "Please enter a valid range(Was given: " << aMin << " : " << aMax << ")" << '\n';
        return;
    }
    
    std::string line;
    while (true)
    {
        if (!std::getline(std::cin, line))
        {
            ClearInput();
            continue;
        }

        size_t first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
        {
            continue;
        }
        size_t last = line.find_last_not_of(" \t\r\n");
        line = line.substr(first, (last - first + 1));

        if (HandleCheatCode(line, aDiablo))
        {
            continue;
        }

        try
        {
            size_t idx = 0;
            int val = std::stoi(line, &idx);
            if (idx == line.length() && val >= aMin && val <= aMax)
            {
                aInput = val;
                return;
            }
        }
        catch (...)
        {
        }

        std::cout << "Invalid input. Please enter a valid integer between " << aMin << " and " << aMax << " (or a cheat code): " << '\n';
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
