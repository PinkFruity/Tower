#include "CommandCenter.h"

void CommandCenter::unlock(string toUnlock) {
   string keyString, lockString;
   Item* key = nullptr;
   KeyLockPair* pair = nullptr;
   if (!withParser(toUnlock, lockString, keyString)) {
      stringstream toParse(toUnlock);
      toParse >> lockString >> keyString;
   }
   if (lockString.empty()) {
      cout << "You cannot unlock nothing." << endl;
      return;
   }
   pair = findPair(lockString);
   if (pair) {
      if (!isLocked(pair->lock)) {
         cout << "The " << lockString << " is already unlocked." << endl;
         return;
      }
   }
   else {
      cout << "The " << lockString << " cannot be unlocked." << endl;
      return;
   }
   if (keyString.empty()) {
      cout << "You have to unlock the " << lockString << " with something." << endl;
      return;
   }

   key = mainCharacter->findItem(keyString);
   if (key) {
      if (keyFitsLock(key->getName(), pair->lock->getName())) {
         pair->lock->setStatus("unlocked");
         pair->path->removeBarrier();
         cout << pair->unlockMessage << endl;
      }
      else
         cout << "You can't use the " << keyString << " to unlock the " << lockString << "." << endl;
   }
   else
      cout << "You don't have a " << keyString << " in your inventory." << endl;
   return;
}

KeyLockPair* CommandCenter::findPair(string lockString) {
   KeyLockPair* lockRet = nullptr;
   Item* lock = mainCharacter->getRoom()->findItem(lockString);
   if (lock == nullptr)
      lock = mainCharacter->findItem(lockString);
   if (lock) {
      lockRet = bigBoss->getItems()->findPair(lock->getName());
   }
   return lockRet;
}

bool CommandCenter::isLocked(Item* lock) {
   if (lock->getStatus() == "locked")
      return true;
   else if (lock->getStatus() == "unlocked")
      return false;
   else
      std::cout << "BUG: isLocked() was executed on an item that doesn't have lock/unlockable status.";
   return false;
}

bool CommandCenter::keyFitsLock(string key, string lock) {
   return bigBoss->getItems()->isKeyLockPair(key, lock);
}
