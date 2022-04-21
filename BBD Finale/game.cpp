#include "game.h"
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <string>

// detect keyboard input function
int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// ----------------------------------------------------     INITIALIZATIONS   ------------------------------------------------------------------------------
// ----------------------------------------------------FUNCTIONS INVOLVING THE BULLETS---------------------------------------------------------------

// function to move the bullets in the map
void Bullet::Move()
{
    this->x += this->V_x;
    this->y += this->V_y;
}

// function to initialize the whereabouts of the bullets in the map, as well as the speed, and size
void Bullet::init(int Mapsize_x,int Mapsize_y, int difficulty)
{
    int randNum = rand()%4 + 1;

    // initialize bullets at top of map, going down to bottom of map, with random horizontal movements
    if (randNum == 1)
    {
        this->x = 0;
        this->y = rand() % Mapsize_y;
        this->V_x = 1;
        this->V_y = rand()%3 - 1;
    }

    // initialize bullets at bottom of map, going up to top of map, with random horizontal movements
    if (randNum == 2)
    {
        this->x = Mapsize_x - 1;
        this->y = rand() % Mapsize_y;
        this->V_x = -1;
        this->V_y = rand()%3 - 1;
    }

    // initialize bullets at LHS of map, going right to RHS of map, with random vertical movements
    if (randNum == 3)
    {
        this->x = rand() % Mapsize_x;
        this->y = 0;
        this->V_x = rand()%3 - 1;
        this->V_y = 1;
    }

    // initialize bullets at RHS of map, going left to LHS of map, with random vertical movements
    if (randNum == 4)
    {
        this->x = rand() % Mapsize_x;
        this->y = Mapsize_y - 1;
        this->V_x = rand()%3 - 1;
        this->V_y = -1;
    }

    // if difficulty is easy, size of bullets will more likely be smaller
    if (difficulty == 1)
    {
        int parameter[] = {1, 1, 2, 2, 3, 3, 3, 4, 4 ,5};
        this->Size = parameter[rand() % 10];
    }

    // if difficulty is medium, size of bullets will more likely be larger than easy but smaller than hard
    else if(difficulty == 2)
    {
        int parameter[] = {1, 2, 2, 3, 3, 3, 4, 4 ,5, 5};
        this->Size = parameter[rand() % 10];
    }

    // if difficulty is hard, size of bullets will more likely be bigger
    else
    {
        int parameter[] = {1, 2, 3, 3, 4, 4, 4, 5 ,5, 5};
        this->Size = parameter[rand() % 10];
    }
}

// function to get bullet position in the vertical axis
int Bullet::getBulletPos_x()
{
    return this->x;
}

// function to get bullet position in the horizontal axis
int Bullet::getBulletPos_y()
{
    return this->y;
}

// function to get bullet size
int Bullet::getBulletSize()
{
    return this->Size;
}

// ----------------------------------------------------FUNCTIONS INVOLVING THE PLAYER---------------------------------------------------------------

// function to retrieve the x coordinate of the player
int Player::getPlayerPos_x()
{
    return this->x;
}

// function to retrieve the y coordinate of the player
int Player::getPlayerPos_y()
{
    return this->y;
}

// function to detect keypressing and change the player's coordinate
void Player::Move(int Mapsize_x, int Mapsize_y)
{
    // use WASD to detect movements
    if(kbhit())
    {
        char c = getchar();
        if(this->y > 0 && (c == 'A' || c == 'a'))this->y--;
        if(this->y < Mapsize_y - 1 && (c == 'D' || c == 'd'))this->y++;
        if(this->x > 0 && (c == 'W' || c == 'w'))this->x--;
        if(this->x < Mapsize_x - 1 && (c == 'S' || c == 's'))this->x++;
    }
}

// function to initialize the player coordinate and health
void Player::init()
{
    this->x = rand()%11 + 5;
    this->y = rand()%21 + 10;
    this->HP = 3;
}

// ----------------------------------------------------FUNCTIONS INVOLVING HEALING---------------------------------------------------------------

// function to initialize the whereabouts of the healing items in the map
void Healing::init(int Mapsize_x,int Mapsize_y)
{
    this->x = rand() % Mapsize_x;
    this->y = rand() % Mapsize_y;
}

// ----------------------------------------------------FUNCTIONS INVOLVING GAME---------------------------------------------------------------

// function to initialize the map size
void Game::initMap()
{
    this->MapSize_x = 20;
    this->MapSize_y = 40;
}

/*
    Initializing:
        the player elements
        the bullets elements
        UI elements
*/

// function to initialize essential variables in map
void Game::initVariables()
{
    this->gameOver = false;

    this->player.init();
    this->bullets.clear();
    this->HealItems.clear();

    // difficulty level changes the maximum bullet number shown in the map
    if (this->difficulty==1) this->maxBulletsNumber = 5;
    else if (this->difficulty==2) this->maxBulletsNumber = 15;
    else if (this->difficulty==3) this->maxBulletsNumber = 25;
}

// constructor
Game::Game()
{
    this->initMap();
    this->initVariables();
}

// ----------------------------------------------------     GAME FUNCTIONS   ------------------------------------------------------------------------------

// ----------------------------------------------------RUNNING---------------------------------------------------------------

// if !gameOver is true, stop the game
bool Game::isRunning()
{
    return !gameOver;
}

//---------------------------------------------------UPDATING STATUS------------------------------------------------------------

// function to update the map constantly
void Game::updateMap()
{
    // resetting the map
    for(int i = 0; i < this->MapSize_x; i++)
    {
        for(int j = 0; j < this->MapSize_y; j++)
        {
            this->Map[i][j]='.';
        }
    }

    // updating the positions of all bullets in the map
    for(unsigned int i = 0; i < this->bullets.size(); i++)
    {
        int sz = this->bullets[i].getBulletSize();
        int x = this->bullets[i].getBulletPos_x(), y = this->bullets[i].getBulletPos_y();

        for(int j = 0; j < sz; j++)
            for(int k = 0; k < sz; k++)
                if(x + j >= 0 && x + j < this->MapSize_x && y + k >= 0 && y + k < this->MapSize_y)
                    this->Map[x + j][y + k] = '*';
    }

    // checking for player's collision with bullets
    char Pos = this->Map[this->player.getPlayerPos_x()][this->player.getPlayerPos_y()];
    if(Pos == '*')
    {
        if(this->AfterHitInv == 0)
        {
            this->player.HP--;
            if(player.HP <= 0)this->gameOver = true;
            this->AfterHitInv++;
        }
    }

    // counting down the time of invincibility
    if(this->AfterHitInv)this->AfterHitInv = (this->AfterHitInv + 1) % 10;

    // updating the position of the player
    this->Map[this->player.getPlayerPos_x()][this->player.getPlayerPos_y()] = '@';

    // updating the positions of health items in the map
    for(unsigned int i = 0; i < this->HealItems.size();)
    {
        int x = this->HealItems[i].x, y = this->HealItems[i].y;
        if(this->Map[x][y] == '*')this->HealItems.erase(this->HealItems.begin() + i);
        else if(this->Map[x][y] == '@') this->player.HP++, this->HealItems.erase(this->HealItems.begin() + i);
        else Map[x][y] = '$', i++;
    }
}


// function to update the player status
void Game::updatePlayerStatus()
{
    player.Move(this->MapSize_x, this->MapSize_y);
}

// function to update the bullet status
void Game::updateBulletStatus()
{
    //Moving all the current bullet
    for(unsigned int i = 0; i < this->bullets.size();)
    {
        this->bullets[i].Move();

        int x = this->bullets[i].getBulletPos_x(), y = this->bullets[i].getBulletPos_y(), sz=this->bullets[i].getBulletSize();

        //check if the bullet is outside the map, delete it if so
        if(x >= this->MapSize_x || y >= this->MapSize_y || x + sz -1 < 0 || y + sz - 1 < 0)
            this->bullets.erase(this->bullets.begin() + i);
        else i++;
    }

    // creating a new bullets by chance
    if(this->maxBulletsNumber > this->bullets.size() && rand() % (5 - this->difficulty) == 0)
    {
        Bullet newBullet;
        newBullet.init(this->MapSize_x, this->MapSize_y, this->difficulty);
        this->bullets.push_back(newBullet);
    }


}

// function to spawn healing items in the map
void Game::spawnHealingItems()
{
    if(rand() % 50 <= (7 - this->player.HP - (int)(this->HealItems.size() - this->difficulty)))
    {
        Healing *newHealItem = new Healing;

        while(true)
        {
            newHealItem->init(this->MapSize_x, this->MapSize_y);
            bool p = 0;
            for(unsigned int i = 0; i < this->HealItems.size(); i++)
            {
                if(this->HealItems[i].x == newHealItem->x && this->HealItems[i].y == newHealItem->y)
                {
                    p = 1;
                    break;
                }
            }
            if(!p)
                break;
        }

        this->HealItems.push_back(*newHealItem);
        delete newHealItem;
    }
}

// function to compile all the update functions to one function
void Game::update()
{
    updateBulletStatus();
    spawnHealingItems();
    updatePlayerStatus();
    updateMap();
}

//---------------------------------------------------------------------------RENDERING------------------------------------------------------------------------------------------//

// function to render UI
void Game::renderUI()
{
    std::cout << "Health: " << this->player.HP << "\n";
}

// function to render map
void Game::renderMap()
{
    for(int i = 0; i < this->MapSize_x; i++)
    {
        for(int j = 0; j < this->MapSize_y; j++)
        {
            std::cout << this->Map[i][j];
        }
        std::cout << "\n";
    }
    if(this->AfterHitInv)std::cout<<"You've been hit!!"<<"\n";
}

// function to compile all the render functions to one function
void Game::render()
{
    renderUI();
    renderMap();
}

//---------------------------------------------------- MENU, DIFFICULTY, SCOREBOARD --------------------------------------------------------

// function to print menu
void Game::printMenu()
{
    std::string sentence[4]={"Welcome to Bombastic Bullet Dodger", "  The task is simple for you...   ",
    "       Dodge the bullets!         ", "        Press 'E' to start!       "};

    for(int i=0; i<4; i++)
    {
        std::cout << "+-------------------------------------------+" << "\n";
        std::cout << "|     " << sentence[i] << "    |" << "\n";
        std::cout << "+-------------------------------------------+" << "\n";
        if (i==3)
            break;
        sleep(2);
        system("clear");
    }

    // awaiting 'E' from player
    while(true)
    {
        char c;
        c = getchar();
        if(c == 'E')
            break;
    }
}

// function to pick difficulty
void Game::pickDifficulty(){
    std::cout << "+-------------------------------------------+" << "\n";
    std::cout << "|             Pick difficulty:              |" << "\n";
    std::cout << "|             1. Easy   (Press 1)           |" << "\n";
    std::cout << "|             2. Medium (Press 2)           |" << "\n";
    std::cout << "|             3. Hard   (Press 3)           |" << "\n";
    std::cout << "+-------------------------------------------+" << "\n";

    while(true){
        char c;
        c = getchar();
        if (c == '1')
        {
            this->difficulty = 1;
            break;
        }
        else if(c == '2')
        {
            this->difficulty = 2;
            break;
        }
        else if(c == '3')
        {
            this->difficulty = 3;
            break;
        }
    }

}

// function to print highest score
void Game::printHighestScore()
{
    std::string sentence[3]={"Scoreboard_Easy.txt", "Scoreboard_Med.txt", "Scoreboard_Hard.txt"};

    std::cout << "+-------------------------------------------+" << "\n";
    std::cout << "|                                           |" << "\n";
    for(int j=0; j<3; j++)
    {
        // getting file from scoreboard text
      	std::ifstream fin (sentence[j]);
      	int x, highest = -1;
      	while (fin >> x)
        {
            if (x > highest)
        		  highest = x;
        }
        fin.close();

        // printing the highest score
        if(j==0)
            std::cout << "|              IN EASY MODE:                |" << "\n";
        else if(j==1)
            std::cout << "|             IN MEDIUM MODE:               |" << "\n";
        else if(j==2)
            std::cout << "|              IN HARD MODE:                |" << "\n";
        if (highest <= 9)
            std::cout << "|  Longest time a player survived: 0" << highest << "  secs |" << "\n";
        else if (highest > 9)
            std::cout << "|  Longest time a player survived: " << highest << "  secs |" << "\n";
        std::cout << "|                                           |" << "\n";
    }
    std::cout << "+-------------------------------------------+" << "\n";
}

// function to store the score in the scoreboard file
void Game::storeScore(int duration)
{
    std::string sentence[3]={"Scoreboard_Easy.txt", "Scoreboard_Med.txt", "Scoreboard_Hard.txt"};
    std::ofstream fout(sentence[(this->difficulty)-1], std::ios::app);

  	fout << duration << "\n";
    fout.close();
}
