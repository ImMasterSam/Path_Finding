#include <SelectionBox.h>
#include <AlgorithmManager.h>

void SelectionBox::init(const char *filename)
{   

    std::cout << "Selection Box Start Initializing...\n";
    
    font = TTF_OpenFont(filename, fontSize);

    if(font == NULL)
        std::cout << SDL_GetError() << "\n";
    
    for(int i=0;i<AlgsNum;i++)
    {
        
        int len = Names[i].size();

        dst[i].x = 900 - len*(fontSize/4);
        dst[i].y = 25;
        dst[i].w = len * fontSize/2;
        dst[i].h = fontSize;
        load(Names[i]);
    }

    std::cout << "Selection Box Initialized!\n";

}

void SelectionBox::load(std::string word)
{   

    SDL_Surface *temp = TTF_RenderText_Blended(font, word.c_str(), fontColor);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, temp);

    if(tex == NULL)
        std::cout << SDL_GetError() << "\n";

    texArray.push_back(tex);
	SDL_FreeSurface(temp);

}

void SelectionBox::update(SDL_Rect *mouse)
{   

    if(!AlgorithmManager::isSearching())
    {
        switch (AlgsSelection)
        {
            case 0:
                AlgorithmManager::setAlg(AlgorithmManager::Algs::BFS);
                break;
            case 1:
                AlgorithmManager::setAlg(AlgorithmManager::Algs::DFS);
                break;
            case 2:
                AlgorithmManager::setAlg(AlgorithmManager::Algs::Dijkstra);
                break;
            case 3:
                AlgorithmManager::setAlg(AlgorithmManager::Algs::Astar);
                break;
            
            default:
                break;
        }
    }

    if((mouse->x>=800 && mouse->x<=1000) && (mouse->y>=25 && mouse->y<=25+fontSize))
        ispointed = true;
    else
        ispointed = false;
}

void SelectionBox::render()
{
    SDL_RenderCopy(Game::renderer, texArray[AlgsSelection], NULL, &dst[AlgsSelection]);

    if(ispointed)
    {   
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 30);
        SDL_RenderFillRect(Game::renderer, &block_dst);
    }
        

}

void SelectionBox::handleEvent(SDL_Event *event)
{

    if(!ispointed) return;

    switch(event->type)
    {

        case SDL_MOUSEWHEEL:
            if(event->wheel.y>0)
                AlgsSelection = (AlgsSelection + 1) % AlgsNum;
            else if(event->wheel.y<0)
                AlgsSelection = (AlgsSelection + AlgsNum-1) % AlgsNum;
            break;

    }

}