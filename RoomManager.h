#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H
class RoomManager;
#include <vector>
#include <iostream>
#include "Room.h"
#include "TheGame.h"

/* Spawns all rooms, sets descriptions, and links the rooms together (A.K.A. spawns paths between them). */
class RoomManager {
public:
   RoomManager(TheGame*);
   void addRoom(string roomName);
   Room* findRoom(string);
   void addPath(string beginningRoom, string direction, string endRoom);
   void setDescriptions(string roomName, string shortDescription, string longDescription);
   void setDescriptions(string roomName, string description);
   Room* getSpawnLocation();
private:
   TheGame* bigBoss;
   vector<Room*> roomList;
};
#endif
