#include <DFS.h>

SDL_Point DFS::curPos, DFS::nxtPos;
std::vector<SDL_Point> DFS::path;
bool DFS::vis[40][40];

void DFS::travel(Map *map)
{

    for(SDL_Point &p : path)
    {
        if((p.x == map->sx && p.y == map->sy) || (p.x == map->ex && p.y == map->ey))
            continue;
        
        Map::cells[p.x][p.y] = Map::PATH;
    }

}

void DFS::Setup(Map *map)
{

    std::cout << "Algoritm::DFS Setup!\n";

    path.clear();

    for(int i=0;i<40;i++)
    {
        for(int j=0;j<40;j++)
        {
            vis[i][j] = false;
        }
    }

    curPos.x = map->sx;
    curPos.y = map->sy;
    vis[curPos.x][curPos.y] = true;

}

void DFS::Search(Map *map)
{   

    for(int i=0;i<4;i++)
    {
        nxtPos.x = curPos.x + dir[i][0];
        nxtPos.y = curPos.y + dir[i][1];

        if((nxtPos.x<0 || nxtPos.x>=40) || (nxtPos.y<0 || nxtPos.y>=40))
            continue;

        if(nxtPos.x == map->ex && nxtPos.y == map->ey)
        {   
            travel(map);
            AlgorithmManager::Solved();
            std::cout << "DFS Search Complete.\n";
            return;
        }

        if(!vis[nxtPos.x][nxtPos.y] && map->cells[nxtPos.x][nxtPos.y] != Map::WALL)
        {
            vis[nxtPos.x][nxtPos.y] = true;
            map->cells[nxtPos.x][nxtPos.y] = Map::VISITED;
            path.push_back(nxtPos);
            curPos = nxtPos;
            return;
        }

    }
    
    // else
    path.pop_back();
    curPos = path[path.size()-1];

}