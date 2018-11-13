#ifndef ROOM_H
#define ROOM_H
class Room;
#include <vector>
#include <string>
#include "Path.h"
#include "Item.h"
#include "Character.h"
using namespace std;

/* Holds all the data for a single room.
   Things to note:
   (1) Rooms only know where they lead; they do not know which other rooms lead into it. In other words,
       Room A may know how to get to Room B, but Room B does not know that Room A leads into it.
   (2) Rooms know which items they hold. Since items do not know where they are located, if an item were
       to magically vanish from a room, it would be lost to the game. (See Item.h.)
 */
class Room {
public:
   Room(string);
   void addPath(string direction, Room* endRoom);
   Path* getPath(string direction);
   void removeBarrier(string direction);
   void setBarrier(string direction, string reason);
   void setDescriptions(string shortDes, string longDes);
   void setDescriptions(string);
   string getShortDescription();
   string getLongDescription();
   string getName();
   void setVisited(bool);
   bool isVisited();
   void addItem(Item*);
   Item* findItem(string item);
   Item* removeItem(string);
   void getAllItems(Character*);
   void displayInventory();
   void displayPaths();
private:
   string name;
   string shortDescription;
   string longDescription;
   bool beenVisited;
   vector<Path*> pathList;
   vector<Item*> inventory;
};

#endif
