#pragma once
#include <vector>

class Door;

class Room
{
    std::vector<Door*> myDoors = {};
    std::vector<const char*> myDirections = { "N", "E", "S", "W" };
    
    int myDoorCount = 0;
    int myMinDoorCount = 2;
    int myMaxDoorCount = 4;
    int myCachedInput = -1;
    int myPreviousInput = -1;
    
    bool myIsFirstRoom = false;
    
    void GenerateDoors(int aDoorCount);
    const char* GetDirection(int aDoorIndex) const { return myDirections[aDoorIndex]; }
    void OpenDoor(int aDoorIndex);
    void BroadcastDoors();
    
public:
    Room(bool myIsFirstRoom = false);
    Room(int aDoorCount, bool myIsFirstRoom = false);
    const char* myDirection = nullptr;
    
    bool IsOppositeDirection(int i) const;
};