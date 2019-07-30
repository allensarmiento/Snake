#include <ctime>
#include <cstdlib>

class Enemy {
 public:
   Enemy();
   void SetPosition(int game_width, int game_height);
   void SetXPosition(int x);
   void SetYPosition(int y);
   void SetXVector(int x_vec);
   void SetYVector(int y_vec);
   int GetXPosition();
   int GetYPosition();
   int GetXVector();
   int GetYVector();
   ~Enemy();
 private:
   int x_position;
   int y_position;
   int x_vector;
   int y_vector;
};
