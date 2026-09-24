#pragma once
#include "Enemy.h"
#include "Player.h"

class BattleManager
{
    void ReceiveDamage(Player& aPlayer, Enemy& aEnemy, bool isPlayer = true);
    
public:
    void EnterCombat(Player& aPlayer, Enemy& aEnemy);
};