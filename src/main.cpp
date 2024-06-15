#include <Game.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

Game *game = nullptr;

int main(int argc, char *argv[]){

    const int FPS = 60;
    const int FrameDelay = 1000 / FPS;

    Uint32 FrameStart;
    int FrameTime;

    game = new Game();
    game->init("Path Finding", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, false);

    while(game->isRunning())
    {
        FrameStart = SDL_GetTicks();
        auto ProcessStart = Clock::now();

        game->update();
        game->render();
        game->handleEvent();

        auto ProcessEnd = Clock::now();
        //std::cout << "Processing Time -> " << std::chrono::duration_cast<std::chrono::microseconds>(ProcessEnd - ProcessStart).count() << " us \r";

        FrameTime = SDL_GetTicks() - FrameStart;

        if(FrameDelay > FrameTime){

            SDL_Delay(FrameDelay - FrameTime);

        }

    }

    game->clean();

    return EXIT_SUCCESS;
}