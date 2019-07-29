#include <ctime>
#include <cstdlib>

class Enemy {
 public:
   Enemy();
   void SetPosition(int game_width, int game_height);
   int GetXPosition();
   int GetYPosition();
   void SetXPosition(int x);
   void SetYPosition(int y);
   int GetXVector();
   int GetYVector();
   void SetXVector(int x_vec);
   void SetYVector(int y_vec);
   ~Enemy();
 private:
   int x_position;
   int y_position;
   int x_vector;
   int y_vector;
};
