# Snake
Implementation of the game Snake where the snake cannot collide with a wall, itself, or enemies.

## Language Used
C++

## Implementation Details
- Game Class
- Game Screen Class
- Player Class
- Food Class
- Enemy Class

## Notes
The implementation is that if the snake has only one body, it can move in opposite directions because it is not colliding with itself. However, if the snake eats a food and gets another body part, it will no longer be able to move opposite directions because it will collide with itself. <br>

Enemies are semicolons (;) which move around the screen. If any part of the snake's body touches a semicolon, the game is over. <br>

Colliding with a food (F) increases the score and adds a body to the snake. <br>

The game is lossed upon colliding with the wall, your own body, or enemies. <br>
