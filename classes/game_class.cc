#include "game_class.h"

Game::Game() {}

void Game::SetDimensions(int width, int height) {
  game_screen.SetGameDimensions(width, height);
}

void Game::SetTitle(std::string title) {
  game_title = title;
}

void Game::Start() {
  game_screen.InitGameScreen();
  game_screen.DisplayCenter(game_title);
  game_screen.DisplayGameScreen();
}

Game::~Game() {}
