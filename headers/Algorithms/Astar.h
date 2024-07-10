#pragma once

#include <AlgorithmManager.h>
#include <Map.h>

class Astar
{
    private:

        struct node
        {
            SDL_Point pos;
            SDL_Point last;
            int gValue;
            int hValue;
            int fValue;
        };

        struct cmp
        {
            bool operator () (const node &a, const node &b)
            {   
                if(a.fValue != b.fValue)
                {
                    return a.fValue > b.fValue;
                }
                else
                {
                    if(a.hValue != b.hValue)
                    {
                        return a.hValue > b.hValue;
                    }
                    else
                    {
                        return a.gValue > b.gValue;
                    }
                }
                
            }
        };


        static node cur, nxt;

        static bool vis[50][50];
        static SDL_Point prev[50][50];
        static std::priority_queue<node, std::vector<node>, cmp> pq;

        static void travel(SDL_Point cur);
        static int manhatton_dis(SDL_Point &pos, Map *map)
        {
            return abs(pos.x - map->ex) + abs(pos.y - map->ey);
        }

    public:
    
        static void Setup(Map *map);
        static void Search(Map *map);

};