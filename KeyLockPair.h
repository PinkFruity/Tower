#ifndef KEY_LOCK_PAIR_H
#define KEY_LOCK_PAIR_H
struct KeyLockPair;
#include <string>
#include "Item.h"
#include "Path.h"

struct KeyLockPair {
   KeyLockPair(Path* p, Item* k, Item* l, string locked, string unlocked);
   Item* key;
   Item* lock;
   Path* path;
   string lockMessage;
   string unlockMessage;
};

#endif
