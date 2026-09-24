#include <cstdlib>
#include <iostream>

#include "BattleManager.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
    // [ENTER] Attack
    // [1/2/3] Enter Room
    
    Player player = Player();
    for (int i = 0; i < 2; i++)
    {
        player.IncreaseStrength();
        player.IncreasePhysique();
        player.IncreaseSkill();
    }
    
    std::cout << "PLAYER DEFENSE: " << player.GetDefense() << '\n';

    Enemy enemy = Enemy();
    std::cout << "ENEMY DEFENSE: " << enemy.GetDefense() << '\n';
    
    BattleManager battleManager = BattleManager();
    battleManager.EnterCombat(player, enemy);
    
    system("pause");
    
    return 0;
}