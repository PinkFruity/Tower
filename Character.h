#ifndef CHARACTER_H
#define CHARACTER_H
class Character;
#include <iostream>
#include <string>
#include "TheGame.h"
#include "Item.h"
#include "Room.h"
using namespace std;

/* Holds all data for a single character. There is currently only one character, the main player.
 * Things to note:
   None yet.
 */
class Character {
public:
   Character(TheGame*);
   void setName(string);
   void setLocation(Room*);
   Room* getRoom();
   void addItem(Item*);
   Item* findItem(string);
   Item* removeItem(string);
   //void removeItem(string);
   void displayInventory();
   void addHealth(int);
   int getHealth();
   int getMaxHealth();
private:
   TheGame* bigBoss;
   string name;
   vector<Item*> inventory;
   Room* location;
   int health;
   int maxHP;
};

#endif
