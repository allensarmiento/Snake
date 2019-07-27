#include "game_class.h"

// Set default frames per second.
Game::Game() {
  fps = 200;
}

// Set Game Dimensions; Player gets updated according to dimensions.
void Game::SetDimensions(int width, int height) {
  game_screen.SetGameDimensions(width, height);
  game_width = width;
  game_height = height;
  game_screen.InitGameScreen();
  game_interface = game_screen.GetGameScreen();
  player.CenterPosition(game_width, game_height);
  // TODO: Set dimensions for the  right side interface
}

// Set game title.
void Game::SetTitle(std::string title) {
  game_title = title;
}

// Handle game logic.
void Game::Start() {
  // Initial clearing of screen.
  system("clear");
  // Game Loop: Read input and update game screen.
  while (true) {
    char key;
    if (player._keyboardhit()) {
      std::cin >> key;
      player.SetKeyboardInput(key);
    }
    system("clear");
    Blit();
    Sleep(fps);
  }
}

// Update Player position.
void Game::UpdatePlayer() {
  int x = player.GetXPosition();
  int y = player.GetYPosition();
  game_interface[x][y] = '|';
}

// Display the Game Interface.
void Game::DisplayGameInterface() {
  for (int i = 0; i < game_height; i++) {
    for (int j = 0; j < game_width; j++) {
      std::cout << game_interface[i][j];
    }
    std::cout << '\n';
  }
}

// Sleep Function
void Game::Sleep(int milliseconds) {
  clock_t time_end;
  time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
  while (clock() < time_end) {}
}

// Displays the message in the center of the corresponding game width.
void Game::DisplayTitle() {
  std::cout << std::setfill(' ') << std::setw(game_width/2 + game_title.length()/2) << game_title << '\n';
}

// Display the title, update player position and display game interface.
void Game::Blit() {
  DisplayTitle();
  UpdatePlayer();
  DisplayGameInterface();
}

Game::~Game() {}
