#include <iostream>
#include <string>
#include "TheGame.h"

int main() {
   TheGame game;

   string playerCommand;
   while (!game.over()) {
      getline(cin, playerCommand);
      game.doCommand(playerCommand);
   }
   system("pause");
   return 0;
}

/* TO IMPLEMENT LIST:
   1. A time system
      a. every command costing time (minimum of 1 minute)
      b. events happening at certain time intervals (like hourly bells or life-drains from keys)
   2. Character health
*/

/* TO POLISH LIST:
 * 1. When you enter a room, each item's short description is displayed (as opposed to the current, "There is a x, y, and z on the floor").
      a. items would need a long and short description (currently only have a single description)
   2. Make certain items unholdable (like doors or other heavy things).
      a. character would need a carrying capacity variable
      b. items would need burdens
   3. Items should have aliases that users can use (e.g. "key" or "the ice key" for "ice_key"). To be handled in normalizer().
      a. items would need a vector<string> of names instead of a single variable
      b. logic for various functions would need to be revised, so any time we check item.getName() == string, we'd need to swap that to
         a function in Item, like isA(string) that would return true/false if that string were found in that item's vector list of aliases.
         if (item.isA("door"));
   4. Items should display their status in their description (short and long).
   5. COMPLETE - When you enter a room, possible directions should be displayed. (Yes, it would mean duplicating it in the room description, but it
      should make things clear for the user. I hope.)
   6. Command examine should fail when the user doesn't input anything afterwards, i.e., "examine" is their only input.
   7. Because the maze is so difficult, maybe some signposts/encouragement/items/easter eggs should be placed in rooms the way Pokemon does.
      Makes it less frustrating to be stuck in some areas?
*/