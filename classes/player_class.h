#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

class Player {
 public:
   Player();
   void CenterPosition(int game_width, int game_height);
   void SetPosition();
   int GetXPosition();
   int GetYPosition();
   int _keyboardhit();
   void SetKeyboardInput(char key);
   ~Player();
 private:
   int x_position;
   int y_position;
   int bytes_waiting;
   std::string direction;
};
