#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <vector>

class Player {
 public:
   Player();
   void CenterPosition(int game_width, int game_height);
   void SetPosition();
   int GetXPosition();
   int GetYPosition();
   int _keyboardhit();
   void SetKeyboardInput(char key);
   void AddBody();
   std::vector<int> GetXBody();
   std::vector<int> GetYBody();
   ~Player();
 private:
   int x_position;
   int y_position;
   int bytes_waiting;
   std::string direction;
   std::vector<int> x_body;
   std::vector<int> y_body;
};
