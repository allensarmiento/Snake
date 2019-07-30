#include "food_class.h"

// Initialize food symbol.
Food::Food() {
  food = 'F';
}

// Set the boundaries the food can be within.
void Food::SetBoundaries(int game_width, int game_height) {
  x_boundary = game_height;
  y_boundary = game_width;
}

// Set a random food position within the boundaries.
void Food::SetFoodPosition() {
  x_food_position = (rand() % (x_boundary - 3)) + 2;
  y_food_position = (rand() % (y_boundary - 3)) + 2;
}

// Get the food symbol.
char Food::GetFoodSymbol() {
  return food;
}

// Get the x food position.
int Food::GetXFoodPosition() {
  return x_food_position;
}

// Get the y food position.
int Food::GetYFoodPosition() {
  return y_food_position;
}

Food::~Food() {}
