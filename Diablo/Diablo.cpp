#include <iostream>

#include "Character.h"
#include "Utilities.h"

int main()
{
    std::cout << "Hello, World!" << '\n';
    Character playerCharacter = CharacterType::Player;
    std::cout << FromCharacterTypeToText(playerCharacter.GetCharacterType()) << '\n';
    
    Character enemyCharacter = CharacterType::Enemy;
    std::cout << FromCharacterTypeToText(enemyCharacter.GetCharacterType()) << '\n';
    
    Pause();
    return 0;
}