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


# Features Implemented
1. Generation of random game sets or events: 
- the starting position of the bullet, its speed, its direction, and its size, and the time when it spawns.
- the position of healing items and the time when it spawns.
- the player's starting position

2. Data structures for storing game status: 
The data structure for storing game status is arrays. The array is going to be used for the map. and the random number that will become the “seed” for the bullet direction.

3. Dynamic memory management: 
We use vectors to store how many bullets and healing items have spawned, thus making it dynamic-memory allocated.

4. File input/output:
The input is the latest player’s score and the output is the high score after the game ends.

5. Program codes in multiple files:
Files involved in coding are seperated in three files. Two .cpp files: "game.cpp", "main.cpp", and 1 .h file: "game.h". "game.cpp" is where the all the functions involved in the game generation are defined. "game.h" is the header file where all the classes are defined. "main.cpp" is where all the functions are called. Additionally, there are makefile, and .txt files to store the score of the players.

# Compilation and execution instructions
1. Use makefile to make the game by typing in terminal: "make game".
2. Initialize the game by typing: "./game".
3. A menu will appear, and you will be asked to press 'E' to start the game.
4. After scoreboard is printed, you will be asked to press '1' to pick easy mode, '2' to pick medium mode, and '3' to pick hard mode.
5. A countdown will start, at which point you could prepare yourself by putting your hands in WASD.
6. When the game starts, press WASD to control player movements
7. When the game ends, press 'E' to exit the game.
