#include "enemy_class.h"

Enemy::Enemy() {}

void Enemy::SetPosition(int game_width, int game_height) {
  x_position = (rand() % (game_height - 3)) + 2;
  y_position = (rand() % (game_width - 3)) + 2;
}

int Enemy::GetXPosition() {
  return x_position;
}

int Enemy::GetYPosition() {
  return y_position;
}

Enemy::~Enemy() {}
