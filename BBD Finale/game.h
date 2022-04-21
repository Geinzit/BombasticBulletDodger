// game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

/*
class that acts as the objects
contains variables that involves the bullets, player, and healing items
*/
class Bullet
{
private:
    int x,y;                  // position(top left position)
    int V_x,V_y;              // speed - change of position in every iteration
    int Size;                 // the square-shape length
public:
    // functions and comments in game.cpp
    int getBulletPos_x();
    int getBulletPos_y();
    int getBulletSize();

    void Move();
    void init(int Mapsize_x, int Mapsize_y, int difficulty);
};

class Player
{
private:
    int x,y;                 // position of the player

public:
    int HP;                  // the player's health

    // functions and comments in game.cpp
    int getPlayerPos_x();
    int getPlayerPos_y();
    void Move(int Mapsize_x, int Mapsize_y);
    void init();
};

class Healing
{
public:
    int x, y;                // position of healing items
    void init(int Mapsize_x, int Mapsize_y);
};

/*
class that acts as game engine
contains variables that involves the map, UI elements, enemies, player
*/
class Game
{
private:
    bool gameOver;                  // boolean to detect game over

    int AfterHitInv;                // the period of invincibility after being hit by a bullet
    int MapSize_x, MapSize_y;       // mapsize
    char Map[105][105];             // array of map

    Player player;                  // class player

    int difficulty;                 // difficulty level
    int maxBulletsNumber;           // maximum bullet numbers spawned in game
    std::vector<Bullet> bullets;    // vector of bullets
    std::vector<Healing> HealItems; // vector of healing items

    void initMap();
    void initVariables();

public:
    // constructor
    Game();

    // checker functions
    bool isRunning();

    // updating & rendering functions
    void updateMap();
    void updatePlayerStatus();
    void updateBulletStatus();
    void spawnHealingItems();
    void update();
    void renderUI();
    void renderMap();
    void render();

    // menu, difficulty, and scoreboard functions
    void printMenu();
    void pickDifficulty();
    void printHighestScore();
    void storeScore(int duration);
};

#endif
