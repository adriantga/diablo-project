#include "Character.h"

void Character::Set(int& aTarget, int aAmount)
{
    AdjustAmount(aAmount);
    aTarget = aAmount;
}