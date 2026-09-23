#include "Utilities.h"
#include "Windows.h"
#include <iostream>

constexpr int CASE_OFFSET = 32;

void ClearInput()
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

const char* FromCharacterTypeToText(CharacterType aCharacterType)
{
        
    switch (aCharacterType)
    {
    case CharacterType::Enemy:
        return "Enemy";
    case CharacterType::Player:
        return "Player";
    }
        
    return "";
}

void DoCommand(const char* aCommand)
{
    system(aCommand);
}

void Pause()
{
    DoCommand("pause");
}

void ClearConsole()
{
    DoCommand("cls");
}

char ToChar(char aSource, bool lower = false)
{
    return aSource + (CASE_OFFSET * (lower ? 1 : -1));    
}

int Min(int aValue, int aMin)
{
    if (aValue < aMin) return aMin;
    return aValue;
}

int Max(int aValue, int aMax)
{
    if (aValue > aMax) return aMax;
    return aValue;
}

int Abs(const int& aValue)
{
    return aValue * ((aValue > 0 ? 1 : -1));
}

int Clamp(int aValue, int aMin, int aMax)
{
    return Max(Min(aValue, aMin), aMax);
}

char LowerChar(char aSource)
{
    return ToChar(aSource, true);
}

char UpperChar(char aSource)
{
    return ToChar(aSource, false);
}