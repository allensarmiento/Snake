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
  food.SetBoundaries(game_width, game_height);
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
  // NOTE: This line of code is a test to see if the food lands on a random
  // position each time. Eventually, will check for collision to know when
  // to get the new position.
  UpdateFood();
  // Game Loop: Read input and update game screen.
  while (true) {
    char key;
    if (player._keyboardhit()) {
      std::cin >> key;
      player.SetKeyboardInput(key);
    }
    system("clear");
    // Set up game interface for redraw so update player.
    game_screen.InitGameScreen();
    game_interface = game_screen.GetGameScreen();
    // Draw game screen.
    Blit();
    Sleep(fps);
  }
}

// Update Player position.
void Game::UpdatePlayer() {
  player.SetPosition();
  int x = player.GetXPosition();
  int y = player.GetYPosition();
  game_interface[x][y] = '#';
}

void Game::UpdateFood() {
  food.SetFoodPosition();
}

void Game::GetFoodPosition() {
  int x = food.GetXFoodPosition();
  int y = food.GetYFoodPosition();
  game_interface[x][y] = food.GetFoodSymbol();
}

bool Game::PlayerCollideFruit() {
  int x_player = player.GetXPosition();
  int y_player = player.GetYPosition();
  int x_food = food.GetXFoodPosition();
  int y_food = food.GetYFoodPosition();
  if (x_player == x_food && y_player == y_food) {
    return true;
  }
  return false;
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
void Game::Sleep(int fps) {
  clock_t time_end;
  time_end = clock() + fps * CLOCKS_PER_SEC/1000;
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
  if (PlayerCollideFruit()) {
    UpdateFood();
  }
  GetFoodPosition();
  DisplayGameInterface();
}

Game::~Game() {}
