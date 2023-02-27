#include "Game.h"
#include "SDL3/SDL.h"
#include <iostream>
#include <string>

// our Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
    std::cout << "game init attempt...\n";
    char title[] = "Chapter 3";
    TheGame::Instance()->init(title, 640, 480);
    if (TheGame::Instance()->is_Running())
    {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->is_Running())
        {
            TheGame::Instance()->event_handler();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            SDL_Delay(10);
        }
    }
    else
    {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }

    std::cout << "game closing...\n";
    TheGame::Instance()->clean();

    return 0;
}