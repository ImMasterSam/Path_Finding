#include <AlgorithmManager.h>

std::vector<SDL_Point> AlgorithmManager::path;
int AlgorithmManager::currentAlg =  BFS;
bool AlgorithmManager::searching = false;
bool AlgorithmManager::solved = true;

void AlgorithmManager::displayPath()
{
    for(SDL_Point &p : path)
    {
        Map::cells[p.x][p.y] = Map::PATH;
    }
}

void AlgorithmManager::StartSearch(Map *map)
{
    
    std::cout << "Start Searching ...\n";

    if(!map->searchable())
        return;

    solved = false;
    searching = true;

    switch(currentAlg)
    {
        case BFS:
            BFS::Setup(map);
            break;
        case DFS:
            DFS::Setup(map);
            break;
        case Dijkstra:
            Dijkstra::Setup(map);
            break;

    }
    
}

void AlgorithmManager::update(Map *map)
{

    displayPath();
    
    if(searching)
    {
        auto ProcessStart = Clock::now();

        switch(currentAlg)
        {
            case BFS:
                BFS::Search(map);
                break;
            case DFS:
                DFS::Search(map);
                break;
            case Dijkstra:
                Dijkstra::Search(map);
                break;
        }

        Analyzer::processTime += std::chrono::duration_cast<std::chrono::microseconds>(Clock::now()-ProcessStart).count();

    }
    

}