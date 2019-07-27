class Player {
 public:
   Player();
   void SetPosition(int game_width, int game_height);
   int GetXPosition();
   int GetYPosition();
   ~Player();
 private:
   int x_position;
   int y_position;
};
