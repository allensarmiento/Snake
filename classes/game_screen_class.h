#include <iostream>

class GameScreen {
 public:
  // Get width and height values, then allocate memory
  // for board space.
  GameScreen(int width, int height) {
    game_width = width;
    game_height = height;
    game_screen = new char*[game_height];
    for (int i = 0; i < game_height; i++) {
      game_screen[i] = new char[game_width];
    }
  }
  void InitGameScreen() {
    for (int i = 0; i < game_height; i++) {
      for (int j = 0; j < game_width; j++) {
        if (i == 0 || i == game_height-1 || j == 0 || j == game_width-1) {
          game_screen[i][j] = '*';
        } else {
          game_screen[i][j]  = ' ';
        }
      }
    }
  }
  void DisplayGameScreen() {
    for (int i = 0; i < game_height; i++) {
      for (int j = 0; j < game_width; j++) {
        std::cout << game_screen[i][j];
      }
      std::cout << '\n';
    }
  }
  ~GameScreen(){}

 private:
  char** game_screen;
  int game_width;
  int game_height;
};

