#pragma once

#include <AlgorithmManager.h>
#include <Map.h>

struct node
{
    int x, y;
    int last;
};

class BFS
{
    private:

        static node cur, nxt;
        static int i, j;

        static bool vis[50][50];
        static node queue[2000];

    public:
    
        static void Setup(Map *map);
        static void Search(Map *map);

};