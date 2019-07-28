#include "player_class.h"

// Initialize player direction to up.
Player::Player() {
  direction = "UP";
}

// Set player to center of the screen.
void Player::CenterPosition(int game_width, int game_height) {
  x_position = game_height / 2;
  y_position = game_width / 2;
}

// Set player position upon keyboard click.
//
// y_position increases/decreases by 2 to have the same feel as the x_position.
// If y_position only increases by 1, it appears to be slower than the x_position.
// This is most likely due to the default spacing in the terminal.
void Player::SetPosition() {
  if (direction == "UP") {
    x_position--;
  }
  if (direction == "RIGHT") {
    y_position++;
    // Check if collided with an object.
    // y_position++;
  }
  if (direction == "DOWN") {
    x_position++;
  }
  if (direction == "LEFT") {
    y_position--;
    // Check if collided with an object.
    // y_position--;
  }
}

// Return player x position.
int Player::GetXPosition() {
  return x_position;
}

// Return player y position.
int Player::GetYPosition() {
  return y_position;
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
    std::cout << "Going Left" << '\n';
  }
  if (key == 's'){
    direction = "DOWN";
  }
  if (key == 'd') {
    direction = "RIGHT";
  }
}

Player::~Player() {}
