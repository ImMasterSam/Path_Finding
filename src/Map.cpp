#include <Map.h>
#include <AlgorithmManager.h>

int Map::cells[40][40] = {0};

Map::Map() {}
Map::~Map() {}

void Map::init()
{
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            cells[i][j] = 0;
        }
    }

}

void Map::update(SDL_Rect &pos)
{
    int x = pos.y / 20;
    int y = pos.x / 20;

    m_pos.x = (x<0 || x>=row) ? -1 : x;
    m_pos.y = (y<0 || y>=col) ? -1 : y;
    
}

void Map::render_map()
{
     
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {   

            switch(cells[i][j]){
                
                // SPACE
                case SPACE:
                    SDL_SetRenderDrawColor(Game::renderer, 30, 30, 30, 255);
                    break;
                
                // WALL
                case WALL:
                    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
                    break;
                
                // START
                case START:
                    SDL_SetRenderDrawColor(Game::renderer, 0, 230, 0, 255);
                    break;

                // END
                case END:
                    SDL_SetRenderDrawColor(Game::renderer, 230, 0, 0, 255);
                    break;

                // VISITED
                case VISITED:
                    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 150, 255);
                    break;
                
                // FINAL PATH
                case PATH:
                    SDL_SetRenderDrawColor(Game::renderer, 230, 230, 0, 255);
                    break;

                default:
                    break;

            }

            Cell.y = i*20 + 1;
            Cell.x = j*20 + 1;

            SDL_RenderFillRect(Game::renderer, &Cell); 
        }
    }

    // Mouse Position
    if(m_pos.x != -1 && m_pos.y != -1 )
    {
        Cell.y = m_pos.x*20 + 1;
        Cell.x = m_pos.y*20 + 1;

        switch(draw_type)
        {
            // wall
            case 0:
                SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 50);
                break;
            // start
            case 1:
                SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 50);
                break;
            // end
            case 2:
                SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 50);
                break;

            default:
                SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 50);
                break;
        }

        
        SDL_RenderFillRect(Game::renderer, &Cell); 
    }

}

void Map::setup()
{

    AlgorithmManager::unSolved();

    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(cells[i][j] == VISITED || cells[i][j] == PATH)
                cells[i][j] = SPACE;
        }
    }
}

void Map::clear()
{

    std::cout << "Map Cleared!\n";

    sx = sy = ex = ey = -1;

    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            cells[i][j] = 0;
        }
    }

}

void Map::handleEvent(SDL_Event *event)
{   

    draw_mouse(event->button, m_pos);

    switch(event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            draw = true;
            break;
        case SDL_MOUSEBUTTONUP:
            draw = false;
            break;

        case SDL_MOUSEWHEEL:
            if(event->wheel.y>0)
                draw_type = (draw_type + 1) % 3;
            else if(event->wheel.y<0)
                draw_type = (draw_type + 2) % 3;
            break;

        case SDL_KEYDOWN:
            if(AlgorithmManager::isSearching()) break;

            draw_keyb(event->key.keysym.sym, m_pos);

            switch(event->key.keysym.sym)
            {
                case SDLK_RETURN:
                    AlgorithmManager::StartSearch(this);
                    break;
                case SDLK_ESCAPE:
                    clear();
                    break;
                default:
                    break;
            }
    }

}

void Map::draw_mouse(SDL_MouseButtonEvent &b, SDL_Point &m_pos)
{   

    if(!draw || AlgorithmManager::isSearching()) return;

    int x = m_pos.x;
    int y = m_pos.y;

    if(x == -1 || y == -1)
    {
        return;
    }

    setup();

    switch(b.button)
    {   

        case SDL_BUTTON_LEFT:
            //std::cout << "draw\n";
            switch(draw_type)
            {   
                // wall
                case 0:
                    cells[x][y] = WALL;
                    break;
                // start
                case 1:
                    if(sx != -1 || sy != -1)
                        cells[sx][sy] = SPACE;
                    cells[x][y] = START;
                    sx = x; sy = y;
                    break;
                // end
                case 2:
                    if(ex != -1 || ey != -1)
                        cells[ex][ey] = SPACE;
                    cells[x][y] = END;
                    ex = x; ey = y;
                    break;

                default:
                    break;
            }
            break;

        case SDL_BUTTON_RIGHT:
        case SDL_BUTTON_X1:
            //std::cout << "clear\n";
            cells[x][y] = SPACE;
            if(x == sx && y == sy)
                sx = sy = -1;
            if(x == ex && y == ey)
                ex = ey = -1;

            break;
        
        default:
            //std::cout << "None\n";
            break;
    }
}

void Map::draw_keyb(SDL_Keycode &k, SDL_Point &m_pos)
{   
    int x = m_pos.x;
    int y = m_pos.y;

    if(x == -1 || y == -1)
    {
        return;
    }

    setup();

    switch(k)
    {   

        case SDLK_s:

            if(sx != -1 && sy != -1)
                cells[sx][sy] = SPACE;
            cells[x][y] = START;

            sx = x;
            sy = y;

            break;

        case SDLK_e:

            if(ex != -1 && ey != -1)
                cells[ex][ey] = SPACE;
            cells[x][y] = END;

            ex = x;
            ey = y;
            
            break;
        
        default:
            break;
    }
}
