#include "Utilities.h"
#include <iostream>
#include <cstdlib>

constexpr int CHARACTER_CASE_OFFSET = 32;

void WriteLine(const char* aText, bool newLine)
{
    std::cout << aText << (newLine ? '\n' : ' ');
}

char ToCharacter(char aSource, bool lower = false)
{
    return aSource + (lower ? CHARACTER_CASE_OFFSET : -CHARACTER_CASE_OFFSET);
}

char ToUpperCharacter(char aSource)
{
    return ToCharacter(aSource, false);
}

char ToLowerCharacter(char aSource)
{
    return ToCharacter(aSource, true);
}

bool IsCharacter(char aSource, char aTarget)
{
    return aSource == aTarget || aSource == ToLowerCharacter(aTarget);
}

int Clamp(int aValue, int aMin, int aMax)
{
    return Max(Min(aValue, aMin), aMax);
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

void ClearInput()
{
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}