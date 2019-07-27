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

Player::~Player() {}
