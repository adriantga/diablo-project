#include "BattleController.h"
#include "Door.h"
#include "Room.h"
#include "Utilities.h"

void ShowMainMenu()
{
    ClearScreen();
    std::cout << "==================================================" << '\n';
    std::cout << "                      DIABLO                      " << '\n';
    std::cout << "==================================================" << '\n';
    std::cout << "[1] Play" << '\n';
    std::cout << "[2] Cheats" << '\n';
    std::cout << "[3] Quit" << '\n';
    std::cout << "==================================================" << '\n';
}

void ShowCheatsMenu(Diablo& aDiablo)
{
    bool inCheatsMenu = true;
    while (inCheatsMenu)
    {
        ClearScreen();
        std::cout << "==================================================" << '\n';
        std::cout << "                   CHEATS MENU                    " << '\n';
        std::cout << "==================================================" << '\n';
        std::cout << "[1] Immortality (skill issue): " << aDiablo.cheats.GetState(aDiablo.cheats.isImmortal) << '\n';
        std::cout << "[2] One-Hit Kill (magic trick): " << aDiablo.cheats.GetState(aDiablo.cheats.isOneHit) << '\n';
        std::cout << "[3] Back to Main Menu" << '\n';
        std::cout << "==================================================" << '\n';

        int cheatChoice;
        ForceInput(cheatChoice, aDiablo, 1, 3);

        switch (cheatChoice)
        {
        case 1:
            aDiablo.cheats.isImmortal = !aDiablo.cheats.isImmortal;
            break;
        case 2:
            aDiablo.cheats.isOneHit = !aDiablo.cheats.isOneHit;
            break;
        case 3:
            inCheatsMenu = false;
            break;
        }
    }
}

void PlayGame(Diablo& diablo)
{
    Room entrance = Room("Entrance", diablo);
    entrance.SetId(0);
    
    Room cathedral = Room("Cathedral", diablo);
    cathedral.SetId(1);
    
    Room armory = Room("Armory", diablo);
    armory.SetId(2);
    
    Room kitchen = Room("Kitchen", diablo);
    kitchen.SetId(3);
    
    Room cells = Room("Cells", diablo);
    cells.SetId(4);
    
    entrance.AddConnection(cathedral);
    
    cathedral.AddConnection(entrance);
    cathedral.AddConnection(armory);
    
    armory.AddConnection(cathedral);
    armory.AddConnection(kitchen);
    
    kitchen.AddConnection(armory);
    kitchen.AddConnection(cells);
    
    cells.AddConnection(kitchen);

    // Items, Spells, Chests in Entrance
    StatModifier woodenClubMod;
    woodenClubMod.strength = 1;
    woodenClubMod.attack = 2;
    entrance.AddItem(Item("Wooden Club", 2, woodenClubMod, "A sturdy wooden club"));

    StatModifier potionMod;
    potionMod.maxHealth = 10;
    StatModifier daggerMod;
    daggerMod.agility = 1;
    daggerMod.attack = 1;
    Chest entranceChest("Old Wooden Chest", {
        Item("Health Potion", 1, potionMod, "Restores vitality and vigor"),
        Item("Rusty Dagger", 1, daggerMod, "A quick small blade")
    });
    entrance.AddChest(entranceChest);

    StatModifier protectSpellMod;
    protectSpellMod.defense = 3;
    entrance.AddSpell(Spell("Scroll of Protection", 6, protectSpellMod, "Surrounds the player with a protective barrier"));

    // Cathedral contents
    StatModifier holyBladeMod;
    holyBladeMod.strength = 3;
    holyBladeMod.attack = 5;
    StatModifier blessedRingMod;
    blessedRingMod.vitality = 2;
    blessedRingMod.defense = 2;
    Chest cathedralChest("Cathedral Reliquary", {
        Item("Holy Blade", 4, holyBladeMod, "A sanctified blade"),
        Item("Blessed Ring", 1, blessedRingMod, "A ring blessed by ancient clerics")
    });
    cathedral.AddChest(cathedralChest);

    StatModifier mightSpellMod;
    mightSpellMod.strength = 3;
    mightSpellMod.attack = 4;
    cathedral.AddSpell(Spell("Blessing of Might", 8, mightSpellMod, "Grants divine physical power"));

    // Armory contents
    StatModifier boneShieldMod;
    boneShieldMod.defense = 2;
    boneShieldMod.vitality = 1;
    Item boneShield("Bone Shield", 3, boneShieldMod, "A shield crafted from hardened bones");
    CharacterFactory::CreateEnemy("Skeleton", 1, 1, 1, armory, boneShield, 100);

    StatModifier ironSwordMod;
    ironSwordMod.strength = 4;
    ironSwordMod.attack = 6;
    Item ironSword("Iron Greatsword", 5, ironSwordMod, "A heavy two-handed greatsword");
    CharacterFactory::CreateEnemy("Undead Warrior", 1, 1, 2, armory, ironSword, 100);

    StatModifier plateArmorMod;
    plateArmorMod.defense = 5;
    plateArmorMod.vitality = 4;
    plateArmorMod.agility = -1;
    Chest armoryChest("Armory Weapon Chest", {
        Item("Plate Armor", 6, plateArmorMod, "Heavy steel plate armor (-1 Agility)")
    });
    armory.AddChest(armoryChest);

    StatModifier knifeMod;
    knifeMod.agility = 2;
    knifeMod.attack = 3;
    armory.AddItem(Item("Throwing Knives", 2, knifeMod, "Balanced steel daggers"));

    // Kitchen contents
    StatModifier cleaverMod;
    cleaverMod.strength = 2;
    cleaverMod.attack = 3;
    kitchen.AddItem(Item("Chef's Cleaver", 2, cleaverMod, "A sharp heavy butchering tool"));

    StatModifier flameSpellMod;
    flameSpellMod.attack = 4;
    kitchen.AddSpell(Spell("Flame Enchantment", 5, flameSpellMod, "Ignites weapon strikes with fire"));

    StatModifier rationsMod;
    rationsMod.maxHealth = 15;
    rationsMod.vitality = 1;
    Chest kitchenChest("Pantry Crate", {
        Item("Iron Rations", 1, rationsMod, "Hearty preserved meal")
    });
    kitchen.AddChest(kitchenChest);

    // Cells contents
    StatModifier cloakMod;
    cloakMod.agility = 3;
    cloakMod.defense = 3;
    StatModifier giantsRingMod;
    giantsRingMod.strength = 3;
    giantsRingMod.carryCapacity = 5;
    Chest cellsChest("Dungeon Master's Chest", {
        Item("Shadow Cloak", 2, cloakMod, "A cloak that blends into darkness"),
        Item("Ring of the Giant", 1, giantsRingMod, "Increases muscle and carry capacity")
    });
    cells.AddChest(cellsChest);

    StatModifier speedSpellMod;
    speedSpellMod.agility = 4;
    cells.AddSpell(Spell("Scroll of Speed", 5, speedSpellMod, "Increases speed and reflex"));

    Door entranceDoor = Door(entrance, diablo);
    Door cathedralDoor = Door(cathedral, diablo);
    cathedralDoor.SetLocked(true, 3, 4);
    
    Door armoryDoor = Door(armory, diablo);
    Door kitchenDoor = Door(kitchen, diablo);
    Door cellsDoor = Door(cells, diablo);
    
    std::vector<Room> rooms = {entrance, cathedral, armory, kitchen, cells};
    std::vector<Door> doors = {entranceDoor, cathedralDoor, armoryDoor, kitchenDoor, cellsDoor};

    int currentRoomId = 0;
    int previousRoomId = 0;

    Player player = CharacterFactory::CreatePlayer(5, 4, 6);
    diablo.player = player;
    
    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
    
    bool shouldRun = true;
    int input;
    
    while (shouldRun)
    {
        if (doors[currentRoomId].IsLocked())
        {
            constexpr int MAX_OPTIONS = 5;
            ForceInput(input, diablo, 1, MAX_OPTIONS);

            switch (input)
            {
            case 1:
                if (diablo.player.GetStrength() >= doors[currentRoomId].GetRequiredStrength())
                {
                    doors[currentRoomId].SetLocked(false);
                    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                }
                else
                {
                    ClearScreen();
                    std::cout << "You tried to brute-force the door, however, you failed!\n";
                    Pause();
                    currentRoomId = previousRoomId;
                    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                }
                break;
            case 2:
                if (diablo.player.GetAgility() >= doors[currentRoomId].GetRequiredAgility())
                {
                    doors[currentRoomId].SetLocked(false);
                    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                }
                else
                {
                    ClearScreen();
                    std::cout << "You accidentally broke the lockpick!\n";
                    Pause();
                    currentRoomId = previousRoomId;
                    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                }
                break;
            case 3:
                currentRoomId = previousRoomId;
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                break;
            case 4:
                ClearScreen();
                ShowStats(diablo);
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                break;
            case 5:
                ClearScreen();
                ShowInventory(diablo);
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                break;
            }
        }
        else if (!rooms[currentRoomId].IsRoomCleared())
        {
            int enemyCount = rooms[currentRoomId].GetEnemyCount();
            int statsOption = enemyCount + 1;
            int inventoryOption = enemyCount + 2;
            
            ForceInput(input, diablo, 1, inventoryOption);

            if (input == statsOption)
            {
                ClearScreen();
                ShowStats(diablo);
                Pause();
                rooms[currentRoomId].EnterCombat(diablo);
            }
            else if (input == inventoryOption)
            {
                ClearScreen();
                ShowInventory(diablo);
                Pause();
                rooms[currentRoomId].EnterCombat(diablo);
            }
            else
            {
                int finalInput = input - 1;
                
                BattleController::BattleTurn(diablo, rooms[currentRoomId], finalInput);
                doors[currentRoomId].SetRoom(rooms[currentRoomId]);
                
                if (!diablo.player.IsAlive())
                {
                    std::cout << "You died!\n";
                    Pause();
                    shouldRun = false;
                    break;
                }
                
                if (!rooms[currentRoomId].IsRoomCleared())
                {
                    rooms[currentRoomId].EnterCombat(diablo);
                }
                else
                {
                    doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
                }
            }
        }
        else
        {
            int connectionsCount = rooms[currentRoomId].GetConnectionsCount();
            int chestCount = rooms[currentRoomId].GetUnopenedChestCount();
            int itemCount = rooms[currentRoomId].GetItemCount();
            int spellCount = rooms[currentRoomId].GetSpellCount();

            int statsOption = connectionsCount + chestCount + itemCount + spellCount + 1;
            int inventoryOption = connectionsCount + chestCount + itemCount + spellCount + 2;

            ForceInput(input, diablo, 1, inventoryOption);

            if (input == statsOption)
            {
                ClearScreen();
                ShowStats(diablo);
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
            else if (input == inventoryOption)
            {
                ClearScreen();
                ShowInventory(diablo);
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
            else if (input <= connectionsCount)
            {
                int finalInput = input - 1;
                int nextRoomId = rooms[currentRoomId].GetConnection(finalInput).GetId();
                previousRoomId = currentRoomId;
                currentRoomId = nextRoomId;
                diablo.player.TickSpells();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
            else if (input <= connectionsCount + chestCount)
            {
                int unopenedOrdinal = input - connectionsCount - 1;
                int chestIndex = rooms[currentRoomId].GetUnopenedChestIndex(unopenedOrdinal);
                Chest& chest = rooms[currentRoomId].GetChests()[chestIndex];
                chest.Open();

                ClearScreen();
                std::cout << "You opened the [" << chest.GetName() << "]!" << '\n';
                if (chest.IsEmpty())
                {
                    std::cout << "The chest was empty." << '\n';
                }
                else
                {
                    std::cout << "The following items fell out onto the floor:" << '\n';
                    for (const auto& item : chest.GetItems())
                    {
                        std::cout << " - " << item.GetName() << " (Weight: " << item.GetWeight() << ")";
                        std::string modStr = FormatModifiers(item.GetModifiers());
                        if (!modStr.empty())
                        {
                            std::cout << " [" << modStr << "]";
                        }
                        std::cout << '\n';
                        rooms[currentRoomId].AddItem(item);
                    }
                    chest.ClearItems();
                }
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
            else if (input <= connectionsCount + chestCount + itemCount)
            {
                int itemIndex = input - connectionsCount - chestCount - 1;
                Item item = rooms[currentRoomId].GetItems()[itemIndex];

                ClearScreen();
                if (diablo.player.AddItem(item))
                {
                    rooms[currentRoomId].RemoveItem(itemIndex);
                    std::cout << "You picked up [" << item.GetName() << "]!" << '\n';
                    std::cout << "Current inventory weight: " << diablo.player.GetTotalWeight() << " / " << diablo.player.GetCarryCapacity() << '\n';
                }
                else
                {
                    std::cout << "The item is too heavy to carry! (Weight: " << item.GetWeight() << ", Carrying: " << diablo.player.GetTotalWeight() << " / " << diablo.player.GetCarryCapacity() << ")" << '\n';
                }
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
            else if (input <= connectionsCount + chestCount + itemCount + spellCount)
            {
                int spellIndex = input - connectionsCount - chestCount - itemCount - 1;
                Spell spell = rooms[currentRoomId].GetSpells()[spellIndex];
                diablo.player.CastSpell(spell);
                rooms[currentRoomId].RemoveSpell(spellIndex);

                ClearScreen();
                std::cout << "You read the spell [" << spell.GetName() << "]!" << '\n';
                std::cout << "It is now active for " << spell.GetDuration() << " turns." << '\n';
                Pause();
                doors[currentRoomId].OpenDoor(diablo, rooms[currentRoomId]);
            }
        }
    }
}

int main()
{
    Diablo diablo = {};
    bool running = true;
    
    while (running)
    {
        ShowMainMenu();
        int menuChoice;
        ForceInput(menuChoice, diablo, 1, 3);
        
        switch (menuChoice)
        {
        case 1:
            PlayGame(diablo);
            break;
        case 2:
            ShowCheatsMenu(diablo);
            break;
        case 3:
            running = false;
            break;
        }
    }
    
    return 0;
}