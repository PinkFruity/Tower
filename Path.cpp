#include "Path.h"

Path::Path(string direction, Room* goHere) : pathName(direction), destination(goHere) {};

string Path::getPathName() {
   return pathName;
}

Room* Path::getDestination() {
   return destination;
}

bool Path::isAccessible() {
   return barrier.empty();
}

string Path::getBarrier() {
   return barrier;
}

void Path::setBarrier(string reason) {
   barrier = reason;
}

void Path::removeBarrier() {
   barrier = "";
}
