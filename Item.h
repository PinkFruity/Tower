#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Holds all the data for a single Item.
 * Things to note:
   (1) Items DO NOT know where they are. The container holding it (a room, player, or different item) must keep
       track of the item; otherwise, it's lost to the game.
 */
class Item; // To fix the infinite recursion
class Item {
public:
   Item(string n);
   string getName();
   void setDescription(string);
   string getDescription();
   //void setInRoomDescription(string);
   //string getInRoomDescription();
   void setStatus(string);
   string getStatus();
   void setBurden(int);
   int getBurden();
   void setCapacity(int);
   int getCapacity();
   void addItem(Item*);
   void removeItem(Item*);
private:
   string name;
   //string inRoomDescription;
   string description;
   string status;
   int burden;
   int capacity;
   vector<Item*> inventory;
};

#endif
