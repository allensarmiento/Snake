#include "game_class.h"

// Set default frames per second.
Game::Game() {
  fps = 200;
  playing = true;
  score = 1;
  num_enemies = 10;
  for (int i = 0; i < num_enemies; i++) {
    enemies.push_back(Enemy());
  }
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
  for (int i = 0; i < num_enemies; i++) {
    enemies[i].SetPosition(game_width, game_height);
  }
}

// Set game title.
void Game::SetTitle(std::string title) {
  game_title = title;
}

// Add the food position to the game interface.
void Game::GetFoodPosition() {
  int x = food.GetXFoodPosition();
  int y = food.GetYFoodPosition();
  game_interface[x][y] = food.GetFoodSymbol();
}

// Displays the message in the center of the corresponding game width.
void Game::DisplayTitle() {
  std::cout << std::setfill(' ') << std::setw(game_width/2 + game_title.length()/2) << game_title << '\n';
}

// Update all enemy positions according to the vector.
void Game::UpdateEnemies() {
  // Loop through all enemies, check if collided with wall, and
  // update vector.
  for (int i = 0; i < num_enemies; i++) {
    if (EnemyCollideWall(enemies[i])) {
      int x_vector = enemies[i].GetXVector();
      enemies[i].SetXVector(x_vector * -1);
      int y_vector = enemies[i].GetYVector();
      enemies[i].SetYVector(y_vector * -1);
    }
    int x_position = enemies[i].GetXPosition();
    int y_position = enemies[i].GetYPosition();
    enemies[i].SetXPosition(x_position + enemies[i].GetXVector());
    enemies[i].SetYPosition(y_position + enemies[i].GetYVector());
    x_position = enemies[i].GetXPosition();
    y_position = enemies[i].GetYPosition();
    game_interface[x_position][y_position] = ';';
  }
}

// Update food position.
void Game::UpdateFood() {
  food.SetFoodPosition();
}

// Update Player position.
void Game::UpdatePlayer() {
  // Make sure player is not out of bounds.
  if (PlayerCollideWall()) { return; }
  for (int i = 0; i < num_enemies; i++) {
    if (PlayerCollideEnemy(enemies[i])) { return; }
  }
  // Set the next position.
  player.SetPosition();
  // Get the location of the new position and add to game interface.
  std::vector<int> x = player.GetXBody();
  std::vector<int> y = player.GetYBody();
  for (int i = 0; i < x.size(); i++) {
    game_interface[x[i]][y[i]] = '#';
  }
}

// Check if enemy collides with a wall.
bool Game::EnemyCollideWall(Enemy enemy) {
  int x_enemy = enemy.GetXPosition();
  int y_enemy = enemy.GetYPosition();
  if (game_interface[x_enemy][y_enemy] == '*') {
    return true;
  }
  return false;
}

// Check if player collided with enemy.
bool Game::PlayerCollideEnemy(Enemy enemy) {
  int x_enemy = enemy.GetXPosition();
  int y_enemy = enemy.GetYPosition();
  std::vector<int> x_body = player.GetXBody();
  std::vector<int> y_body = player.GetYBody();
  for (int i = 0; i < x_body.size(); i++) {
    if (x_body[i] == x_enemy && y_body[i] == y_enemy) {
      return true;
    }
  }
  return false;
}

// Check if player collided with fruit/food.
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

// Check if player collided with a wall.
bool Game::PlayerCollideWall() {
  int x_player = player.GetXPosition();
  int y_player = player.GetYPosition();
  if (game_interface[x_player][y_player] == '*') {
    return true;
  }
  return false;
}

// Check if player collided with itself.
bool Game::PlayerCollideSelf() {
  std::vector<int> x = player.GetXBody();
  std::vector<int> y = player.GetYBody();
  for (int i = 2; i < x.size(); i++) {
    if (x[1] == x[i] && y[1] == y[i]) {
      return true;
    }
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

// Display the title, update player position and display game interface.
void Game::Blit() {
  DisplayTitle();
  std::cout << "Score: ";
  if (PlayerCollideFruit()) {
    UpdateFood();
    player.AddBody();
    score++;
  }
  if (PlayerCollideWall() || PlayerCollideSelf()) { playing = false; }
  for (int i = 0; i < num_enemies; i++) {
    if (PlayerCollideEnemy(enemies[i])) { playing = false; }
  }
  GetFoodPosition();
  UpdateEnemies();
  UpdatePlayer();
  std::cout << score << '\n';
  DisplayGameInterface();
}

// Sleep Function
void Game::Sleep(int fps) {
  clock_t time_end;
  time_end = clock() + fps * CLOCKS_PER_SEC/1000;
  while (clock() < time_end) {}
}

// Handle game logic.
void Game::Start() {
  // Initial clearing of screen.
  system("clear");
  // Place food position.
  UpdateFood();
  // Game Loop: Read input and update game screen.
  while (playing) {
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
  std::cout << "Final score: " << score << '\n';
}

Game::~Game() {}
