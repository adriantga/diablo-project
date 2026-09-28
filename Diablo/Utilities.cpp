#include "Utilities.h"

#include <iostream>

// ----------------------------------
// WRAPPERS
// ----------------------------------
void WriteLine(const char* aText, bool aNewLine)
{
    std::cout << aText << (aNewLine ? '\n' : '\0');
}

void DoCommand(const char* aCommand)
{
    system(aCommand);
}

void Pause()
{
    DoCommand("pause");
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
        WriteLine("Please only enter numbers!");
        ClearInput();
        std::cin >> aInput;
    }
}

bool HasSubceeded(int aSource, int aTarget)
{
    return aSource < aTarget;
}

bool HasExceeded(int aSource, int aTarget)
{
    return aSource > aTarget;
}

void ForceInput(int& aInput, int aMin, int aMax)
{
    if (aMin == aMax)
    {
        std::cout << "Enter a number (" << aMin << "):" << '\n';
    }
    else
    {
        std::cout << "Enter a number (" << aMin << " - " << aMax << "):" << '\n';
    }

    
    std::cin >> aInput;
    bool hasLimits = aMin != -1 && aMax != -1;
    bool isInRange = !HasSubceeded(aInput, aMin) && !HasExceeded(aInput, aMax);
    
    if (!hasLimits)
    {
        WriteLine("The range you entered is invalid!");
        return;
    }

    while (!isInRange)
    {
        while (std::cin.fail())
        {
            WriteLine("Please only enter numbers!");
            ClearInput();
            std::cin >> aInput;
        }
        
        std::cin >> aInput;
        isInRange = !HasSubceeded(aInput, aMin) && !HasExceeded(aInput, aMax);
    }
    
    ClearInput();
}
