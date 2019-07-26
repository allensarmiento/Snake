// Main Driver.
//
// Incorporate a game board that contains a game screen.
// This will be used to show the score on the side.

#include <iostream>
#include <iomanip>
#include "classes/game_class.h"
using namespace std;

int main() {
  int game_width = 50;
  int game_height = 30;
  string game_title = "SNAKE";

  Game game;
  game.SetDimensions(game_width, game_height);
  game.SetTitle(game_title);
  game.Start();

  return 0;
}
