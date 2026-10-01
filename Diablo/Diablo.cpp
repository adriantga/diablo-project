#include <cstdlib>

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
    
    CharacterFactory::CreateEnemy("Skeleton", 1, 1, 1, armory);
    CharacterFactory::CreateEnemy("Undead Warrior", 1, 1, 2, armory);
    
    armory.AddConnection(cathedral);
    armory.AddConnection(kitchen);
    
    kitchen.AddConnection(armory);
    kitchen.AddConnection(cells);
    
    cells.AddConnection(kitchen);
    
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
    
    doors[currentRoomId].OpenDoor(diablo);
    
    bool shouldRun = true;
    int input;
    
    while (shouldRun)
    {
        if (rooms[currentRoomId].IsRoomCleared())
        {
            if (!doors[currentRoomId].IsLocked())
            {
                int connectionsCount = rooms[currentRoomId].GetConnectionsCount();
                int statsOption = connectionsCount + 1;
                
                ForceInput(input, diablo, 1, statsOption);

                if (input == statsOption)
                {
                    ClearScreen();
                    ShowStats(diablo);
                    Pause();
                    doors[currentRoomId].OpenDoor(diablo);
                }
                else
                {
                    int finalInput = input - 1;
                    int nextRoomId = rooms[currentRoomId].GetConnection(finalInput).GetId();
                    previousRoomId = currentRoomId;
                    currentRoomId = nextRoomId;
                    doors[currentRoomId].OpenDoor(diablo);
                }
            }
            else
            {
                constexpr int MAX_OPTIONS = 4;
                ForceInput(input, diablo, 1, MAX_OPTIONS);

                switch (input)
                {
                case 1:
                    if (diablo.player.GetStrength() >= doors[currentRoomId].GetRequiredStrength())
                    {
                        doors[currentRoomId].SetLocked(false);
                        doors[currentRoomId].OpenDoor(diablo);
                    }
                    else
                    {
                        ClearScreen();
                        std::cout << "You tried to brute-force the door, however, you failed!\n";
                        Pause();
                        currentRoomId = previousRoomId;
                        doors[currentRoomId].OpenDoor(diablo);
                    }
                    break;
                case 2:
                    if (diablo.player.GetAgility() >= doors[currentRoomId].GetRequiredAgility())
                    {
                        doors[currentRoomId].SetLocked(false);
                        doors[currentRoomId].OpenDoor(diablo);
                    }
                    else
                    {
                        ClearScreen();
                        std::cout << "You accidentally broke the lockpick!\n";
                        Pause();
                        currentRoomId = previousRoomId;
                        doors[currentRoomId].OpenDoor(diablo);
                    }
                    break;
                case 3:
                    currentRoomId = previousRoomId;
                    doors[currentRoomId].OpenDoor(diablo);
                    break;
                case 4:
                    ClearScreen();
                    ShowStats(diablo);
                    Pause();
                    doors[currentRoomId].OpenDoor(diablo);
                    break;
                }
            }
        }
        else
        {
            int enemyCount = rooms[currentRoomId].GetEnemyCount();
            int statsOption = enemyCount + 1;
            
            ForceInput(input, diablo, 1, statsOption);

            if (input == statsOption)
            {
                ClearScreen();
                ShowStats(diablo);
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
                    doors[currentRoomId].OpenDoor(diablo);
                }
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