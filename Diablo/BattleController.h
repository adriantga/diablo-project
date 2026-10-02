#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Room.h"

class Enemy;
class Player;
class Room;

class BattleController
{
    static void DisplayHealth(const Player& aPlayer, const Enemy& aEnemy);
    static void DisplayHealth(const Player& aPlayer, const std::vector<Enemy>& aEnemies);
public:
    static void Battle(Diablo& aDiablo, Enemy& aEnemy);
    static void Battle(Player& aPlayer, Enemy& aEnemy);
    static void BattleTurn(Diablo& aDiablo, Room& aRoom, int aTargetIndex);
};