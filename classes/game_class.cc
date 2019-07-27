#include "game_class.h"

struct termios terminalSettings;

Game::Game() {
  fps = 200;
}

void Game::SetDimensions(int width, int height) {
  game_screen.SetGameDimensions(width, height);
  game_width = width;
  game_height = height;
  game_screen.InitGameScreen();
  game_interface = game_screen.GetGameScreen();

  player.SetPosition(game_width, game_height);
  // TODO: Set dimensions for the  right side interface
}

void Game::SetTitle(std::string title) {
  game_title = title;
}

// Handle game logic here
void Game::Start() {
  system("clear");
  while (true) {
    char key;
    if (player._keyboardhit()) {
      std::cin >> key;
      player.SetKeyboardInput(key);
    }
    Blit();
    Sleep(fps);
    system("clear");
  }
}

void Game::UpdatePlayer() {
  int x = player.GetXPosition();
  int y = player.GetYPosition();
  game_interface[x][y] = '|';
}

void Game::DisplayGameInterface() {
  for (int i = 0; i < game_height; i++) {
    for (int j = 0; j < game_width; j++) {
      std::cout << game_interface[i][j];
    }
    std::cout << '\n';
  }
}

// Cross Platform Sleep Function
void Game::Sleep(int milliseconds) {
  clock_t time_end;
  time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
  while (clock() < time_end) {}
}

// Displays the message in the center of the corresponding game width.
void Game::DisplayTitle() {
  std::cout << std::setfill(' ') << std::setw(game_width/2 + game_title.length()/2) << game_title << '\n';
}

void Game::Blit() {
  DisplayTitle();
  UpdatePlayer();
  DisplayGameInterface();
}

Game::~Game() {}
