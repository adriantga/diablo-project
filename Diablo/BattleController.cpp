#include "BattleController.h"

#include <iostream>

#include "Utilities.h"


void BattleController::Battle(Diablo& aDiablo, Enemy& aEnemy)
{
    ClearScreen();
    std::cout << "\n================= BATTLE STARTED =================" << '\n';
    std::cout << "Fighting " << aEnemy.GetName() << "!" << '\n';

    while (aDiablo.player.IsAlive() && aEnemy.IsAlive())
    {
        Character playerCharacter = aDiablo.player.GetCharacter();
        Character enemyCharacter = aEnemy.GetCharacter();
     
        Pause();
        
        if (aDiablo.player.IsAlive())
        {
            int playerDamage = CalculateDamageTaken(enemyCharacter, playerCharacter);
            if (aDiablo.cheats.isOneHit)
            {
                playerDamage = aEnemy.GetHealth();
                std::cout << "[MAGIC TRICK] Instant kill activated!" << '\n';
            }
            aEnemy.TakeDamage(playerDamage);
            std::cout << "Player dealt " << playerDamage << " damage to " << aEnemy.GetName() << "!" << '\n';
        }

        if (aEnemy.IsAlive())
        {
            int enemyDamage = CalculateDamageTaken(playerCharacter, enemyCharacter);
            if (aDiablo.cheats.isImmortal)
            {
                enemyDamage = 0;
                std::cout << "[SKILL ISSUE] Player is immortal and took no damage!" << '\n';
            }
            else
            {
                aDiablo.player.TakeDamage(enemyDamage);
            }
            std::cout << aEnemy.GetName() << " dealt " << enemyDamage << " damage to Player!" << '\n';
        }
        
        DisplayHealth(aDiablo.player, aEnemy);
    }
    
    if (aDiablo.player.IsAlive())
    {
        std::cout << "Player won the battle against " << aEnemy.GetName() << "!\n"; 
    }
    std::cout << "==================================================" << '\n';
}

void BattleController::Battle(Player& aPlayer, Enemy& aEnemy)
{
    Diablo diablo = { aPlayer, {} };
    Battle(diablo, aEnemy);
    aPlayer = diablo.player;
}

void BattleController::BattleTurn(Diablo& aDiablo, Room& aRoom, int aTargetIndex)
{
    if (aTargetIndex < 0 || aTargetIndex >= aRoom.GetEnemyCount())
    {
        return;
    }

    ClearScreen();
    std::cout << "\n================= BATTLE TURN =================" << '\n';

    Enemy& targetEnemy = aRoom.GetEnemyRef(aTargetIndex);

    int playerDamage = aDiablo.player.GetAttackValue() - targetEnemy.GetDefense();
    playerDamage = Min(playerDamage, 1);
    if (aDiablo.cheats.isOneHit)
    {
        playerDamage = targetEnemy.GetHealth();
        std::cout << "[MAGIC TRICK] Instant kill activated!" << '\n';
    }
    targetEnemy.TakeDamage(playerDamage);
    std::cout << "Player dealt " << playerDamage << " damage to " << targetEnemy.GetName() << "!" << '\n';

    if (!targetEnemy.IsAlive())
    {
        std::cout << targetEnemy.GetName() << " was defeated!" << '\n';
        if (targetEnemy.HasLoot())
        {
            int roll = rand() % 100;
            if (roll < targetEnemy.GetDropChance())
            {
                Item loot = targetEnemy.GetLoot();
                aRoom.AddItem(loot);
                std::cout << targetEnemy.GetName() << " dropped [" << loot.GetName() << "] on the floor!" << '\n';
            }
        }
    }

    // Natural attack phase: all surviving enemies in the room counterattack the player
    for (int i = 0; i < aRoom.GetEnemyCount(); i++)
    {
        Enemy& enemy = aRoom.GetEnemyRef(i);
        if (enemy.IsAlive())
        {
            int enemyDamage = enemy.GetAttackValue() - aDiablo.player.GetDefense();
            enemyDamage = Min(enemyDamage, 1);
            if (aDiablo.cheats.isImmortal)
            {
                enemyDamage = 0;
                std::cout << "[SKILL ISSUE] Player is immortal and took no damage from " << enemy.GetName() << "!" << '\n';
            }
            else
            {
                aDiablo.player.TakeDamage(enemyDamage);
            }
            std::cout << enemy.GetName() << " dealt " << enemyDamage << " damage to Player!" << '\n';
        }
    }

    aDiablo.player.TickSpells();
    aRoom.RemoveDeadEnemies();

    std::cout << "--------------------------------------------------" << '\n';
    DisplayHealth(aDiablo.player, aRoom.GetEnemies());
    std::cout << "==================================================" << '\n';

    if (!aDiablo.player.IsAlive())
    {
        std::cout << "Player was defeated in battle!\n";
    }
    else if (aRoom.IsRoomCleared())
    {
        std::cout << "Player defeated all enemies in " << aRoom.GetName() << "!\n";
    }

    Pause();
}

void BattleController::DisplayHealth(const Player& aPlayer, const Enemy& aEnemy)
{
    if (aPlayer.IsAlive()) std::cout << "Player Health: " << aPlayer.GetHealth() << " / " << aPlayer.GetMaxHealth() << '\n';
    if (aEnemy.IsAlive()) std::cout << "Enemy Health: " << aEnemy.GetHealth() << " / " << aEnemy.GetMaxHealth() << '\n';
}

void BattleController::DisplayHealth(const Player& aPlayer, const std::vector<Enemy>& aEnemies)
{
    if (aPlayer.IsAlive())
    {
        std::cout << "Player Health: " << aPlayer.GetHealth() << " / " << aPlayer.GetMaxHealth() << '\n';
    }
    for (const auto& enemy : aEnemies)
    {
        if (enemy.IsAlive())
        {
            std::cout << enemy.GetName() << " Health: " << enemy.GetHealth() << " / " << enemy.GetMaxHealth() << '\n';
        }
    }
}