#include <cstdlib>

#include "BattleManager.h"

int main()
{
    // [ENTER] Attack
    // [1/2/3] Enter Room
    
    Player player = Player();
    player.GetCharacter().SetupAttributes();
    player.IncreaseStrength();

    Enemy enemy = Enemy();
    enemy.GetCharacter().SetupAttributes();
    
    BattleManager battleManagerTest = BattleManager();
    battleManagerTest.EnterCombat(player, enemy);
    
    system("pause");
    
    return 0;
}
