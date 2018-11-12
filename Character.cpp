#include "Character.h"

Character::Character(TheGame* game) {
   bigBoss = game;
   name = "";
   location = nullptr;
   health = 100;
   maxHP = 100;
}

void Character::setName(string userName) {
   name = userName;
   return;
}

void Character::setLocation(Room* r) {
   location = r;
   return;
}

Room* Character::getRoom() {
   return location;
}

void Character::addItem(Item* toBeAdded) {
   inventory.push_back(toBeAdded);
   return;
}

Item* Character::findItem(string itemName) {
   Item* foundItem = nullptr;
   for (int i = 0; !foundItem && i < inventory.size(); i++) {
      if (inventory[i]->getName() == itemName) {
         foundItem = inventory[i];
      }
   }
   return foundItem;
}
Item* Character::removeItem(string itemName) {
   Item* foundItem = nullptr;
   for (int i = 0; !foundItem && i < inventory.size(); i++) {
      if (inventory[i]->getName() == itemName) {
         foundItem = inventory[i];
         inventory.erase(inventory.begin() + i);
      }
   }
   return foundItem;
}

/*void Character::removeItem(string toBeRemoved) {
   return;
}*/

void Character::displayInventory() {
   if (inventory.size()) {
      std::cout << "Current inventory:" << std::endl;
      for (int i = 0; i < inventory.size(); i++) {
         std::cout << "+ " << inventory[i]->getName() << std::endl;
      }
   }
   else
      std::cout << "You have nothing in your inventory." << std::endl;
   return;
}

int Character::getHealth() {
   return health;
}

int Character::getMaxHealth() {
   return maxHP;
}

void Character::addHealth(int amount) {
   if (health + amount <= 0) {
      while (inventory.size()) {
         location->addItem(inventory[0]);
         inventory.erase(inventory.begin());
      }
      std::cout << "Your vision fades. The world blurs. You wake to find yourself in the home room of the tower." << std::endl;
      location = bigBoss->getMap()->getSpawnLocation();
      health = maxHP;
      return;
   }
   else if (health > 10 && health + amount <= 10)
      std::cout << "You feel close to death." << std::endl;
   else if (health > 25 && health + amount <= 25)
      std::cout << "You feel faint." << std::endl;
   else if (health > 50 && health + amount <= 50)
      std::cout << "You feel weak." << std::endl;
   (amount + health > maxHP) ? health = maxHP : health += amount;
   return;
}
