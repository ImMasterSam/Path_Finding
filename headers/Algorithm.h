#pragma once

#include <Game.h>
#include <Map.h>
#include <vector>

struct node
{
    int x, y;
    int last;
};

class Algorithm
{

    private:

        static node cur, nxt;
        static int i, j;

        static bool vis[50][50];
        static node queue[2000];

    public:

        static bool solved;

        static void Setup(Map *map);

        static void BFS(Map *map);
        //static void DFS(Map *map);

};