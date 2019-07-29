#include "food_class.h"

Food::Food() {
  food = 'F';
}

void Food::SetBoundaries(int game_width, int game_height) {
  x_boundary = game_height;
  y_boundary = game_width;
}

void Food::SetFoodPosition() {
  x_food_position = (rand() % (x_boundary - 2)) + 2;
  y_food_position = (rand() % (y_boundary - 2)) + 2;
}

char Food::GetFoodSymbol() {
  return food;
}

int Food::GetXFoodPosition() {
  return x_food_position;
}

int Food::GetYFoodPosition() {
  return y_food_position;
}

Food::~Food() {}
