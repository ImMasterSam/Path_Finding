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

    m_pos.x = x;
    m_pos.y = y;
    
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
    if((m_pos.x>=0 && m_pos.x<row) && (m_pos.y>=0 && m_pos.y<col))
    {
        Cell.y = m_pos.x*20 + 1;
        Cell.x = m_pos.y*20 + 1;
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 50);
        SDL_RenderFillRect(Game::renderer, &Cell); 
    }

}

void Map::setup()
{

    std::cout << "Map Setup For Search!\n";

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

void Map::draw_mouse(SDL_MouseButtonEvent &b, SDL_Rect &m_pos)
{   
    int x = m_pos.y / 20;
    int y = m_pos.x / 20;

    if((x<0 || x>=row) || (y<0 || y>=col))
    {
        return;
    }

    setup();

    switch(b.button)
    {   

        case SDL_BUTTON_LEFT:
            //std::cout << "draw\n";
            cells[x][y] = WALL;
            break;

        case SDL_BUTTON_RIGHT:
        case SDL_BUTTON_X1:
            //std::cout << "clear\n";
            cells[x][y] = SPACE;
            break;
        
        default:
            //std::cout << "None\n";
            break;
    }
}

void Map::draw_keyb(SDL_Keycode &k, SDL_Rect &m_pos)
{   
    int x = m_pos.y / 20;
    int y = m_pos.x / 20;

    if((x<0 && x>=row) && (y<0 && y>=col))
    {
        return;
    }

    setup();

    switch(k)
    {   

        case SDLK_s:

            if(sx != -1 && sy != -1)
                cells[sx][sy] = WALL;
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
