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
    
    CharacterFactory::CreateEnemy("Test", 1, 1, 1, cathedral);
    
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
        ForceInput(input, 1, currentRoom.GetConnectionsCount());
        int finalInput = input - 1;
        if (currentRoom.IsRoomCleared())
        {
            currentRoom = rooms[currentRoom.GetConnection(finalInput).GetId()];
            currentDoor = doors[currentRoom.GetId()];
            currentDoor.OpenDoor(diablo);
        }
    }
    
    system("pause");
    return 0;
}