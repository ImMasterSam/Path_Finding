#include <Algorithm.h>

bool Algorithm::solved = true;
node Algorithm::cur, Algorithm::nxt;
int Algorithm::i, Algorithm::j;
bool Algorithm::vis[50][50];
node Algorithm::queue[2000];

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

template<typename T>
void travel(T (&arr)[], int idx)
{   
    node cur = arr[idx];

    while(cur.last != -1)
    {   
        Map::cells[cur.x][cur.y] = 100;
        cur = arr[cur.last];
    }

}

void Algorithm::Setup(Map *map)
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

void Algorithm::BFS(Map *map)
{   

    if(i < j)
    {
        cur = queue[i];
        
        if(map->cells[cur.x][cur.y] == 0)
            map->cells[cur.x][cur.y] = 5;

        if(cur.x == map->ex && cur.y == map->ey)
        {   
            travel<node>(queue, cur.last);
            solved = true;
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
                if(!vis[nxt.x][nxt.y] && map->cells[nxt.x][nxt.y] != 1)
                {
                    vis[nxt.x][nxt.y] = true;
                    queue[j++] = nxt;
                }
            }

        }

        i++;

    }

}


// void dfs_progress(Map *map, std::vector<std::vector<bool> > &vis, std::vector<std::pair<int, int> > &path, int x, int y, bool &found)
// {   

//     if(found)
//         return;

//     if(x == map->ex && y == map->ey)
//     {   
//         found = true;
//         return;
//     }
    
//     for(int i=0;i<4;i++)
//     {
//         int tx = x + dir[i][0];
//         int ty = y + dir[i][1];
        
//         if((tx>=0&&tx<map->row) && (ty>=0&&ty<map->col) && !(vis[tx][ty]))
//         {   

//             if(map->cells[tx][ty] == 0)
//                 map->cells[tx][ty] = 5;
            
//             vis[tx][ty] = true;
//             path.emplace_back(tx, ty);
//             dfs_progress(map, vis, path, tx, ty, found);

//             if(found){
                
//                 if(map->cells[path[path.size()-1].first][path[path.size()-1].second] == 5)
//                     map->cells[path[path.size()-1].first][path[path.size()-1].second] = 100;

//                 path.pop_back();
//                 return;

//             }
                

//             vis[tx][ty] = false;
//             path.pop_back();

//         }

//     }

// }

// void Algorithm::DFS(Map *map)
// {

//     std::vector<std::vector<bool> > vis (map->row, std::vector<bool> (map->col, false));
//     std::vector<std::pair<int, int> > path;

//     bool found = false;
//     vis[map->sx][map->sy] = true;

//     dfs_progress(map, vis, path, map->sx, map->sy, found);

// }
