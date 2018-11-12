#include "ItemManager.h"

ItemManager::ItemManager(TheGame* game) {
   bigBoss = game;
   /* This is where all the items are spawned */
   addItem("red_orb");
   setDescription("red_orb", "Looks like it would be a great place marker.");
   addItem("blue_orb");
   setDescription("blue_orb", "Looks like it would be a great place marker.");
   addItem("green_orb");
   setDescription("green_orb", "Looks like it would be a great place marker.");
   addItem("yellow_orb");
   setDescription("yellow_orb", "Looks like it would be a great place marker.");
   addItem("purple_orb");
   setDescription("purple_orb", "Looks like it would be a great place marker.");
   addItem("ice_key");
   addItem("home_door");

   /* This is where item relationships are linked, e.g., key/locks */
}

void ItemManager::addItem(string itemName) {
   if (!findItem(itemName))
      itemList.push_back(new Item(itemName));
   else
      std::cout << itemName << " is already an item in existence." << std::endl;
   return;
}

void ItemManager::setDescription(string itemName, string description) {
   Item* item = nullptr;
   item = findItem(itemName);
   if (item) {
      item->setDescription(description);
   }
   else
      cout << "Tried to set description to an item that doesn't exist." << endl;
   return;
}

Item* ItemManager::findItem(string itemName) {
   Item* foundItem = nullptr;
   for (int i = 0; !foundItem && i < itemList.size(); i++) {
      if (itemList[i]->getName() == itemName) {
         foundItem = itemList[i];
      }
   }
   return foundItem;
}

void ItemManager::addKeyLockPair(Path* pathToLock, Item* key, Item* lock, string lockMessage, string unlockMessage) {
   keyLockList.push_back(new KeyLockPair(pathToLock, key, lock, lockMessage, unlockMessage));
   return;
}

/*
void ItemManager::addKeyLockPair(string key, string lock) {
   Item* keyPtr;
   Item* lockPtr;
   keyPtr = findItem(key);
   lockPtr = findItem(lock);
   if (keyPtr && lockPtr)
      keyLockList.push_back(new KeyLockPair(keyPtr, lockPtr));
   else {
      cout << "BUG. Tried to add key/lock pair but failed. (Probably tried to add an item that didn't exist.)" << endl;
      cout << "Key: " << key << "\t Lock: " << lock << endl;
   }
   return;
}*/

bool ItemManager::isKeyLockPair(string key, string lock) {
   for (int i = 0; i < keyLockList.size(); i++) {
      if (keyLockList[i]->key->getName() == key && keyLockList[i]->lock->getName() == lock)
         return true;
   }
   return false;
}

Item* ItemManager::findKey(string key) {
   Item* keyPtr = nullptr;
   for (int i = 0; i < keyLockList.size(); i++) {
      if (keyLockList[i]->key->getName() == key)
         keyPtr = keyLockList[i]->key;
   }
   return keyPtr;
}

KeyLockPair* ItemManager::findPair(string pair) {
   KeyLockPair* pairPtr = nullptr;
   for (int i = 0; i < keyLockList.size(); i++) {
      if (keyLockList[i]->lock->getName() == pair || keyLockList[i]->key->getName() == pair)
         pairPtr = keyLockList[i];
   }
   return pairPtr;
}
