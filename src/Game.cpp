#include <Game.h>
#include <Map.h>
#include <Button.h>
#include <Text.h>
#include <AlgorithmManager.h>

int Game::Game_Tick = 0;
SDL_Renderer *Game::renderer = nullptr;

Map *map = nullptr;
Button *start = nullptr;

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
        // Create
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        renderer = SDL_CreateRenderer(window, -1, 0);

        // Render Settings
        SDL_SetRenderDrawBlendMode(Game::renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Other Seettings
        


        Running = true;
    }

    map = new Map();
    start = new Button();
    start->init("picture/start_button", 820, 730, 40, 15, 4);

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
    }  

    map->update(m_pos);
    start->update(&m_pos);

    // Search
    AlgorithmManager::update(map);

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

    //Button
    start->render();

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
            if(start->ispointed())
                AlgorithmManager::StartSearch(map);
            break;
        case SDL_MOUSEBUTTONUP:
            m_pressed = false;
            break;

        case SDL_KEYDOWN:
            map->draw_keyb(event.key.keysym.sym, m_pos);

            switch(event.key.keysym.sym)
            {
                case SDLK_RETURN:
                    AlgorithmManager::StartSearch(map);
                    break;
                case SDLK_ESCAPE:
                    map->clear();
                    break;
                default:
                    break;
            }

            break;

        default:
            break;

    }
}