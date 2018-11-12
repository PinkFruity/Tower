#ifndef THE_GAME_H
#define THE_GAME_H
class TheGame;
#include <string>
#include "CommandCenter.h"
#include "ItemManager.h"
#include "RoomManager.h"
#include "Character.h"
#include "Clock.h"
using namespace std;

/* The big boss. The supreme overlord. Manager of managers. On construction, it spawns
   all items and rooms and makes user interface possible. Every piece of data needed to run the game is, on
   some level, contained within here. */
class TheGame {
public:
   TheGame();
   Character* getMainCharacter();
   ItemManager* getItems();
   RoomManager* getMap();
   Clock* getClock();
   bool over();
   void doCommand(string);
private:
   void addItemToRoom(string room, string item);
   void addLockToPath(string room, string direction, string key, string lock, string lockMessage, string unlockMessage);
   CommandCenter* commands;
   RoomManager* map;
   ItemManager* items;
   Character* mainCharacter;
   Clock* clock;
};

#endif
