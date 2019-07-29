#include <ctime>
#include <cstdlib>

class Enemy {
 public:
   Enemy();
   void SetPosition(int game_width, int game_height);
   int GetXPosition();
   int GetYPosition();
   ~Enemy();
 private:
   int x_position;
   int y_position;
};
