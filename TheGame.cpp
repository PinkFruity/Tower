#include "TheGame.h"

TheGame::TheGame() {
   commands = new CommandCenter(this);
   map = new RoomManager(this);
   items = new ItemManager(this);
   clock = new Clock(this);
   /* Setting main character to the initial room and setting flags in that room (like hasBeenVisited) */
   mainCharacter = new Character(this);
   mainCharacter->setLocation(map->getSpawnLocation());
   commands->setMainCharacter(mainCharacter);
   map->getSpawnLocation()->setVisited(true);
   clock->setMainCharacter(mainCharacter);

   /* Adding items to rooms */
   addItemToRoom("home", "home_door");

   // Adding items to night maze dungeon
   addItemToRoom("night_maze_landing", "red_orb");
   addItemToRoom("night_maze_landing", "blue_orb");
   addItemToRoom("night_maze_landing", "green_orb");
   addItemToRoom("night_maze_landing", "yellow_orb");
   addItemToRoom("night_maze_landing", "purple_orb");
   addItemToRoom("night_maze_pedestal", "ice_key");


   /* Adding locks to paths */
   addLockToPath("home", "north", "ice_key", "home_door", "The door is locked with a silver-ringed keyhole.", "You hear a soft click.");

   /* Printing room description */
   cout << "***Try typing \"help\" to get you started." << endl << endl << endl;
   commands->doCommand("look");
}
Character* TheGame::getMainCharacter() {
   return mainCharacter;
}

ItemManager* TheGame::getItems() {
   return items;
}

RoomManager* TheGame::getMap() {
   return map;
}

Clock* TheGame::getClock() {
   return clock;
}

bool TheGame::over() {
   return commands->over();
}

void TheGame::doCommand(string command) {
   commands->doCommand(command);
}

void TheGame::addItemToRoom(string room, string item) {
   Item* itemToAdd = items->findItem(item);
   Room* destination = map->findRoom(room);
   if (itemToAdd && destination) {
      destination->addItem(itemToAdd);
   }
   else {
      std::cout << "COULD NOT ADD " + item + " TO " + room + ". Please fix!" << std::endl;
   }
   return;
}

void TheGame::addLockToPath(string room, string direction, string key, string lock, string lockMessage, string unlockMessage) {
   Room* pathLocation = nullptr;
   Path* path = nullptr;
   Item* pairKey = nullptr;
   Item* pairLock = nullptr;
   pathLocation = map->findRoom(room);
   if (pathLocation) {
      path = pathLocation->getPath(direction);
      if (path) {
         pairKey = items->findItem(key);
         if (pairKey) {
            pairLock = items->findItem(lock);
            if (pairLock)
               items->addKeyLockPair(path, pairKey, pairLock, lockMessage, unlockMessage);
            else
               cout << "addLockToPath() failed. Could not find lock (" << lock << ") to add." << endl;
         }
         else
            cout << "addLockToPath() failed. Could not find key (" << key << ") to add." << endl;
      }
      else
         cout << "addLockToPath() failed. Could not find path (" << direction << ") within room (" << room << ")." << endl;
   }
   else
      cout << "addLockToPath() failed. Could not find room (" << room << ")." << endl;
   return;
}

/*
void TheGame::addLockToPath(string room, string direction, string lock, string errorMessage) {
   KeyLockPair* locker = nullptr;
   locker = items->findPair(lock);
   Room* tempRoom = nullptr;
   tempRoom = map->findRoom(room);
   Path* path = nullptr;
   if (tempRoom)
      path = tempRoom->getPath(direction);
   else {
      cout << "BUG. Could not find room to add path to. ROOM: "<< room << endl;
      return;
   }
   if (path)
      if (locker) {
         locker->path = path;
         locker->lockMessage = errorMessage;
         path->setBarrier(errorMessage);
      }
      else {
         cout << "BUG. Tried to add a non-existent lock to a path. LOCK: " << lock << std::endl;
         return;
      }
   else {
      cout << "BUG. Could not find the path inside room." << endl;
   }
   return;
}
*/
