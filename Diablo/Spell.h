#pragma once
#include <string>
#include "Helpers.h"

class Spell
{
private:
    std::string myName;
    std::string myDescription;
    int myDuration = 0;
    StatModifier myModifiers;

public:
    Spell() = default;
    Spell(const std::string& aName, int aDuration, const StatModifier& aModifiers = {}, const std::string& aDescription = "")
        : myName(aName), myDescription(aDescription), myDuration(aDuration), myModifiers(aModifiers)
    {
    }

    const std::string& GetName() const { return myName; }
    const std::string& GetDescription() const { return myDescription; }
    int GetDuration() const { return myDuration; }
    const StatModifier& GetModifiers() const { return myModifiers; }
    void SetModifiers(const StatModifier& aModifiers) { myModifiers = aModifiers; }
};

struct ActiveSpell
{
    Spell spell;
    int turnsRemaining = 0;
};
