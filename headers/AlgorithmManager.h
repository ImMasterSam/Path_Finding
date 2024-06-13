#pragma once

#include <Game.h>
#include <Map.h>
#include <vector>

#include <BFS.h>
#include <DFS.h>

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class AlgorithmManager
{

    private:

        enum
        {
            BFS,
            DFS
        };

        static int currentAlg;
        static bool searching;
        static bool solved;

    public:

        static void StartSearch(Map *map);
        static void update(Map *map);

        static void Solved() { solved = true; searching = false; }
        static bool isSearching() { return searching; }

        //static void DFS(Map *map);

};

