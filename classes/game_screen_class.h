#include <iostream>
#include <iomanip>

class GameScreen {
 public:
  GameScreen();
  void SetGameDimensions(int width, int height);
  char** GetGameScreen();
  void InitGameScreen();
  ~GameScreen();
 private:
  int game_width;
  int game_height;
  char** game_screen;
};
