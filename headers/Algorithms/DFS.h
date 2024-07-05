#pragma once

#include <AlgorithmManager.h>
#include <Map.h>

class DFS
{

    private:
        
        static SDL_Point curPos, nxtPos;
        static std::vector<SDL_Point> path;
        static bool vis[40][40];

        static void travel(Map *map);

    public:
        
        static void Setup(Map *map);
        static void Search(Map *map);

};