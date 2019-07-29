#include "enemy_class.h"

Enemy::Enemy() {
  x_vector = 1;
  y_vector = 1;
}

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

void Enemy::SetXPosition(int x) {
  x_position = x;
}

void Enemy::SetYPosition(int y) {
  y_position = y;
}

int Enemy::GetXVector() {
  return x_vector;
}

int Enemy::GetYVector() {
  return y_vector;
}

void Enemy::SetXVector(int x_vec) {
    x_vector = x_vec;
}

void Enemy::SetYVector(int y_vec) {
  y_vector = y_vec;
}

Enemy::~Enemy() {}
