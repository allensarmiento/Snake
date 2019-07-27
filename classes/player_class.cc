#include "player_class.h"

// Initialize player direction to up.
Player::Player() {
  direction  = "UP";
}

// Set player to center of the screen.
void Player::CenterPosition(int game_width, int game_height) {
  x_position = game_height / 2;
  y_position = game_width / 2;
}

// Set player position upon keyboard click.
void Player::SetPosition(std::string direction) {

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
}

Player::~Player() {}
