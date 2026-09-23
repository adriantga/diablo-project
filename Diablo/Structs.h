#pragma once
#include "Combatant.h"
#include "Room.h"

struct Player
{
    // This struct will take care of things like
    // 1. Rooms traversed
    // 2. Enemies killed(for scaling difficulty)
    // More to come, possibly
    // -----------------------------------------------
    int roomsCleared = 0;
    int enemiesKilled = 0;
    
    Combatant combatant;
    Room previousRoom;
};

struct Enemy
{
    Combatant combatant;
};

struct GameData
{
    int minEnemyCount = 0;
    int maxEnemyCount = 1;
};

struct Diablo
{
    GameData gameData;
    Player player;
};