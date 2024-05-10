#include <iostream>
#include "Game.h"
#include "logger.h"

Game *game = nullptr;
int main(int argc, char* argv[]) {



    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Time Traveller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               1024, 1024, false);

    Logger::init();
    Logger::getLogger()->info("Game started!");

    while(game->running())
    {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
