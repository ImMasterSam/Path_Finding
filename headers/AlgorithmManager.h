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
        
        static std::vector<SDL_Point> path;
        static void displayPath();

        static int currentAlg;
        static bool searching;
        static bool solved;

    public:

        enum Algs
        {
            BFS,
            DFS
        };

        static void StartSearch(Map *map);
        static void update(Map *map);

        static void unSolved() { solved = false;path.clear(); }
        static void Solved() { solved = true; searching = false; }
        static bool isSearching() { return searching; }

        static void setPath(std::vector<SDL_Point> p) { path = p; }
        static void setAlg(Algs a) { currentAlg = a; }

};

