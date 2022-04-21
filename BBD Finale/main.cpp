#include "game.h"
#include <ctime>
#include <chrono>

int main()
{
    // initialize srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;

    // printing menu, highest score, and choose difficulty
    system("clear");
    game.printMenu();
    system("clear");
    game.printHighestScore();
    usleep(5000000);
    system("clear");
    game.pickDifficulty();
    system("clear");

    // starting in 5, 4, 3, 2, 1
    for(int i=5; i>0; i--)
    {
        std::cout << "Starting in " << i << std::endl;
        usleep(1000000);
        system("clear");
    }

    // start the timer and let the game run, until the player loses, and stop the timer
    auto start = std::chrono::steady_clock::now();
    while(game.isRunning())
    {
        usleep(100000);
        system("clear");
        game.update();
        game.render();
    }
    auto end = std::chrono::steady_clock::now();

    // storing score to file
    int duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    game.storeScore(duration);

    // printing game over menu
    std::cout << "Game Over!" << std::endl;
    std::cout << "You survived for: " << duration << " secs" << std::endl;
    std::cout << "Type 'E' to Exit..." << std::endl;
    while(true)
    {
        char c;
        c = getchar();
        if(c == 'E')
            break;
    }
    return 0;
}
