#pragma once

#include <AlgorithmManager.h>
#include <Map.h>

class Dijkstra
{
    private:

        struct node
        {
            SDL_Point pos;
            SDL_Point last;
            int dis;
        };

        struct cmp
        {
            bool operator () (const node &a, const node &b)
            {   
                if(a.dis != b.dis)
                {
                    return a.dis > b.dis;
                }
                else
                {
                    if(a.pos.y != b.pos.y)
                    {
                        return a.pos.y < b.pos.y;
                    }
                    else
                    {
                        return a.pos.x < b.pos.x;
                    }
                }

            }
        };

        static node cur, nxt;

        static bool vis[50][50];
        static SDL_Point prev[50][50];
        static std::priority_queue<node, std::vector<node>, cmp> pq;

        static void travel(SDL_Point cur);

    public:
    
        static void Setup(Map *map);
        static void Search(Map *map);

};