// Main Driver
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "classes/game_class.h"
using namespace std;

int main() {
  srand(time(0));
  int game_width = 50;
  int game_height = 30;
  string game_title = "SNAKE";

  Game game;
  game.SetDimensions(game_width, game_height);
  game.SetTitle(game_title);
  game.Start();

  return 0;
}
