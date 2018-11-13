#include "KeyLockPair.h"

KeyLockPair::KeyLockPair(Path* p, Item* k, Item* l, string locked, string unlocked) : path(p), key(k), lock(l), lockMessage(locked), unlockMessage(unlocked) {
   lock->setStatus("locked");
   path->setBarrier(lockMessage);
};
