#include "CommandCenter.h"
//#include "CommandUnlock.cpp"

CommandCenter::CommandCenter(TheGame* b) : bigBoss(b) {}
bool CommandCenter::over() {
   return (mainCharacter->getRoom()->getName() == "end");
}

void CommandCenter::setMainCharacter(Character* m) {
   mainCharacter = m;
}

void CommandCenter::doCommand(string originalCommand) {
   userCommand = originalCommand;
   normalizer();
   stringstream commandToParse(userCommand);
   string firstWord;
   commandToParse >> firstWord;
   commandToParse.ignore();

   /* This is where the list of commands begins*/
   if (firstWord == "") {}
   else if (firstWord == "drop") {
      string itemName;
      getline(commandToParse, itemName);
      drop(itemName);
   }
   else if (firstWord == "examine") {
      string item;
      getline(commandToParse, item);
      examine(item);
   }
   else if (firstWord == "go") {
      string direction;
      //commandToParse.ignore();
      getline(commandToParse, direction);
      go(direction);
   }
   else if (firstWord == "help") {
      help();
   }
   else if (firstWord == "lock") {
      string itemToUnlock;
      getline(commandToParse, itemToUnlock);
      lock(itemToUnlock);
   }
   else if (firstWord == "look") {
      look();
   }
   else if (firstWord == "stats") {
      stats();
   }
   else if (firstWord == "take") {
      string itemName;
      getline(commandToParse, itemName);
      take(itemName);
   }
   else if (firstWord == "unlock") {
      string itemToUnlock;
      getline(commandToParse, itemToUnlock);
      unlock(itemToUnlock);
   }
   else if (firstWord == "quit") {
      cout << "Are you sure you want to quit? Progress will not be saved. [Y]/[N]" << endl;
      string input;
      cin >> input;
      cin.ignore();
      if (input == "y" || input == "Y" || input == "yes")
         exit(1);
   }
   else if (firstWord == "kill") {
      string amount;
      getline(commandToParse, amount);
      mainCharacter->addHealth(-stoi(amount));
   }
   else if (firstWord == "addtime") {
      string amount;
      getline(commandToParse, amount);
      addTime(stoi(amount));
   }
   else {
      std::cout << "\"" << originalCommand << "\" is not a valid command." << std::endl;
   }
   std::cout << std::endl;
   std::cout << "-> ";
   return;
};

/* Takes the user input string and
   (1) strips white space
   (2) lowercases every letter
   (3) swaps out common synonyms for their correct word, A.K.A, swaps "pick up" for "take."
 * Replaces COMMANDS and ITEM NAMES
   COMMAND ALIASES:
   drop - N/A
   examine - N/A
   go - walk
   inventory - N/A
   look - N/A
   take - pick up, grab
   use - N/A
   ITEM ALIASES:
   N/A
 */
void CommandCenter::normalizer() {
   /* Stripping whitespace from beginning */
   while (userCommand.size() && userCommand[0] == ' ')
      userCommand.erase(userCommand.begin());

   /* Stripping whitespace from end */
   while (userCommand.size() && userCommand[userCommand.size() - 1] == ' ')
      userCommand.erase(userCommand.begin() + userCommand.size() - 1);

   /* Deleting multiple spaces in a row while lowercasing everything */
   for (int i = 0; i < userCommand.size(); i++) {
      int j = i + 1;
      while (userCommand[i] == ' ' && j < userCommand.size() && userCommand[j] == ' ') {
         userCommand.erase(userCommand.begin() + j);
      }
      userCommand[i] = tolower(userCommand[i]);
   }

   //cout << "HERE IS THE NEW STRING: \"" + userCommand + "\"" << endl << endl;

   /* Replacing common command aliases, where the real command comes first, followed by its alias */
   aliasSwap("take", "pick up");
   aliasSwap("take", "grab");
   aliasSwap("take", "get");
   aliasSwap("go", "walk");

   deleteWord("the");
   deleteWord("a");
   deleteWord("an");
   deleteWord(".");
   return;
}

/* Takes two strings: (1) the command that SHOULD be used, (2) the alias that the user used instead */
void CommandCenter::aliasSwap(string replacement, string toBeCut) {
   int index = userCommand.find(toBeCut);
   if (index != string::npos)
      userCommand.replace(index, toBeCut.size(), replacement);
   return;
}

void CommandCenter::deleteWord(string toDelete) {
   int index = 0;
   while ((index = userCommand.find(" " + toDelete + " ", index)) != string::npos) {
       userCommand.erase(index, toDelete.size() + 1);
   }
   return;
}

bool CommandCenter::withParser(string fullCommand, string& leftSide, string& rightSide) {
   int wIndex = fullCommand.find("with");
   if (wIndex == string::npos)
      return false;
   leftSide = fullCommand.substr(0, wIndex - 1);
   rightSide = fullCommand.substr(wIndex + 5);
   return true;
}

void CommandCenter::addTime(int toAdd) {
   bigBoss->getClock()->addTime(toAdd);
   return;
}

void CommandCenter::drop(string itemName) {
   Item* toDrop = mainCharacter->removeItem(itemName);
   if (toDrop) {
      mainCharacter->getRoom()->addItem(toDrop);
      std::cout << "You dropped the " + itemName << std::endl;
   }
   else
      std::cout << "You do not have a " + itemName + " in your inventory." << std::endl;
   return;
}

void CommandCenter::examine(string item) {
   Item* toFind = mainCharacter->findItem(item);
   if (toFind)
      std::cout << toFind->getDescription() << endl;
   else
      std::cout << "You do not have the " << item << " in your inventory." << endl;
}

void CommandCenter::go(string direction) {
   Room* current = mainCharacter->getRoom();
   if (!current)
      std::cout << "Character has no location. BROKEN. Lost to darkness." << std::endl;
   else {
      Path* toGo = current->getPath(direction);
      if (toGo) {
         if (toGo->isAccessible()) {
            mainCharacter->setLocation(toGo->getDestination());
            if (toGo->getDestination()->isVisited())
               std::cout << toGo->getDestination()->getShortDescription() << std::endl;
            else {
               std::cout << toGo->getDestination()->getLongDescription() << std::endl;
               toGo->getDestination()->setVisited(true);
            }
            mainCharacter->getRoom()->displayInventory();
            mainCharacter->getRoom()->displayPaths();
         }
         else
            std::cout << "You cannot go " + direction + ". " + toGo->getBarrier() << std::endl;
      }
      else std::cout << "You cannot go " + direction + ". " << std::endl;
   }
   return;
}

void CommandCenter::help() {
   cout << "***List of commands (some may be hidden):\n" <<
      "\tdrop (item) - removes an item from inventory\n" <<
      "\texamine (item) - gives a description of the item\n" <<
      "\tgo (direction) - travel in that direction\n" <<
      "\thelp - displays basic information about interacting with the game\n" <<
      "\tlook - gives a longer description of current room\n" <<
      "\tstats - displays basic information about yourself\n"
      "\ttake (item) - adds an item from inventory\n" <<
      "\tunlock (lock) with (key) - unlocks a lock with a key\n" <<
      "\tquit - exits game (progress will be lost)\n\n" <<
      "***A basic command would look like this:\n" <<
      "\tgo south\n" <<
      "\ttake the sword" << endl;
   return;
}

void CommandCenter::lock(string toUnlock) {
   string keyString, lockString;
   Item* key = nullptr;
   KeyLockPair* pair = nullptr;
   if (!withParser(toUnlock, lockString, keyString)) {
      stringstream toParse(toUnlock);
      toParse >> lockString >> keyString;
   }
   if (lockString.empty()) {
      cout << "You cannot lock nothing." << endl;
      return;
   }
   pair = findPair(lockString);
   if (pair) {
      if (isLocked(pair->lock)) {
         cout << "The " << lockString << " is already locked." << endl;
         return;
      }
   }
   else {
      cout << "The " << lockString << " cannot be locked." << endl;
      return;
   }
   if (keyString.empty()) {
      cout << "You have to lock the " << lockString << " with something." << endl;
      return;
   }

   key = mainCharacter->findItem(keyString);
   if (key) {
      if (keyFitsLock(key->getName(), pair->lock->getName())) {
         pair->lock->setStatus("locked");
         pair->path->setBarrier(pair->lockMessage);
         cout << "You locked the " << lockString << "." << endl;
      }
      else
         cout << "You can't use the " << keyString << " to lock the " << lockString << "." << endl;
   }
   else
      cout << "You don't have a " << keyString << " in your inventory." << endl;
   return;
}

void CommandCenter::look() {
      std::cout << mainCharacter->getRoom()->getLongDescription() << std::endl;
      mainCharacter->getRoom()->displayInventory();
      mainCharacter->getRoom()->displayPaths();
      return;
}

void CommandCenter::stats() {
   std::cout << "Health: " << mainCharacter->getHealth() << "/" << mainCharacter->getMaxHealth() << endl;
   std::cout << "Time: " << bigBoss->getClock()->getTime() << endl;
   mainCharacter->displayInventory();
   return;
}

void CommandCenter::take(string itemName) {
   Item* itemToAdd = mainCharacter->getRoom()->removeItem(itemName);
   if (itemToAdd) {
      mainCharacter->addItem(itemToAdd);
      std::cout << "Added " + itemName + " to inventory." << std::endl;
   }
   else
      std::cout << "You cannot find a " + itemName + " here." << std::endl;
   return;
}
