#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <vector>

class Player {
 public:
   Player();
   int _keyboardhit();
   void SetKeyboardInput(char key);
   void SetPosition();
   std::vector<int> GetXBody();
   std::vector<int> GetYBody();
   int GetXPosition();
   int GetYPosition();
   void AddBody();
   void CenterPosition(int game_width, int game_height);
   ~Player();
 private:
   int bytes_waiting;
   std::string direction;
   std::vector<int> x_body;
   std::vector<int> y_body;
};
