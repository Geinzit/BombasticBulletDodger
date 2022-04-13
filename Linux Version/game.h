// game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
/*
the bullet class
includes:
    size
    speed
    position(center pos)
*/
class Bullet
{
private:
    int x,y;//position(top left position)
    int V_x,V_y;//speed - change of position in every iteration
    int Size;//the square-shape length
public:
    int getBulletPos_x();
    int getBulletPos_y();
    int getBulletSize();

    void Move();
    void init(int Mapsize_x, int Mapsize_y);
};

class Player
{
private:
    int x,y;//position of the player

public:
    int getPlayerPos_x();
    int getPlayerPos_y();

    int HP;//the player's health
    int Clock; //the player's time survived
    void Move(int Mapsize_x, int Mapsize_y);//function that detect keypress and move the player
    void init();
};


/*
class that acts as game engine
contains variables that involves the map, UI elements, enemies, player
*/
class Game
{
private:
    void initMap();
    void initVariables();

    //Variables
    bool gameOver;

    int MapSize_x, MapSize_y;
    char Map[105][105];

    Player player;

    int maxBulletsNumber;
    std::vector<Bullet> bullets;

public:


    //Constructor / Destructor
    Game();

    //checker functions
    bool isRunning();

    //updating & rendering functions
    void updateMap();
    void updatePlayerStatus();
    void updateBulletStatus();
    void update();
    void renderUI();
    void renderMap();
    void render();

    // printing and storing to the scoreboard
    void printHighestScore();
    void storeScore(int duration);
};

#endif
