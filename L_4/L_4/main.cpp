#include <iostream>
#include <windows.h>
#include "Game.h"
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));


    Game* game = new Game();

    game->Run();

    return 0;

}