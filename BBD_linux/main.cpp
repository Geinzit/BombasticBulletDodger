#include "game.h"
int main()
{
    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;
    while(game.isRunning())
    {
        usleep(100000);
        system("clear");
        game.update();
        game.render();
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
}
/*
g++ -pedantic-errors -std=c++11 main.cpp game.cpp -o main.exe
*/
