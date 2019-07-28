#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <termios.h>
#include "game_screen_class.h"
#include "player_class.h"
#include "food_class.h"

class Game {
 public:
  Game();
  void SetDimensions(int width, int height);
  void SetTitle(std::string title);
  void DisplayTitle();
  void UpdatePlayer();
  void UpdateFood();
  void GetFoodPosition();
  void DisplayGameInterface();
  void Sleep(int milliseconds);
  void Start();
  void Blit();
  ~Game();
 private:
   std::string game_title;
   int game_width;
   int game_height;
   int fps;
   char** game_interface;
   GameScreen game_screen;
   Player player;
   Food food;
};
