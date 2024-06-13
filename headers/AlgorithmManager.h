#pragma once

#include <Game.h>
#include <Map.h>
#include <vector>

#include <BFS.h>

class AlgorithmManager
{

    private:

        enum
        {
            BFS
        };

        static int currentAlg;
        static bool searching;
        static bool solved;

    public:

        static void StartSearch(Map *map);
        static void update(Map *map);

        static void Solved() { solved = true; searching = false; }

        //static void DFS(Map *map);

};

