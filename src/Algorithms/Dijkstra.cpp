#include <Dijkstra.h>

Dijkstra::node Dijkstra::cur, Dijkstra::nxt;
bool Dijkstra::vis[50][50];
SDL_Point Dijkstra::prev[50][50];
std::priority_queue<Dijkstra::node, std::vector<Dijkstra::node>, Dijkstra::cmp> Dijkstra::pq;

void Dijkstra::travel(SDL_Point cur)
{   
    std::vector<SDL_Point> path;

    while(prev[cur.x][cur.y].x != -1 && prev[cur.x][cur.y].x != -1)
    {   
        path.push_back(cur);
        cur = prev[cur.x][cur.y];
    }

    AlgorithmManager::setPath(path);
}

void Dijkstra::Setup(Map *map)
{   

    if(!map->searchable()) return;
    
    decltype(pq)().swap(pq);

    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            vis[i][j] = false;
        }
    }

    cur.pos.x = map->sx;
    cur.pos.y = map->sy;
    cur.last = {-1, -1};
    cur.dis = 0;
    vis[cur.pos.x][cur.pos.y] = true;

    pq.push(cur);

    std::cout << "Algoritm::Dijkstra Setup!\n";

}

void Dijkstra::Search(Map *map)
{   

    if(pq.size())
    {
        cur = pq.top();
        pq.pop();

        prev[cur.pos.x][cur.pos.y] = cur.last;
        
        if(map->cells[cur.pos.x][cur.pos.y] == Map::SPACE)
            map->cells[cur.pos.x][cur.pos.y] = Map::VISITED;

        if(cur.pos.x == map->ex && cur.pos.y == map->ey)
        {   
            std::cout << "Dijkstra Search Complete.\n";
            travel(cur.last);
            AlgorithmManager::Solved();
            return;
        }

        for(int k=0;k<4;k++)
        {
            nxt = cur;
            nxt.pos.x += dir[k][0];
            nxt.pos.y += dir[k][1];
            nxt.dis = cur.dis + 1;
            nxt.last = {cur.pos.x, cur.pos.y};

            if((nxt.pos.x>=0&&nxt.pos.x<map->row) && (nxt.pos.y>=0&&nxt.pos.y<map->col))
            {
                if(!vis[nxt.pos.x][nxt.pos.y] && map->cells[nxt.pos.x][nxt.pos.y] != Map::WALL)
                {   
                    vis[nxt.pos.x][nxt.pos.y] = true;
                    pq.push(nxt);
                }
            }

        }

    }
    else
    {
        std::cout << "Dijkstra Search Complete.\n";
        AlgorithmManager::Solved();
    }

}
