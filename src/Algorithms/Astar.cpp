#include <Astar.h>

Astar::node Astar::cur, Astar::nxt;
bool Astar::vis[50][50];
SDL_Point Astar::prev[50][50];
std::priority_queue<Astar::node, std::vector<Astar::node>, Astar::cmp> Astar::pq;

void Astar::travel(SDL_Point cur)
{
    std::vector<SDL_Point> path;

    while(prev[cur.x][cur.y].x != -1 && prev[cur.x][cur.y].x != -1)
    {
        path.push_back(cur);
        cur = prev[cur.x][cur.y];
    }

    AlgorithmManager::setPath(path);
}

void Astar::Setup(Map *map)
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
    cur.gValue = 0;
    cur.hValue = manhatton_dis(cur.pos, map);
    cur.fValue = cur.gValue + cur.hValue;
    vis[cur.pos.x][cur.pos.y] = true;

    pq.push(cur);

    std::cout << "Algoritm::A* Setup!\n";

}

void Astar::Search(Map *map)
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
            std::cout << "A* Search Complete.\n";
            travel(cur.last);
            AlgorithmManager::Solved();
            return;
        }

        for(int k=0;k<4;k++)
        {
            nxt = cur;
            nxt.pos.x += dir[k][0];
            nxt.pos.y += dir[k][1];
            nxt.gValue = cur.gValue + 1;
            nxt.hValue = manhatton_dis(nxt.pos, map);
            nxt.fValue = nxt.gValue + nxt.hValue;
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
        std::cout << "A* Search Complete.\n";
        AlgorithmManager::Solved();
    }

}
