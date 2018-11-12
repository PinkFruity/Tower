#ifndef PATH_H
#define PATH_H
class Path;
#include "Room.h"
#include <string>
using namespace std;

/* Holds all data about a single path from Room A to Room B.
 * Things to note:
   (1) Paths only exist within Room.
   (2) Paths are only aware of
      > which room they lead into
      > the direction a user needs to input
      > if the path is traversable (A.K.A. user is allowed to go() to the destination).
      They're unaware of which room they come from.
 */
class Path {
public:
   Path(string direction, Room* goHere);
   string getPathName();
   Room* getDestination();
   bool isAccessible();
   string getBarrier();
   void setBarrier(string reason);
   void removeBarrier();
private:
   string pathName;
   Room* destination;
   string barrier; // Tells go() if the path is traversable
};

#endif
