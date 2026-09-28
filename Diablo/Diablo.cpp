#include "Door.h"
#include "Room.h"
#include "Utilities.h"

class Room;
class Door;

int main()
{
    Room entrance = "Entrance";
    Room cathedal = "Cathedral";
    Room armory = "Armory";
    Room cells = "Cells";
    Room kitchen = "Kitchen";
    
    Door outside = Door();
    outside.AddConnection(entrance);
    
    Door entranceDoor = Door();
    entranceDoor.AddConnection(cathedal);

    Door cathedralDoor = Door();
    cathedralDoor.AddConnection(entrance);
    cathedralDoor.AddConnection(armory);
    
    Door armoryDoor = Door();
    armoryDoor.AddConnection(cathedal);
    armoryDoor.AddConnection(kitchen);
    
    Door kitchenDoor = Door();
    kitchenDoor.AddConnection(cells);
    kitchenDoor.AddConnection(armory);
    
    Door cellsDoor = Door();
    cellsDoor.AddConnection(kitchen);
    
    std::vector<Door> doors = {outside, entranceDoor, cathedralDoor, armoryDoor, kitchenDoor, cellsDoor };
    
    entrance.SetDoor(entranceDoor);
    cathedal.SetDoor(cathedralDoor);
    armory.SetDoor(armoryDoor);
    kitchen.SetDoor(kitchenDoor);
    cells.SetDoor(cellsDoor);
    
    Door& currentDoor = outside;
    currentDoor.OpenDoor();
    
    int input = -1;
    bool run = true;
    while (run)
    {
        ForceInput(input, 1, currentDoor.GetConnectionCount());
        
        // Enter the connection
        currentDoor = currentDoor.GetConnection(input - 1)->GetDoor();
        currentDoor.OpenDoor();
    }
    
    Pause();
    return 0;
}