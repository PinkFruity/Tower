#ifndef CLOCK_H
#define CLOCK_H
class Clock;
#include <iomanip>
#include "TheGame.h"
#include "Character.h"

class Clock {
public:
   Clock(TheGame*);
   void addTime(int);
   string getTime();
   void setMainCharacter(Character*);
private:
   //int getTimeChange()
   TheGame* bigBoss;
   Character* mainCharacter;
   int minutes;
   int timeHeldIceKey;
};

#endif