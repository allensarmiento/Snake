#include <iostream>
#include <iomanip>
#include "game_screen_class.h"

class Game {
 public:
  Game();
  void SetDimensions(int width, int height);
  void SetTitle(std::string title);
  void Start();
  ~Game();
 private:
   std::string game_title;
   GameScreen game_screen;
};
