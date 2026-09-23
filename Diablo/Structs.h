#pragma once

struct Player
{
    // This struct will take care of things like
    // 1. Rooms traversed
    // 2. Enemies killed(for scaling difficulty)
    // More to come, possibly
    // -----------------------------------------------
    
    int roomsCleared = 0;
    int enemiesKilled = 0;
};

struct GameData
{
    Player player;
};