#include <BFS.h>
#include <vector>

node BFS::cur, BFS::nxt;
int BFS::i, BFS::j;
bool BFS::vis[50][50];
node BFS::queue[2000];

template<typename T>
void travel(T (&arr)[], int idx)
{   
    std::vector<SDL_Point> path;
    node cur = arr[idx];

    while(cur.last != -1)
    {   
        SDL_Point p = {cur.x, cur.y};
        path.push_back(p);
        cur = arr[cur.last];
    }

    AlgorithmManager::setPath(path);
}

void BFS::Setup(Map *map)
{   

    if(!map->searchable()) return;
    
    std::cout << "Algoritm::BFS Setup!\n";

    for(i=0;i<50;i++)
    {
        for(j=0;j<50;j++)
        {
            vis[i][j] = false;
        }
    }

    cur.x = map->sx;
    cur.y = map->sy;
    vis[cur.x][cur.y] = true;
    cur.last = -1;

    i = j = 0;
    queue[j++] = cur;

}

void BFS::Search(Map *map)
{   

    if(i < j)
    {
        cur = queue[i];
        
        if(map->cells[cur.x][cur.y] == Map::SPACE)
            map->cells[cur.x][cur.y] = Map::VISITED;

        if(cur.x == map->ex && cur.y == map->ey)
        {   
            std::cout << "BFS Search Complete.\n";
            travel<node>(queue, cur.last);
            AlgorithmManager::Solved();
            return;
        }

        for(int k=0;k<4;k++)
        {

            nxt = cur;
            nxt.x += dir[k][0];
            nxt.y += dir[k][1];
            nxt.last = i;

            if((nxt.x>=0&&nxt.x<map->row) && (nxt.y>=0&&nxt.y<map->col))
            {
                if(!vis[nxt.x][nxt.y] && map->cells[nxt.x][nxt.y] != Map::WALL)
                {
                    vis[nxt.x][nxt.y] = true;
                    queue[j++] = nxt;
                }
            }

        }

        i++;

    }

}
