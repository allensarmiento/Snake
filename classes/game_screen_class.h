#include <iostream>
#include <iomanip>

class GameScreen {
 public:
  GameScreen();
  void SetGameDimensions(int width, int height);
  void InitGameScreen();
  char** GetGameScreen();
  ~GameScreen();
 private:
  char** game_screen;
  int game_width;
  int game_height;
};
