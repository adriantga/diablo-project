#include "BattleManager.h"

#include <cstdlib>
#include <iostream>

void BattleManager::EnterCombat(Player& aPlayer, Enemy& aEnemy)
{
    while (aEnemy.IsAlive())
    {
        // Might have to use a pointer for this
        ReceiveDamage(aPlayer, aEnemy);
        ReceiveDamage(aPlayer, aEnemy, false);
        
        system("pause");
        
        std::cout << "Enemy Health remaining: " << aEnemy.GetHealth() << '\n';
        std::cout << "Player Health remaining: " << aPlayer.GetHealth() << '\n';
        
    }

    if (aPlayer.IsAlive())
    {
        std::cout << "You won the battle! Yippee!" << '\n';
    }
}

void BattleManager::ReceiveDamage(Player& aPlayer, Enemy& aEnemy, bool isPlayer)
{
    if (aPlayer.IsAlive() && isPlayer)
    {
        aEnemy.TakeDamage(aPlayer.GetCharacter());
    }
    else if (aEnemy.IsAlive() && !isPlayer)
    {
        aPlayer.TakeDamage(aEnemy.GetCharacter());
    }
}
