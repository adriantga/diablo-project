#include "Utilities.h"

#include <iostream>
#include <random>

static std::random_device globalRnd;
static std::mt19937 globalGen(globalRnd());

int GetRandomNumber(int aMin, int aMax)
{
    std::uniform_int_distribution<> distributor(aMin, aMax);
    return distributor(globalGen);
}

void WriteLine(const char* aText, bool aNewLine)
{
    std::cout << aText << (aNewLine ? '\n' : '\0');
}