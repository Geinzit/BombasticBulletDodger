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
    //Sleep(5000);//windows
    usleep(5000000);//linux
    system("clear");

    for(int i=5; i>0; i--){
      std::cout << "Starting in " << i << std::endl;
      //Sleep(1000);windows
      usleep(1000000);//linux
      //system("cls");//windows
      system("clear");//linux
    }

    auto start = std::chrono::steady_clock::now();
    while(game.isRunning())
    {
        //Sleep(100);//windows
        usleep(100000);//linux

        //system("cls");//windows
        system("clear");//linux
        game.update();
        game.render();
    }
    //storing score to file
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    game.storeScore(duration);

    std::cout << "Game Over!" << std::endl;
    std::cout << "You survived for: " << duration << " secs" << std::endl;
    std::cout << "Type 'E' to Exit..." << std::endl;
    //while(!(GetKeyState(32) & 0x8000));//windows
    while(true)
    {
      char c;
      c = getchar();
      if(c == 'E')break;
    }
    return 0;
}
/*
g++ -pedantic-errors -std=c++11 main.cpp game.cpp -o main.exe
*/
