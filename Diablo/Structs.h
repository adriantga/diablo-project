#pragma once
#include "Combatant.h"

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
};

struct Enemy
{
    Combatant combatant;
};

struct GameData
{
    // We only need to do this for now.
    Player player;
};