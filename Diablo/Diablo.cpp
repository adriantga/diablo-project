#include <cstdlib>
#include <iostream>

#include "Room.h"
#include "Utilities.h"


int main()
{
    // [ENTER] Attack
    // [1/2/3] Enter Room
    
    Room entranceRoom = "Entrance";
    Room cathedralRoom = "Cathedral";
    Room cellsRoom = "Cells";
    Room armoryRoom = "Armory";
    Room kitchenRoom = "Kitchen";
    
    entranceRoom.AddConnection(cathedralRoom);
    cathedralRoom.AddConnections({entranceRoom, armoryRoom});
    armoryRoom.AddConnections({cathedralRoom, kitchenRoom});
    kitchenRoom.AddConnections({cellsRoom, armoryRoom});
    cellsRoom.AddConnection(kitchenRoom);
    
    std::vector<Room> rooms = {entranceRoom, cathedralRoom, armoryRoom, kitchenRoom, cellsRoom};
    
    // Use a pointer here instead later
    Room currentRoom = entranceRoom;
    
    currentRoom.ShowConnections();
    
    int input;

    while (true)
    {
        ForceInput(input, 0, currentRoom.GetConnectionCount());
        
        if (input > 0 && input <= currentRoom.GetConnectionCount())
        {
            
            
            Room nextRoom = currentRoom.GetConnection(input - 1);
            
            // This should have the connections already but it doesn't...
            
            currentRoom.SetConnections(nextRoom.GetConnections());
            currentRoom = nextRoom;
            
            currentRoom.ShowConnections();
        }
    }
    
}
