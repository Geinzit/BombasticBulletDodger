# Bombastic Bullet Dodger

# Team members:
Huang Mao Dian Heinz 3035844077
Dave Henokh Liong 3035902415

# General Description
The player will dodge incoming bullets from all sides of the map by controlling their body. The player has three hearts, and the game ends when the player's health reaches zero (1 bullet deals 1 heart). During the game, healing items will randomly spawn, which will increase the player's heart by 1. After the game ends, the score of the player is printed, which is calculated by how much time the player survives. Goodluck on the battlefield!

# Game rules: 
1. Use WASD to control the player movements (the character '@').
2. In the start of the game, a player has three hearts. When the player runs out of hearts, the game ends. 
3. Don’t touch the bullets (the character '\*')! 1 bullet deals 1 heart.
4. There will be a chance for the player to recover their health by catching healing items (the character '$') that will randomly spawn on the map. If caught, it will increase the health of the player by 1.
5. Be quick in getting the healing items! The healing items will disappear if a bullet passes through it!
6. The score is calculated by how much time the player survives.
7. There are three difficulties: easy, medium, and hard:
- In easy mode, the maximum bullets that can be generated in the map is 5, and the bullet sizes will generally be smaller.
- In medium mode, the maximum bullets that can be generated in the map is 15, and the bullet sizes will generally be bigger than easy mode, but smaller than hard mode.
- In hard mode, the maximum bullets that can be generated in the map is 25, and the bullet sizes will generally be bigger.
8. There is a time of invincibility when players get hit, meaning that the player will not lose any hearts even though they get hit by bullets. The time of invincibility is 5 iterations, and is denoted by "You've been hit!!" message, i.e. you are invincible if there is a "You've been hit!!" message until it disappears.

# Features Implemented
1. Generation of random game sets or events: 
- the player's starting position
- the starting position of the bullet, its speed, its direction, and its size, and the time when it spawns.
- the position of healing items and the time when it spawns.

2. Data structures for storing game status: 
The data structure for storing game status is arrays. The array is going to be used for storing the map and its entities. There is also a string array to store the scoreboard file names, to categorize which score should be included in which file (in easy mode, score will be stored in "Scoreboard_Easy.txt", and so on.

3. Dynamic memory management: 
We use vectors to store how many bullets and healing items have spawned and destroyed, thus making it dynamic-memory allocated. And also pointers that utilize dynamic memory management to create new Healing Items.

4. File input/output:
The input is the player's keypress to start the game, pick difficulty, control the player's movements, and exit the game. The output is the printed menu, updated map every iteration, and score of the player which is stored in a seperate file. 
The score of each game is stored in separate files under each difficulty, and the game will read inputs from the file to produce the top score.

5. Program codes in multiple files:
Files involved in coding are seperated in three files. Two .cpp files: "game.cpp", "main.cpp", and 1 .h file: "game.h". "game.cpp" is where the all the functions involved in the game generation are defined. "game.h" is the header file where all the classes are defined. "main.cpp" is where all the functions are called. Additionally, there are makefile, and .txt files to store the score of the players.

# Compilation and execution instructions
1. There is a makefile to easily compile the game, where flags and necessary commands are already included. Essentially, main.cpp and game.h turns to main.o, and game.cpp and game.h turns to game.o, where game is made from main.o and game.o.
2. Put all of the files attached in this GitHub in one folder, and use makefile to make the game by typing in terminal: "make game".
3. Initialize the game by typing: "./game".
4. A menu will appear, and you will be asked to press 'E' to start the game.
5. After scoreboard is printed, you will be asked to press '1' to pick easy mode, '2' to pick medium mode, and '3' to pick hard mode.
6. A countdown will start, at which point you could prepare yourself by putting your hands in WASD.
7. When the game starts, press WASD to control player movements. Dodge the bullets!
8. When the game ends, press 'E' to exit the game.
9. To remove the game and .o files, type in terminal "make clean".

# Additional notes
Comments of commits in GitHub can be shown by clicking the total commits and looking at the individual comments.
