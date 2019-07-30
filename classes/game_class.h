#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <termios.h>
#include <vector>
#include "enemy_class.h"
#include "food_class.h"
#include "game_screen_class.h"
#include "player_class.h"

class Game {
 public:
  Game();
  void SetDimensions(int width, int height);
  void SetTitle(std::string title);
  void GetFoodPosition();
  void DisplayTitle();
  void UpdateEnemies();
  void UpdateFood();
  void UpdatePlayer();
  bool EnemyCollideWall(Enemy enemy);
  bool PlayerCollideEnemy(Enemy enemy);
  bool PlayerCollideFruit();
  bool PlayerCollideWall();
  bool PlayerCollideSelf();
  void DisplayGameInterface();
  void Blit();
  void Sleep(int milliseconds);
  void Start();
  ~Game();
 private:
   bool playing;
   int fps;
   int game_width;
   int game_height;
   int score;
   int num_enemies;
   char** game_interface;
   std::string game_title;
   std::vector<Enemy> enemies;
   Food food;
   GameScreen game_screen;
   Player player;
};
