#include <iostream>
#include <iomanip>

class GameScreen {
 public:
  GameScreen();
  void SetGameDimensions(int width, int height);
  void DisplayCenter(std::string message);
  void InitGameScreen();
  void DisplayGameScreen();
  ~GameScreen();
 private:
  char** game_screen;
  int game_width;
  int game_height;
};
