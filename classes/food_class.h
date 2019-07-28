#include <iostream>
#include <ctime>
#include <cstdlib>

class Food {
 public:
   Food();
   void SetBoundaries(int game_width, int game_height);
   void SetFoodPosition();
   char GetFoodSymbol();
   int GetXFoodPosition();
   int GetYFoodPosition();
   ~Food();
 private:
   char food;
   int x_food_position;
   int y_food_position;
   int x_boundary;
   int y_boundary;
};
