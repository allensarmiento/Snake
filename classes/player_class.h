#include <iostream>

class Player {
 public:
   Player(int game_width, int game_height);
   ~Player();
 private:
   int x_position;
   int y_position;
};
