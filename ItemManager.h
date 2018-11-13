#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H
class ItemManager;
struct KeyLockPair;
#include <vector>
#include "Item.h"
#include "TheGame.h"
#include "Path.h"
#include "KeyLockPair.h"
using namespace std;

/* Spawns all items, adds descriptions, etc. and stores them in a vector. */
class ItemManager {
public:
   ItemManager(TheGame*);
   void addItem(string itemName);
   void setDescriptions(string itemName, string dropped, string description);
   void setDescriptions(string itemName, string description);
   Item* findItem(string itemName);
   void addKeyLockPair(Path* pathToLock, Item* key, Item* lock, string lockMessage, string unlockMessage);
   bool isKeyLockPair(string key, string lock);
   Item* findKey(string);
   KeyLockPair* findPair(string);
private:
   TheGame* bigBoss;
   vector<Item*> itemList;
   vector<KeyLockPair*> keyLockList;
};

#endif
