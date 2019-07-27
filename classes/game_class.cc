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

void Game::Blit() {
  game_screen.DisplayCenter(game_title);
  DisplayGameInterface();
}

Game::~Game() {}
