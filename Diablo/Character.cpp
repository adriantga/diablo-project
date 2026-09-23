#include "Character.h"

void Character::Heal(int amount)
{
    AdjustAmount(amount);
    myHealth -= amount;
}
    
void Character::TakeDamage(int amount)
{
    AdjustAmount(amount);
    myHealth -= amount;
}
    
void Character::IncreaseDamage(int amount)
{
    AdjustAmount(amount);  
    myDamage += amount;
}