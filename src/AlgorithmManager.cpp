#include <AlgorithmManager.h>

int AlgorithmManager::currentAlg =  BFS;
bool AlgorithmManager::searching = false;
bool AlgorithmManager::solved = true;

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

    }

}

void AlgorithmManager::update(Map *map)
{

    if(solved)  return;
    
    if(searching)
    {
        switch(currentAlg)
        {
            case BFS:
                BFS::Search(map);
                break;
            case DFS:
                DFS::Search(map);
                break;
        }
    }
    

}