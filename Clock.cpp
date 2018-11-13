#include "Clock.h"

Clock::Clock(TheGame* game) {
   bigBoss = game;
   minutes = 0;
   timeHeldIceKey = 0;
   mainCharacter = game->getMainCharacter();
}

void Clock::addTime(int toAdd) {
   int timeChange;
   timeChange = ((minutes + toAdd) / 60) - (minutes / 60);
   if (timeChange) {
      cout << "You hear a bell toll in the distance ..." << endl;
      cout << "-15 HEALTH" << endl;
      mainCharacter->addHealth(-15);
   }
   Item* foundItem = mainCharacter->findItem("ice key");
   if (foundItem) {
      timeChange = ((timeHeldIceKey + toAdd) / 3) - (timeHeldIceKey / 3);
      if (timeChange) {
         //cout << "The key chills you." << endl;
         //cout << "-" << timeChange * 2 << " HEALTH" << endl;
         mainCharacter->addHealth(-(timeChange * 2));
      }
   }
   minutes += toAdd;
   return;
}

string Clock::getTime() {
   stringstream iss;
   int hour = (minutes / 60) % 24;
   if (hour < 6)
      iss << "MORNING ";
   else if (hour < 12)
      iss << "AFTERNOON ";
   else if (hour < 24)
      iss << "NIGHT ";
   iss << setfill('0') << "(" << setw(2) << hour << ":" << setw(2) << minutes % 60 << ")";
   return iss.str();
}

void Clock::setMainCharacter(Character* mc) {
   mainCharacter = mc;
}