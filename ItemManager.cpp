#include "ItemManager.h"

ItemManager::ItemManager(TheGame* game) {
   bigBoss = game;

   /* This is where all the items are spawned */
   addItem("door");
   addItem("leaflet");

   addItem("flag 1");
   addItem("flag 2");
   addItem("flag 3");
   addItem("flag 4");
   addItem("flag 5");
   addItem("potion 1");
   addItem("potion 2");
   addItem("potion 3");
   addItem("ice key");
   addItem("note");

   /* Item descriptions */
   setDescriptions("flag 1",
      "There is a flag with a '1' on the floor (flag 1).",
      "Looks like it would be a great place marker.");
   setDescriptions("flag 2",
      "There is a flag with a '2' on the floor (flag 2).",
      "Looks like it would be a great place marker.");
   setDescriptions("flag 3",
      "There is a flag with a '3' on the floor (flag 3).",
      "Looks like it would be a great place marker.");
   setDescriptions("flag 4",
      "There is a flag with a '4' on the floor (flag 4).",
      "Looks like it would be a great place marker.");
   setDescriptions("flag 5",
      "There is a flag with a '5' on the floor (flag 5).",
      "Looks like it would be a great place marker.");
   
   setDescriptions("ice key",
      "A key on the ground glows with a harsh white light that doesn't seem to match the room around it (ice key).",
      "An ancient-looking key. It's ice-cold to the touch, and something tells you it isn't meant to be held.");
   setDescriptions("note",
      "A note lays on the floor (note)",
      "Careful - it has a bite.");
   setDescriptions("potion 1",
      "A small bottle lies on the floor (potion 1).",
      "A minor potion. Drink to restore 20 HP.");
   setDescriptions("potion 2",
      "A small bottle lies on the floor (potion 2).",
      "A minor potion. Drink to restore 20 HP.");
   setDescriptions("potion 3",
      "A small bottle lies on the floor (potion 3).",
      "A medium-sized potion. Drink to restore 50 HP.");

   setDescriptions("leaflet",
      "A small leaflet lays in the middle of the room.",
      "To the adventurer who wishes to traverse the waters above ...\n"
      "Beware.\n"
      "Many people have attempted to cross, and many people have died. If you do not wish to join their ranks, I offer some (often ignored) advice:\n"
      "1. You are given five flags. They are inherently useless. I have been told, however, that they float in water; "
      "and, when DROPPED, they have a remarkable ability to resist any current. They may help you keep your bearings. "
      "(Items remain in the same room they're dropped.)\n"
      "2. You may feel inclined to make a map. Be wary, though, that many currents are one-directional--and a current that begins "
      "north will not always remain so.\n"
      "3. Save your potions. You won't get more.\n"
      "4. Check \"stats\" often.\n"
      "And remember:\n"
      "This dungeon is designed to kill you.\n"
      "P.S.--Typing \"n\" instead of \"go north\" can save a lot of time, as can \"get all\" instead of individual items.\n");
   setDescriptions("door",
      "A silver door lies to the north of the room (door).",
      "It bars the way out. A silver-ringed keyhole lies just above the handle.");
}

void ItemManager::addItem(string itemName) {
   if (!findItem(itemName))
      itemList.push_back(new Item(itemName));
   else
      std::cout << itemName << " is already an item in existence." << std::endl;
   return;
}

void ItemManager::setDescriptions(string itemName, string dropped, string examine) {
   Item* item = nullptr;
   item = findItem(itemName);
   if (item) {
      item->setDescriptions(dropped, examine);
   }
   else
      cout << "Tried to set description to an item that doesn't exist." << endl;
   return;
}

void ItemManager::setDescriptions(string itemName, string input) {
   setDescriptions(itemName, input, input);
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
