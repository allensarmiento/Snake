// Main Driver.
//
// Incorporate a game board that contains a game screen.
// This will be used to show the score on the side.

#include <iostream>
#include <iomanip>
#include "classes/game_screen_class.h"
using namespace std;

// Displays the message in the center of the corresponding width.
void displayCenter(string message, int width) {
  cout << setfill(' ') << setw(width/2 + message.length()/2) << message << '\n';
}

int main() {
  int game_width = 50;
  int game_height = 30;

  displayCenter("SNAKE", game_width);
  GameScreen game_screen(game_width, game_height);
  game_screen.InitGameScreen();
  game_screen.DisplayGameScreen();

  return 0;
}

