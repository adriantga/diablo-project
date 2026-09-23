#include <iostream>
#include <ostream>

#include "Character.h"
#include "Windows.h"

int main()
{
    Character playerCharacter = Character();
    playerCharacter.SetDamage(20);
    
    Character enemyCharacter = Character();
    enemyCharacter.SetDamage(10);

    while (playerCharacter.IsAlive() && enemyCharacter.IsAlive())
    {
        std::cout << "Player Health: " << playerCharacter.GetHealth() << '\n';
        std::cout << "Enemy Health: " << enemyCharacter.GetHealth() << '\n';
        
        Sleep(1000);
        enemyCharacter.TakeDamage(playerCharacter.GetDamage());
        std::cout << "Player dealt " << playerCharacter.GetDamage() << " to enemy!" << '\n';
        Sleep(1000);
        playerCharacter.TakeDamage(enemyCharacter.GetDamage());
        std::cout << "Enemy dealt " << enemyCharacter.GetDamage() << " to player!" << '\n';
        Sleep(1000);
        
        ClearConsole();
    }
    
    
    
    return 0;
}
