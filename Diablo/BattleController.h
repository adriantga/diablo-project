#pragma once
#include "Enemy.h"
#include "Player.h"

class Enemy;
class Player;

class BattleController
{
    static void DisplayHealth(const Player& aPlayer, const Enemy& aEnemy);
public:
    static void Battle(Player& aPlayer, Enemy& aEnemy);
};
