#include <Game.h>
#include <Map.h>
#include <Text.h>
#include <Algorithm.h>

int Game::Game_Tick = 0;
SDL_Renderer *Game::renderer = nullptr;

Map *map = nullptr;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flag = 0;

    if(fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        Running = true;
    }

    map = new Map();

    reset();

}

void Game::reset()
{   
    Game_Tick = 0;
}

void Game::update()
{   

    if(m_pressed)
    {
        map->draw_mouse(event.button, m_pos);
        map->setup();
    }  

    //std::cout << map->searchable() << " : " << Algorithm::solved << "\n";
    map->update(m_pos);

    // Search
    if(!Algorithm::solved)
        Algorithm::BFS(map);

    Game_Tick++;
    //std::cout << m_pressed << "\n";
    //std::cout << Game_Tick << " -> " << game_status << "\n";
    
}

void Game::render()
{      
    // background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Map
    map->render_map();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
}

void Game::handleEvent()
{
    SDL_PollEvent(&event);

    switch(event.type)
    {

        case SDL_QUIT:
            Running = false;
            break;

        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&m_pos.x, &m_pos.y);
            break;
        
        case SDL_MOUSEBUTTONDOWN:
            m_pressed = true;
            break;
        case SDL_MOUSEBUTTONUP:
            m_pressed = false;
            break;

        case SDL_KEYDOWN:
            map->draw_keyb(event.key.keysym.sym, m_pos);
            if(map->searchable())
                map->setup();

            if(event.key.keysym.sym == SDLK_RETURN)
                Algorithm::Setup(map);

            break;

        default:
            break;

    }
}