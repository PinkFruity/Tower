#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H
class ItemManager;
struct KeyLockPair;
#include <vector>
#include "Item.h"
#include "TheGame.h"
#include "Path.h"
using namespace std;

struct KeyLockPair {
   KeyLockPair(Path* p, Item* k, Item* l, string locked, string unlocked) : path(p), key(k), lock(l), lockMessage(locked), unlockMessage(unlocked) {
      lock->setStatus("locked");
      path->setBarrier(lockMessage);
   };
   Item* key;
   Item* lock;
   Path* path;
   string lockMessage;
   string unlockMessage;
};

/* Spawns all items, adds descriptions, etc. and stores them in a vector. */
class ItemManager {
public:
   ItemManager(TheGame*);
   void addItem(string itemName);
   void setDescription(string itemName, string description);
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
