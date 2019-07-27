#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
// #include <stropts.h>
#include <stdio.h>

class Player {
 public:
   Player();
   void SetPosition(int game_width, int game_height);
   int GetXPosition();
   int GetYPosition();
   int _keyboardhit();
   void SetKeyboardInput(char key);
   ~Player();
 private:
   int x_position;
   int y_position;
   int bytes_waiting;
};
