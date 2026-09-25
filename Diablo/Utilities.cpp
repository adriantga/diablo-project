#include "Utilities.h"

#include <iostream>
#include <random>

static std::random_device globalRnd;
static std::mt19937 globalGen(globalRnd());

void DoCommand(const char* aCommand)
{
    system(aCommand);
}

void PauseConsole()
{
    DoCommand("pause");
}

void ClearConsole()
{
    DoCommand("cls");
}

void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void ForceInput(int& aInput)
{
    std::cin >> aInput;
    
    while (std::cin.fail())
    {
        WriteLine("Please enter a valid integer!");
        ClearInput();
        std::cin >> aInput;
    }
}

void ForceInput(int& aInput, int aMin, int aMax)
{
    bool hasLimits = aMin != -1 && aMax != -1;
    
    std::cout << "Min: " << aMin << ", Max: " << aMax << '\n';
    
    if (aMin > aMax)
    {
        int temporary = aMax;
        aMax = aMin;
        aMin = temporary;
    }
    
    if (!hasLimits)
    {
        WriteLine("Please enter a valid range!");
        return;
    }

    bool isInRange = aInput >= aMin && aInput <= aMax;
    
    while (!isInRange)
    {
        while (std::cin.fail())
        {
            WriteLine("Please enter a valid integer!");
            ClearInput();
            std::cin >> aInput;
        }

        std::cin >> aInput;
        isInRange = aInput >= aMin && aInput <= aMax;
    }
}

int GetRandomNumber(int aMin, int aMax)
{
    std::uniform_int_distribution<> distributor(aMin, aMax);
    return distributor(globalGen);
}

void WriteLine(const char* aText, bool aNewLine)
{
    std::cout << aText << (aNewLine ? '\n' : '\0');
}

int Min(int aValue, int aMin)
{
    if (aValue < aMin) return aMin;
    return aValue;
}
