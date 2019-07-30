#include "enemy_class.h"

// Set initial x and y vectors.
Enemy::Enemy() {
  x_vector = 1;
  y_vector = 1;
}

// Randomly choose a position of the enemy according to the
// game width and game height.
void Enemy::SetPosition(int game_width, int game_height) {
  x_position = (rand() % (game_height - 3)) + 2;
  y_position = (rand() % (game_width - 3)) + 2;
}

// Set the x position.
void Enemy::SetXPosition(int x) {
  x_position = x;
}

// Set the y position.
void Enemy::SetYPosition(int y) {
  y_position = y;
}

// Set the x vector.
void Enemy::SetXVector(int x_vec) {
    x_vector = x_vec;
}

// Set the y vector.
void Enemy::SetYVector(int y_vec) {
  y_vector = y_vec;
}

// Get the x position.
int Enemy::GetXPosition() {
  return x_position;
}

// Get the y position.
int Enemy::GetYPosition() {
  return y_position;
}

// Get the x vector.
int Enemy::GetXVector() {
  return x_vector;
}

// Get the y vector.
int Enemy::GetYVector() {
  return y_vector;
}

Enemy::~Enemy() {}
