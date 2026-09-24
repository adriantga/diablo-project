#include "BattleManager.h"

#include <cstdlib>
#include <iostream>

void BattleManager::EnterCombat(Player aPlayer, Enemy aEnemy)
{
    do
    {
        aEnemy.TakeDamage(aPlayer.GetCharacter());
        aPlayer.TakeDamage(aEnemy.GetCharacter());
        
        system("pause");
        std::cout << "Enemy Health remaining: " << aEnemy.GetHealth() << '\n';
        std::cout << "Player Health remaining: " << aPlayer.GetHealth() << '\n';
    }
    while (aEnemy.IsAlive() && aPlayer.IsAlive());
    
    if (aPlayer.IsAlive())
    {
        std::cout << "Player made it out alive!" << '\n';
    }
    else if (aEnemy.IsAlive())
    {
        std::cout << "Enemy made it out alive..." << '\n';
    }
}