#ifndef COMMAND_CENTER_H
#define COMMAND_CENTER_H
class CommandCenter;
#include <string>
#include <iostream>
#include <sstream>
#include "TheGame.h"
#include "Character.h"
#include "ItemManager.h"
using namespace std;

/* The main command parser. Runs various methods based on user inputs, which involves moving player locations,
   rearranging items, affecting player stats, fetching descriptions of items or rooms, etc.
 * Only has access to:
   (1) current main character
   (2) main character's location
   (3) main character's inventory
   (4) anything else main character has access to
 * Does NOT have access to:
   (1) entire item array
   (2) entire map
   (3) other characters beyond those in the same room - yet to be implemented
 */
class CommandCenter {
public:
   CommandCenter(TheGame*);
   bool over();
   void doCommand(string originalCommand);
   void setMainCharacter(Character*);
   bool withParser(string, string&, string&);
private:
   TheGame* bigBoss;
   Character* mainCharacter;
   void normalizer();
   void aliasSwap(string replacement, string toBeCut);
   void deleteWord(string);
   void addTime(int);
   void drop(string item);
   void examine(string item);
   void go(string direction);
   void help();
   void lock(string);
   void look();
   void stats();
   void take(string item);
   void unlock(string);
      KeyLockPair* findPair(string);
      bool isLocked(Item*);
      bool keyFitsLock(string key, string lock);
   string userCommand;
};

#endif
