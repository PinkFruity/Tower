#include "Room.h"

Room::Room(string n) : name(n), beenVisited(false), shortDescription(n), longDescription(n) {};

void Room::addPath(string direction, Room* endRoom) {
   pathList.push_back(new Path(direction, endRoom));
   return;
}

Path* Room::getPath(string direction) {
   for (int i = 0; i < pathList.size(); i++) {
      if (pathList[i]->getPathName() == direction)
         return pathList[i];
   }
   return nullptr;
}

void Room::removeBarrier(string direction) {
   for (int i = 0; i < pathList.size(); i++) {
      if (pathList[i]->getPathName() == direction) {
         pathList[i]->removeBarrier();
         return;
      }
   }
   cout << "COULD NOT FIND PATH. BUG." << endl;
   return;
}
void Room::setBarrier(string direction, string reason) {
   for (int i = 0; i < pathList.size(); i++) {
      if (pathList[i]->getPathName() == direction) {
         pathList[i]->setBarrier(reason);
         return;
      }
   }
}

void Room::setDescriptions(string shortDes, string longDes) {
   shortDescription = shortDes;
   longDescription = longDes;
   return;
}

void Room::setDescriptions(string description) {
   shortDescription = description;
   longDescription = description;
   return;
}

string Room::getShortDescription() {
   return shortDescription;
}
string Room::getLongDescription() {
   return longDescription;
}

string Room::getName() {
   return name;
}

void Room::setVisited(bool currentVisited) {
   beenVisited = currentVisited;
   return;
}

bool Room::isVisited() {
   return beenVisited;
}

void Room::addItem(Item* itemToAdd) {
   inventory.push_back(itemToAdd);
}

Item* Room::findItem(string itemName) {
   Item* returnItem = nullptr;
   for (int i = 0; !returnItem && i < inventory.size(); i++) {
      if (inventory[i]->getName() == itemName)
         returnItem = inventory[i];
   }
   return returnItem;
}

Item* Room::removeItem(string toBeRemoved) {
   Item* returnItem = nullptr;
   for (int i = 0; !returnItem && i < inventory.size(); i++) {
      if (inventory[i]->getName() == toBeRemoved) {
         returnItem = inventory[i];
         inventory.erase(inventory.begin() + i);
      }
   }
   //std::cout << "Could not remove item." << std::endl;
   return returnItem;
}

void Room::getAllItems(Character* mc) {
   while (inventory.size()) {
      mc->addItem(inventory[0]);
      inventory.erase(inventory.begin());
   }
   return;
}

void Room::displayInventory() {
   for (int i = 0; i < inventory.size(); i++) { // XXX: Fix the sketchy item display?
      cout << inventory[i]->getDroppedDescription() << endl;
   }
   /*
   if (inventory.size()) {
      std::cout << "There is a ";
      for (int i = 0; i + 2 < inventory.size(); i++) {
         std::cout << inventory[i]->getName() << ", a ";
      }
      if (inventory.size() == 1)
         std::cout << inventory[0]->getName();
      else {
         std::cout << inventory[inventory.size() - 2]->getName() << " and a " << inventory[inventory.size() - 1]->getName();
      }
      std::cout << " on the floor." << std::endl;
   }*/
   return;
}

void Room::displayPaths() {
   if (pathList.size()) {
      cout << "Directions to go:" << endl;
      for (int i = 0; i < pathList.size(); i++) {
         cout << "+ " << pathList[i]->getPathName() << endl;
      }
   }
   return;
}
