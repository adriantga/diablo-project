#include <cstdlib>

#include "Room.h"


int main()
{
    // [ENTER] Attack
    // [1/2/3] Enter Room
    
    Room testRoom = Room("Entrance");
    Room testRoom2 = Room("Cathedral");
    
    testRoom.AddConnection(testRoom2);
    testRoom2.AddConnection(testRoom);

    system("pause");
    
    return 0;
}
