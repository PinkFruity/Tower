#include "RoomManager.h"

RoomManager::RoomManager(TheGame* game) {
   bigBoss = game;
   /* This is where all the rooms are spawned and linked together */

   /* Creating of rooms and their descriptions */
   addRoom("home");
   setDescriptions("home",
      "HOME",
      "You find yourself in a small room. Little catches your attention aside from a BED in the corner, a door to the NORTH, "
      "and a ladder that leads UP to an opening in the ceiling. (I happen to enjoy immense frustration and pain, so I don't mind "
      "ignoring the leaflet on the ground. You might want to choose differently, though.)"
   );
   addRoom("end");
   setDescriptions("end", "Congratulations! You win.\n");

   /* Night dungeon 1 - Water Maze */
   addRoom("night_maze_landing");
   addRoom("maze1");
   addRoom("maze2");
   addRoom("maze3");
   addRoom("maze4");
   addRoom("maze5");
   addRoom("maze6");
   addRoom("maze7");
   addRoom("maze8");
   addRoom("maze9");
   addRoom("maze10");
   addRoom("maze11");
   addRoom("maze12");
   addRoom("maze13");
   addRoom("maze14");
   addRoom("maze15");
   addRoom("maze16");
   addRoom("maze17");
   addRoom("maze18");
   addRoom("maze19");
   addRoom("maze20");
   addRoom("maze21");
   addRoom("maze22");
   addRoom("maze23");
   addRoom("maze24");
   addRoom("maze25");
   addRoom("maze26");
   addRoom("maze27");
   addRoom("maze28");
   addRoom("maze29");
   addRoom("maze30");
   addRoom("maze31");
   addRoom("maze32");
   addRoom("maze33");
   addRoom("maze34");
   addRoom("maze35");
   addRoom("maze36");
   addRoom("maze37");
   addRoom("maze38");
   addRoom("maze39");
   addRoom("maze40");
   addRoom("maze41");
   addRoom("maze42");
   addRoom("maze43");
   addRoom("maze44");
   addRoom("maze45");
   addRoom("maze46");
   addRoom("maze47");
   addRoom("maze48");
   addRoom("maze49");
   addRoom("maze50");
   addRoom("maze51");
   addRoom("maze52");
   addRoom("maze53");
   addRoom("maze54");
   addRoom("maze55");
   addRoom("maze56");
   addRoom("night_maze_pedestal");
   setDescriptions("maze1", "The water pushes and pulls.");
   setDescriptions("maze2", "The water pushes and pulls.");
   setDescriptions("maze3", "The water pushes and pulls.");
   setDescriptions("maze4", "The water pushes and pulls.");
   setDescriptions("maze5", "The water pushes and pulls.");
   setDescriptions("maze6", "The water pushes and pulls.");
   setDescriptions("maze7", "The water pushes and pulls.");
   setDescriptions("maze8", "The water pushes and pulls.");
   setDescriptions("maze9", "The water pushes and pulls.");
   setDescriptions("maze10", "The water pushes and pulls.");
   setDescriptions("maze11", "The water pushes and pulls.");
   setDescriptions("maze12", "The water pushes and pulls.");
   setDescriptions("maze13", "The water pushes and pulls.");
   setDescriptions("maze14", "The water pushes and pulls.");
   setDescriptions("maze15", "The water pushes and pulls.");
   setDescriptions("maze16", "The water pushes and pulls.");
   setDescriptions("maze17", "The water pushes and pulls.");
   setDescriptions("maze18", "The water pushes and pulls.");
   setDescriptions("maze19", "The water pushes and pulls.");
   setDescriptions("maze20", "The water pushes and pulls.");
   setDescriptions("maze21", "The water pushes and pulls.");
   setDescriptions("maze22", "The water pushes and pulls.");
   setDescriptions("maze23", "The water pushes and pulls.");
   setDescriptions("maze24", "The water pushes and pulls.");
   setDescriptions("maze25", "The water pushes and pulls.");
   setDescriptions("maze26", "The water pushes and pulls.");
   setDescriptions("maze27", "The water pushes and pulls.");
   setDescriptions("maze28", "The water pushes and pulls.");
   setDescriptions("maze29", "The water pushes and pulls.");
   setDescriptions("maze30", "The water pushes and pulls.");
   setDescriptions("maze31", "The water pushes and pulls.");
   setDescriptions("maze32", "The water pushes and pulls.");
   setDescriptions("maze33", "The water pushes and pulls.");
   setDescriptions("maze34", "The water pushes and pulls.");
   setDescriptions("maze35", "The water pushes and pulls.");
   setDescriptions("maze36", "The water pushes and pulls.");
   setDescriptions("maze37", "The water pushes and pulls.");
   setDescriptions("maze38", "The water pushes and pulls.");
   setDescriptions("maze39", "The water pushes and pulls.");
   setDescriptions("maze40", "The water pushes and pulls.");
   setDescriptions("maze41", "The water pushes and pulls.");
   setDescriptions("maze42", "The water pushes and pulls.");
   setDescriptions("maze43", "The water pushes and pulls.");
   setDescriptions("maze44", "The water pushes and pulls.");
   setDescriptions("maze45", "The water pushes and pulls.");
   setDescriptions("maze46", "The water pushes and pulls.");
   setDescriptions("maze47", "The water pushes and pulls.");
   setDescriptions("maze48", "The water pushes and pulls.");
   setDescriptions("maze49", "The water pushes and pulls.");
   setDescriptions("maze50", "The water pushes and pulls.");
   setDescriptions("maze51", "The water pushes and pulls.");
   setDescriptions("maze52", "The water pushes and pulls.");
   setDescriptions("maze53", "The water pushes and pulls.");
   setDescriptions("maze53", "The water pushes and pulls.");
   setDescriptions("maze54", "The water pushes and pulls.");
   setDescriptions("maze55", "The water pushes and pulls.");
   setDescriptions("maze56", "The water pushes and pulls.");
   setDescriptions("night_maze_landing",
      "NIGHT DUNGEON - WATER MAZE LANDING",
      "You step onto an island, the doorway to home nothing but a hole in the ground. The room is dimly lit. Water surrounds you, and even "
      "in the semi-darkness, you can see currents that move in strange, unnatural patterns--swift currents. Something tells you "
      "that, were you to step into them, you would be forced to follow whichever direction they led at their mercy.\n"
      "Across the waters to the north lies another island, this one with a pedestal that holds a silver-looking key.\n"
   );
   setDescriptions("night_maze_pedestal",
      "NIGHT DUNGEON - WATER MAZE PEDESTAL",
      "You come across a larger island, barren of everything except for a single, silver-lined pedestal."
   );

   /* Linking of rooms */
   addPath("home", "north", "end");

   // Night maze dungeon
   addPath("home", "up", "night_maze_landing");
   addPath("night_maze_landing", "north", "maze1");
   addPath("maze1", "south", "night_maze_landing");
   addPath("maze1", "west", "maze8");
   addPath("maze1", "north", "maze39");
   addPath("maze2", "northwest", "maze3");
   addPath("maze2", "east", "maze1");
   addPath("maze3", "north", "maze7");
   addPath("maze3", "east", "maze1");
   addPath("maze4", "north", "maze5");
   addPath("maze4", "south", "maze40");
   addPath("maze5", "west", "maze6");
   addPath("maze5", "north", "maze28");
   addPath("maze5", "south", "maze4");
   addPath("maze6", "south", "maze7");
   addPath("maze6", "east", "maze41");
   addPath("maze6", "southeast", "maze29");
   addPath("maze7", "west", "maze8");
   addPath("maze7", "southwest", "maze3");
   addPath("maze8", "north", "maze9");
   addPath("maze8", "east", "maze7");
   addPath("maze9", "east", "maze28");
   addPath("maze9", "north", "night_maze_pedestal");
   addPath("maze10", "north", "maze11");
   addPath("maze10", "west", "maze28");
   addPath("maze10", "south", "maze28");
   addPath("maze11", "north", "maze12");
   addPath("maze11", "south", "maze28");
   addPath("maze12", "north", "maze13");
   addPath("maze12", "south", "maze11");
   addPath("maze13", "south", "maze14");
   addPath("maze13", "east", "maze42");
   addPath("maze14", "southeast", "maze15");
   addPath("maze14", "west", "maze13");
   addPath("maze14", "south", "maze48");
   addPath("maze15", "north", "maze16");
   addPath("maze16", "southwest", "maze17");
   addPath("maze16", "south", "maze46");
   addPath("maze16", "east", "maze44");
   addPath("maze17", "south", "maze18");
   addPath("maze17", "north", "maze48");
   addPath("maze18", "northwest", "maze19");
   addPath("maze19", "northwest", "maze20");
   addPath("maze20", "northwest", "night_maze_pedestal");
   addPath("night_maze_pedestal", "south", "maze6");
   addPath("maze21", "northwest", "maze22");
   addPath("maze21", "north", "maze55");
   addPath("maze21", "east", "maze52");
   addPath("maze22", "north", "maze23");
   addPath("maze23", "east", "maze24");
   addPath("maze23", "south", "maze54");
   addPath("maze24", "north", "maze25");
   addPath("maze24", "east", "maze52");
   addPath("maze25", "north", "maze26");
   addPath("maze25", "southeast", "maze50");
   addPath("maze26", "east", "maze27");
   addPath("maze26", "west", "maze23");
   addPath("maze27", "north", "maze12");
   addPath("maze27", "southeast", "maze13");
   addPath("maze28", "south", "maze6");
   addPath("maze29", "south", "maze30");
   addPath("maze29", "north", "maze41");
   addPath("maze30", "east", "maze31");
   addPath("maze30", "south", "maze1");
   addPath("maze31", "northwest", "maze29");
   addPath("maze32", "east", "maze33");
   addPath("maze32", "northwest", "maze41");
   addPath("maze33", "south", "maze34");
   addPath("maze33", "west", "maze39");
   addPath("maze34", "west", "maze1");
   addPath("maze34", "south", "maze35");
   addPath("maze35", "north", "maze38");
   addPath("maze35", "south", "maze36");
   addPath("maze36", "west", "maze35");
   addPath("maze36", "east", "maze37");
   addPath("maze37", "south", "maze36");
   addPath("maze37", "north", "maze38");
   addPath("maze38", "north", "maze33");
   addPath("maze38", "east", "maze37");
   addPath("maze38", "west", "maze35");
   addPath("maze39", "northwest", "maze31");
   addPath("maze40", "south", "maze40");
   addPath("maze40", "east", "maze2");
   addPath("maze41", "northwest", "maze28");
   addPath("maze42", "north", "maze43");
   addPath("maze43", "south", "maze16");
   addPath("maze44", "west", "maze16");
   addPath("maze44", "south", "maze45");
   addPath("maze45", "north", "maze44");
   addPath("maze45", "south", "maze46");
   addPath("maze46", "north", "maze16");
   addPath("maze46", "southeast", "maze47");
   addPath("maze47", "west", "maze17");
   addPath("maze48", "west", "maze49");
   addPath("maze49", "east", "maze14");
   addPath("maze49", "west", "maze50");
   addPath("maze50", "west", "maze51");
   addPath("maze50", "north", "maze13");
   addPath("maze51", "west", "maze52");
   addPath("maze52", "north", "maze55");
   addPath("maze52", "south", "maze53");
   addPath("maze53", "east", "maze48");
   addPath("maze53", "south", "maze18");
   addPath("maze54", "south", "maze18");
   addPath("maze54", "north", "maze21");
   addPath("maze55", "east", "maze50");
   addPath("maze56", "west", "maze5");
   addPath("night_maze_landing", "down", "home");
}

void RoomManager::addRoom(string roomName) {
   roomList.push_back(new Room(roomName));
   return;
}
void RoomManager::addPath(string beginningRoom, string direction, string endRoom) {
   Room* origin = findRoom(beginningRoom);
   Room* destination = findRoom(endRoom);
   if (origin && destination)
      origin->addPath(direction, destination);
   else
      std::cout << "addPath went wrong. Please fix!" << std::endl;
   return;
}
void RoomManager::setDescriptions(string roomName, string shortDescription, string longDescription) {
   Room* roomToDescribe = findRoom(roomName);
   if (roomToDescribe)
      roomToDescribe->setDescriptions(shortDescription, longDescription);
   else
      std::cout << "Incorrect string name in setDescriptions! Please fix! Very broken!" << std::endl;
   return;
}

void RoomManager::setDescriptions(string roomName, string description) {
   setDescriptions(roomName, description, description);
}

Room* RoomManager::findRoom(string roomName) {
   Room* roomReturn = nullptr;
   for (int i = 0; !roomReturn && i < roomList.size(); i++) {
      if (roomList[i]->getName() == roomName)
         roomReturn = roomList[i];
   }
   return roomReturn;
}

Room* RoomManager::getSpawnLocation() {
   return findRoom("home");
}
