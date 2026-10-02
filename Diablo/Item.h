#pragma once
#include <string>
#include "Helpers.h"

class Item
{
private:
    std::string myName;
    std::string myDescription;
    int myWeight = 0;
    StatModifier myModifiers;

public:
    Item() = default;
    Item(const std::string& aName, int aWeight, const StatModifier& aModifiers = {}, const std::string& aDescription = "")
        : myName(aName), myDescription(aDescription), myWeight(aWeight), myModifiers(aModifiers)
    {
    }

    const std::string& GetName() const { return myName; }
    const std::string& GetDescription() const { return myDescription; }
    int GetWeight() const { return myWeight; }
    const StatModifier& GetModifiers() const { return myModifiers; }
    void SetModifiers(const StatModifier& aModifiers) { myModifiers = aModifiers; }
};
