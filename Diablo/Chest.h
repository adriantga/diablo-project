#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Chest
{
private:
    std::string myName;
    std::vector<Item> myItems;
    bool myIsOpen = false;

public:
    Chest() = default;
    Chest(const std::string& aName, const std::vector<Item>& aItems = {})
        : myName(aName), myItems(aItems), myIsOpen(false)
    {
    }

    const std::string& GetName() const { return myName; }
    bool IsOpen() const { return myIsOpen; }
    void SetOpen(bool aIsOpen) { myIsOpen = aIsOpen; }
    void Open() { myIsOpen = true; }

    const std::vector<Item>& GetItems() const { return myItems; }
    std::vector<Item>& GetItems() { return myItems; }
    void AddItem(const Item& aItem) { myItems.push_back(aItem); }
    void ClearItems() { myItems.clear(); }
    bool IsEmpty() const { return myItems.empty(); }
    int GetItemCount() const { return static_cast<int>(myItems.size()); }
};
