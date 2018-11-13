#include "Item.h"

Item::Item(string n) : name(n) {};

string Item::getName() {
   return name;
}

void Item::setDescriptions(string dropped, string examine) {
   droppedDescription = dropped;
   description = examine;
}

void Item::setDescriptions(string input) {
   setDescriptions(input, input);
}

string Item::getDroppedDescription() {
   return droppedDescription;
}

std::string Item::getDescription() {
   return description;
}

void Item::setStatus(string input) {
   status = input;
}

string Item::getStatus() {
   return status;
}

void Item::setBurden(int num) {
   burden = num;
}

int Item::getBurden() {
   return burden;
}

void Item::setCapacity(int num) {
   capacity = num;
}

int Item::getCapacity() {
   return capacity;
}

void Item::addItem(Item* toAdd) { /*
   bool foundItem = false;
   for (int i = 0; i < inventory.size() && !foundItem; i++) {
      if (inventory[i]->name == toAdd->name)
         foundItem = true;
   }
   if (foundItem)
      std::cout << name << " already has a " << toAdd->name << std::endl;
   else {
      inventory.push_back(toAdd);
      std::cout << "Added " << toAdd->name << " to " << name << std::endl;
   }*/
   return;
}

void Item::removeItem(Item*) { /*
   bool foundItem = false;
   for (int i = 0; i < inventory.size() && !foundItem; i++) {
      if (inventory[i]->name == toAdd->name)
         foundItem = true;
   }
   if (foundItem)
      std::cout << name << " already has a " << toAdd->name << std::endl;
   else {
      inventory.push_back(toAdd);
      std::cout << "Added " << toAdd->name << " to " << name << std::endl;
   }*/
   return;
}
