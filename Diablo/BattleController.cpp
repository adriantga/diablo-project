#include "BattleController.h"

#include <iostream>

#include "Utilities.h"


void BattleController::Battle(Player& aPlayer, Enemy& aEnemy)
{
    std::cout << "Player Health: " << aPlayer.GetCharacter().health << '\n';
    std::cout << "Enemy Health: " << aEnemy.GetCharacter().health << '\n';
    
    DisplayHealth(aPlayer, aEnemy);

    while (aPlayer.IsAlive() && aEnemy.IsAlive())
    {
        Character playerCharacter = aPlayer.GetCharacter();
        Character enemyCharacter = aEnemy.GetCharacter();
     
        Pause();
        
        if (aPlayer.IsAlive()) aEnemy.TakeDamage(CalculateDamageTaken(enemyCharacter, playerCharacter));
        if (aEnemy.IsAlive()) aPlayer.TakeDamage(CalculateDamageTaken(playerCharacter, enemyCharacter));
        
        DisplayHealth(aPlayer, aEnemy);
    }
    
    if (aPlayer.IsAlive())
    {
        std::cout << "Player won!\n"; 
    }
}

void BattleController::DisplayHealth(const Player& aPlayer, const Enemy& aEnemy)
{
    if (aPlayer.IsAlive()) std::cout << "Player Health: " << aPlayer.GetHealth() << '\n';
    if (aEnemy.IsAlive()) std::cout << "Enemy Health: " << aEnemy.GetHealth() << '\n';
}
