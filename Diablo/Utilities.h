#pragma once
#include <string>
#include "Enemy.h"
#include "Helpers.h"
#include "Player.h"
#include "Room.h"

int Min(int aValue, int aMin);
void ClearScreen();
void Pause();
void ClearInput();
void ShowStats(const Character& character, const Player& player);
void ShowStats(const Character& character);
void ShowStats(const Diablo& diablo);
void ForceInput(int& aInput, int aMin = -1, int aMax = -1);
void ForceInput(int& aInput, Diablo& aDiablo, int aMin, int aMax);
bool HandleCheatCode(const std::string& aInput, Diablo& aDiablo);
int CalculateDamageTaken(Character aSelf, Character aOpponent);

namespace CharacterFactory
{
    Enemy CreateEnemy(const char* aEnemyName, int aStrength, int aAgility, int aVitality, Room& room);
    Player CreatePlayer(int aStrength, int aAgility, int aVitality);
}
