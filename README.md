# Snake
Implementation of the game Snake where the snake cannot collide with a wall, itself, or enemies.

## Language Used
C++

## How to Play:
Move the snake player around with the following keys: W (UP), A (LEFT), S (DOWN), D (RIGHT). Collect as much food (F) as you can without colliding with the wall, yourself, or the enemies.

## Implementation Details
- Game Class
- Game Screen Class
- Player Class
- Food Class
- Enemy Class

## Notes
The implementation is that if the snake has only one body, it can move in opposite directions because it is not colliding with itself. However, if the snake eats a food and gets another body part, it will no longer be able to move opposite directions because it will collide with itself. This can be changed by editing the possible directions available.<br>

Enemies are semicolons (;) which move around the screen. If any part of the snake's body touches a semicolon, the game is over. <br>

Colliding with a food (F) increases the score and adds a body to the snake. <br>

The game is lossed upon colliding with the wall, your own body, or enemies. <br>
