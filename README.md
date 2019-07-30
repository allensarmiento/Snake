# Snake
Terminal console implementation of the game Snake where the snake cannot collide with a wall, itself, or enemies.

## Language Used
C++

## How to Play:
Move the snake player around with the following keys: W (UP), A (LEFT), S (DOWN), D (RIGHT). Collect as much food (F) as you can without colliding with the wall, yourself, or the enemies.

## How to Execute:
1. Download the repository.
2. Go to the folder Snake and in your terminal execute the following:
```
make all
```
3. An Snake executable file should be created. Run it with the following:
```
./Snake
```

## Implementation Details
- Game Class
- Game Screen Class
- Player Class
- Food Class
- Enemy Class

## Notes
The implementation is that if the snake has a body of 2 or less, it can move in opposite directions because it is not colliding with itself. With a body of 2, the positions of the first and second part will swap with each other, so a collision does not occur. However, if the snake eats a food and gets another body part, it will no longer be able to move opposite directions because it will collide with itself. This can be changed by editing the possible directions available.<br>

Enemies are semicolons (;) which move around the screen. If any part of the snake's body touches a semicolon, the game is over. <br>

Colliding with a food (F) increases the score and adds a body to the snake. <br>

The game is lossed upon colliding with the wall, your own body, or enemies. <br>
