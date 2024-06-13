#include <BFS.h>

bool BFS::solved = true;
node BFS::cur, BFS::nxt;
int BFS::i, BFS::j;
bool BFS::vis[50][50];
node BFS::queue[2000];

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

template<typename T>
void travel(T (&arr)[], int idx)
{   
    node cur = arr[idx];

    while(cur.last != -1)
    {   
        Map::cells[cur.x][cur.y] = Map::PATH;
        cur = arr[cur.last];
    }
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
    solved = false;

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
            std::cout << "BFS Search Complete.";
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
