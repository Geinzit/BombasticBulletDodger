# Bombastic Bullet Dodger

# Team members:
Huang Mao Dian Heinz 3035844077
Dave Henokh Liong 3035902415

# General Description
The player will dodge incoming bullets from all sides of the map by controlling their body. The player has three hearts, and the game ends when the player gets hit with three bullets (1 bullet deals 1 heart). During the game, healing items will randomly spawn, which will increase the player's heart by 1.

# Game rules: 
1. Use WASD to control your movements.
2. In the start of the game, a player has three hearts. When the player runs out of hearts, the game ends. 
3. Don’t touch the bullets! 1 bullet deals 1 heart.
4. There will be a chance for the player to recover their health by catching healing items that will randomly spawn on the map. However, the maximum number of health a player can have is 7. When the number is reached, no healing items will spawn.
5. The score is calculated by how much time the player survives.
6. There are three difficulties: easy, medium, and hard:
- In easy mode, the maximum bullets that can be generated in the map is 5, and the bullet sizes will generally be smaller.
- In medium mode, the maximum bullets that can be generated in the map is 15, and the bullet sizes will generally be bigger than easy mode, but smaller than hard mode.
- In hard mode, the maximum bullets that can be generated in the map is 25, and the bullet sizes will generally be bigger.
7. There is a time of invicibility when players get hit, meaning that the player will not lose any hearts eventhough they get hit by bullets.
8. 


# Features

1. The random element of this game will be the bullet speed and direction.
2. The data structure for storing game status is arrays. The array is going to be used to store the scores and the random number that will become the “seed” for the bullet direction.
3. The memory used to store the bullets will be dynamic-memory allocated.
4. The input is the latest player’s score and the output is the high score after the game ends.
5. We are going to put each feature in different files and import them together in the main file which will be run.
