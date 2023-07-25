#include "Game.h"
#include "SDL3/SDL.h"
#include <iostream>
#include <string>

const int FPS = 60;
const int DELAY_TIME = 1000.f / FPS;

// our Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    std::cout << "game init attempt...\n";

    char title[] = "2D Game";

    TheGame::Instance()->init(title, 600, 600);

    if (TheGame::Instance()->is_Running())
    {
        std::cout << "game init success!\n";
        while (TheGame::Instance()->is_Running())
        {
            frameStart = SDL_GetTicks();

            TheGame::Instance()->event_handler();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
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