#include "game.h"
#include <ctime>
#include <chrono>
//#include <unistd.h>
int main()
{
    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;

    game.printHighestScore();
    usleep(5000000);
    system("clear");

    for(int i=5; i>0; i--){
      std::cout << "Starting in " << i << std::endl;
      usleep(1000000);
      system("clear");
    }

    auto start = std::chrono::steady_clock::now();
    while(game.isRunning())
    {
        usleep(100000);
        system("clear");
        game.update();
        game.render();
    }
    //storing score to file
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    game.storeScore(duration);

    std::cout << "Game Over!" << std::endl;
    std::cout << "You survived for: " << duration << " secs" << std::endl;
    usleep(5000000);
    return 0;
}
/*
g++ -pedantic-errors -std=c++11 main.cpp game.cpp -o main.exe
*/
