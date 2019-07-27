#include <iostream>
#include <iomanip>
#include "game_screen_class.h"

class Game {
 public:
  Game();
  void SetDimensions(int width, int height);
  void SetTitle(std::string title);
  void Start();
  void DisplayGameInterface();
  void Blit();
  ~Game();
 private:
   std::string game_title;
   int game_width;
   int game_height;
   char** game_interface;
   GameScreen game_screen;
};
