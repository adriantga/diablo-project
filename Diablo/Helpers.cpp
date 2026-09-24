#include "Utilities.h"

#include <iostream>
#include <random>

std::mt19937 globalGenerator;

void InitializeRandom()
{
    std::random_device globalSeed;
    globalGenerator = std::mt19937(globalSeed());
}

int GetRandomNumber(int aMin, int aMax)
{
    std::uniform_int_distribution<> distribution(aMin, aMax);
    return distribution(globalGenerator);
}

void WriteLine(const char* aText, bool aNewLine)
{
    std::cout << aText;
    if (aNewLine) std::cout << '\n';
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

int Clamp(int aValue, int aMin, int aMax)
{
    return Max(Min(aValue, aMin), aMax);
}