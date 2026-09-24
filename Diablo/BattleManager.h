#pragma once
#include "Enemy.h"
#include "Player.h"

class BattleManager
{
    Player myPlayer;
    Enemy myEnemy;
    
public:
    void EnterCombat(Player aPlayer, Enemy aEnemy);
};