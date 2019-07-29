#include "player_class.h"

// Initialize player direction to up.
Player::Player() {
  direction = "UP";
}

// Set player to center of the screen.
void Player::CenterPosition(int game_width, int game_height) {
  int x_position = game_height / 2;
  int y_position = game_width / 2;

  x_body.push_back(x_position);
  y_body.push_back(y_position);
  AddBody();
}

// Set player position upon keyboard click.
void Player::SetPosition() {
  if (direction == "UP") {
    x_body[0] -= 1;
  }
  if (direction == "RIGHT") {
    y_body[0] += 1;
  }
  if (direction == "DOWN") {
    x_body[0] += 1;
  }
  if (direction == "LEFT") {
    y_body[0] -= 1;
  }
  for (int i = x_body.size() - 1; i > 0; i--) {
    x_body[i] = x_body[i-1];
    y_body[i] = y_body[i-1];
  }
}

// Return player x head position.
int Player::GetXPosition() {
  return x_body[0];
}

// Return player y head position.
int Player::GetYPosition() {
  return y_body[0];
}

// Check Keyboard Hit or Not
int Player::_keyboardhit() {
  static const int STDIN = 0;
  static bool initialized = false;
  if (!initialized) {
    termios term;
    tcgetattr(STDIN, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN, TCSANOW, &term);
    setbuf(stdin, NULL);
    initialized = true;
  }
  ioctl(STDIN, FIONREAD, &bytes_waiting);
  return bytes_waiting;
}

// Set the keyboard direction.
void Player::SetKeyboardInput(char key) {
  std::cout << "Key input: " << key << '\n';
  if (key == 'w') {
    direction = "UP";
  }
  if (key == 'a') {
    direction = "LEFT";
  }
  if (key == 's'){
    direction = "DOWN";
  }
  if (key == 'd') {
    direction = "RIGHT";
  }
}

void Player::AddBody() {
  int x_back = x_body[x_body.size()-1];
  int y_back = y_body[y_body.size()-1];
  if (direction == "UP") {
    x_body.push_back(x_back + 1);
    y_body.push_back(y_back);
  }
  if (direction == "DOWN") {
    x_body.push_back(x_back - 1);
    y_body.push_back(y_back);
  }
  if (direction == "LEFT") {
    x_body.push_back(x_back);
    y_body.push_back(y_back + 1);
  }
  if (direction == "RIGHT") {
    x_body.push_back(x_back);
    y_body.push_back(y_back - 1);
  }
}

std::vector<int> Player::GetXBody() {
  return x_body;
}

std::vector<int> Player::GetYBody() {
  return y_body;
}

Player::~Player() {}
