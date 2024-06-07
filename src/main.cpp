#include <Game.h>

Game *game = nullptr;

int main(int argc, char *argv[]){

    const int FPS = 1000000;
    const int FrameDelay = 1000 / FPS;

    Uint32 FrameStart;
    int FrameTime;

    game = new Game();
    game->init("Path Finding", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

    while(game->isRunning())
    {

        FrameStart = SDL_GetTicks();
        
        game->update();
        game->render();
        game->handleEvent();

        FrameTime = SDL_GetTicks() - FrameStart;

        if(FrameDelay > FrameTime){

            SDL_Delay(FrameDelay - FrameTime);

        }

    }

    game->clean();

    return EXIT_SUCCESS;
}