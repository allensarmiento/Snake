#include "game_class.h"

Game::Game() {}

void Game::SetDimensions(int width, int height) {
  game_screen.SetGameDimensions(width, height);
  game_width = width;
  game_height = height;
  game_screen.InitGameScreen();
  game_interface = game_screen.GetGameScreen();
  // TODO: Set dimensions for the  right side interface
}

void Game::SetTitle(std::string title) {
  game_title = title;
}

void Game::Start() {
  Blit();
}

void Game::DisplayGameInterface() {
  for (int i = 0; i < game_height; i++) {
    for (int j = 0; j < game_width; j++) {
      std::cout << game_interface[i][j];
    }
    std::cout << '\n';
  }
}

// Displays the message in the center of the corresponding game width.
void Game::DisplayTitle() {
  std::cout << std::setfill(' ') << std::setw(game_width/2 + game_title.length()/2) << game_title << '\n';
}

void Game::Blit() {
  DisplayTitle();
  DisplayGameInterface();
}

Game::~Game() {}
