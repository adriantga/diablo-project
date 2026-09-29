#include <cstdlib>

#include "BattleController.h"
#include "Door.h"
#include "Room.h"
#include "Utilities.h"

int main()
{
    Diablo diablo = {};
    
    Room entrance = "Entrance";
    entrance.SetId(0);
    
    Room cathedral = "Cathedral";
    cathedral.SetId(1);
    
    Room armory = "Armory";
    armory.SetId(2);
    
    Room kitchen = "Kitchen";
    kitchen.SetId(3);
    
    Room cells = "Cells";
    cells.SetId(4);
    
    entrance.AddConnection(cathedral);
    
    cathedral.AddConnection(entrance);
    cathedral.AddConnection(armory);
    
    CharacterFactory::CreateEnemy("Skeleton", 1, 1, 1, cathedral);
    CharacterFactory::CreateEnemy("Undead Warrior", 1, 1, 2, cathedral);
    
    armory.AddConnection(cathedral);
    armory.AddConnection(kitchen);
    
    kitchen.AddConnection(armory);
    kitchen.AddConnection(cells);
    
    cells.AddConnection(kitchen);
    
    Door entranceDoor = entrance;
    Door cathedralDoor = cathedral;
    Door armoryDoor = armory;
    Door kitchenDoor = kitchen;
    Door cellsDoor = cells;
    
    std::vector<Room> rooms = {entrance, cathedral, armory, kitchen, cells};
    std::vector<Door> doors = {entranceDoor, cathedralDoor, armoryDoor, kitchenDoor, cellsDoor};
    
    Room currentRoom = entrance;
    
    Player player = CharacterFactory::CreatePlayer(5, 4, 6);
    diablo.player = player;
    
    
    Pause();
    
    Door currentDoor = doors[currentRoom.GetId()];
    currentDoor.OpenDoor(diablo);
    
    bool shouldRun = true;
    int input;
    
    while (shouldRun)
    {
        if (currentRoom.IsRoomCleared())
        {
            ForceInput(input, 1, currentRoom.GetConnectionsCount());
            int finalInput = input - 1;
            
            currentRoom = rooms[currentRoom.GetConnection(finalInput).GetId()];
            currentDoor = doors[currentRoom.GetId()];
            currentDoor.OpenDoor(diablo);
        }
        
        // I need to make the code look cleaner later!
        else
        {
            do
            {
                // This code doesn't really work properly. I will need to work on it!
                int enemyCount = currentRoom.GetEnemyCount();
            
                ForceInput(input, 1, enemyCount);
                int finalInput = input - 1;
            
                Enemy chosenEnemy = currentRoom.GetEnemy(finalInput);
                BattleController::Battle(diablo.player, chosenEnemy);
                
                if (!chosenEnemy.IsAlive()) 
                {
                    currentRoom.RemoveEnemy(finalInput);
                }
            
                for (int i = 0; i < enemyCount; i++)
                {
                    Enemy enemy = currentRoom.GetEnemy(i);
                    if (enemy.IsAlive()) diablo.player.TakeDamage(CalculateDamageTaken(player.GetCharacter(), enemy.GetCharacter()));
                }
                
                currentRoom.EnterCombat(diablo);
            } while (!currentRoom.IsRoomCleared());
        }
    }
    
    system("pause");
    return 0;
}