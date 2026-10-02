#include "Utilities.h"

#include <iostream>

int Min(int aValue, int aMin)
{
    return aValue < aMin ? aMin : aValue;
}

void ShowStats(const Character& /*character*/, const Player& player)
{
    int maxHealth = player.GetMaxHealth();

    std::cout << "----------------------------- ATTRIBUTES -----------------------------" << '\n';
    std::cout << "Health: " << player.GetHealth() << " / " << maxHealth << '\n';
    std::cout << "Strength: " << player.GetStrength() << '\n';
    std::cout << "Agility: " << player.GetAgility() << '\n';
    std::cout << "Vitality: " << player.GetVitality() << '\n';
    std::cout << "----------------------------- MAIN STATS -----------------------------" << '\n';
    std::cout << "Attack: " << player.GetAttackValue() << '\n';
    std::cout << "Defense: " << player.GetDefense() << '\n';
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

std::string FormatModifiers(const StatModifier& aMod)
{
    std::string s;
    auto appendMod = [&](const std::string& name, int val) {
        if (val != 0) {
            if (!s.empty()) s += ", ";
            if (val > 0) s += "+";
            s += std::to_string(val) + " " + name;
        }
    };
    appendMod("STR", aMod.strength);
    appendMod("AGI", aMod.agility);
    appendMod("VIT", aMod.vitality);
    appendMod("ATK", aMod.attack);
    appendMod("DEF", aMod.defense);
    appendMod("HP", aMod.maxHealth);
    appendMod("CAP", aMod.carryCapacity);
    return s;
}

void ShowStats(const Diablo& diablo)
{
    const Player& player = diablo.player;
    int maxHealth = player.GetMaxHealth();
    int health = player.GetHealth();
    StatModifier mods = player.GetTotalModifiers();

    std::cout << "----------------------------- ATTRIBUTES -----------------------------" << '\n';
    std::cout << "Health: " << health << " / " << maxHealth << '\n';
    std::cout << "Strength: " << player.GetStrength() << " (Base: " << player.GetBaseCharacter().strength << ", Mod: " << (mods.strength >= 0 ? "+" : "") << mods.strength << ")" << '\n';
    std::cout << "Agility: " << player.GetAgility() << " (Base: " << player.GetBaseCharacter().agility << ", Mod: " << (mods.agility >= 0 ? "+" : "") << mods.agility << ")" << '\n';
    std::cout << "Vitality: " << player.GetVitality() << " (Base: " << player.GetBaseCharacter().vitality << ", Mod: " << (mods.vitality >= 0 ? "+" : "") << mods.vitality << ")" << '\n';
    std::cout << "----------------------------- MAIN STATS -----------------------------" << '\n';
    std::cout << "Attack: " << player.GetAttackValue() << '\n';
    std::cout << "Defense: " << player.GetDefense() << '\n';
    std::cout << "Max Health: " << maxHealth << '\n';
    std::cout << "Carry Capacity: " << player.GetCarryCapacity() << " (Carrying: " << player.GetTotalWeight() << " / " << player.GetCarryCapacity() << ")" << '\n';
    std::cout << "----------------------------- CHEAT CODES ----------------------------" << '\n';
    std::cout << "Immortality (skill issue): " << diablo.cheats.GetState(diablo.cheats.isImmortal) << '\n';
    std::cout << "One-Hit Kill (magic trick): " << diablo.cheats.GetState(diablo.cheats.isOneHit) << '\n';
    std::cout << "----------------------------------------------------------------------" << '\n';
}

void ShowInventory(const Diablo& diablo)
{
    const Player& player = diablo.player;
    std::cout << "============================= INVENTORY =============================" << '\n';
    std::cout << "Carry Capacity: " << player.GetTotalWeight() << " / " << player.GetCarryCapacity() << '\n';
    const auto& items = player.GetInventory();
    if (items.empty())
    {
        std::cout << "Inventory is empty." << '\n';
    }
    else
    {
        std::cout << "\nCarried Items (" << items.size() << "):" << '\n';
        for (size_t i = 0; i < items.size(); ++i)
        {
            const auto& item = items[i];
            std::cout << " [" << (i + 1) << "] " << item.GetName() << " (Weight: " << item.GetWeight() << ")";
            std::string modStr = FormatModifiers(item.GetModifiers());
            if (!modStr.empty())
            {
                std::cout << " [" << modStr << "]";
            }
            if (!item.GetDescription().empty())
            {
                std::cout << " - " << item.GetDescription();
            }
            std::cout << '\n';
        }
    }
    const auto& spells = player.GetActiveSpells();
    if (!spells.empty())
    {
        std::cout << "\nActive Spells (" << spells.size() << "):" << '\n';
        for (size_t i = 0; i < spells.size(); ++i)
        {
            const auto& activeSpell = spells[i];
            std::cout << " - " << activeSpell.spell.GetName() << " (" << activeSpell.turnsRemaining << " turns remaining)";
            std::string modStr = FormatModifiers(activeSpell.spell.GetModifiers());
            if (!modStr.empty())
            {
                std::cout << " [" << modStr << "]";
            }
            std::cout << '\n';
        }
    }
    std::cout << "=====================================================================" << '\n';
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
    Enemy CreateEnemy(const char* aEnemyName, int aStrength, int aAgility, int aVitality, Room& room, const Item& aLoot, int aDropChance)
    {
        Enemy result = aEnemyName;
    
        result.SetStrength(aStrength);
        result.SetAgility(aAgility);
        result.SetVitality(aVitality);
    
        result.ResetHealth();
        if (aDropChance > 0)
        {
            result.SetLoot(aLoot, aDropChance);
        }
    
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