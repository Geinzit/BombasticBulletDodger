# Bombastic Bullet Dodger

# Team members:
Huang Mao Dian Heinz 3035844077
Dave Henokh Liong 3035902415

# Description
The player will dodge incoming bullets from all sides of the map by controlling their body. The game’s difficulty increases gradually (in which the bullets will be faster and bigger) as the player continues to survive. The player has three hearts, and the game ends when the player gets hit with three bullets (1 bullet deals 1 heart). During the game, random items can appear on the map, such as health recovery items.

# Game rules: 
1. Use WASD to control your movements
2. A player has three hearts, and when the player ran out of hearts, the game ends.
3. The score is calculated by the time the player survives with other possible bonuses.
4. Don’t touch the bullets! 1 bullet deals 1 heart.
5. There will be a chance for the player to recover their hearts by catching health recovery items.
6. There are three difficulties: easy, medium, and hard:
- In easy mode, the maximum bullets that can be generated in the map is 15, and the starting health of the player is 3.
- In medium mode, the maximum bullets that can be generated in the map is 25, and the starting health of the player is 3.
- In hard mode, the maximum bullets that can be generated in the map is 25, and the starting health of the player is 1.


# Features

1. The random element of this game will be the bullet speed and direction.
2. The data structure for storing game status is arrays. The array is going to be used to store the scores and the random number that will become the “seed” for the bullet direction.
3. The memory used to store the bullets will be dynamic-memory allocated.
4. The input is the latest player’s score and the output is the high score after the game ends.
5. We are going to put each feature in different files and import them together in the main file which will be run.
