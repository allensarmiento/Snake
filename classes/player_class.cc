#include "player_class.h"

Player::Player() {}

void Player::SetPosition(int game_width, int game_height) {
  x_position = game_height / 2;
  y_position = game_width / 2;
}

int Player::GetXPosition() {
  return x_position;
}

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

void Player::SetKeyboardInput(char key) {
  std::cout << "Key input: " << key << '\n';
}

Player::~Player() {}
