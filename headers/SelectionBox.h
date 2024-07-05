#pragma once

#include <Game.h>

class SelectionBox
{

    private:
        
        const int AlgsNum = 3;
        const int maxLen = 5;
        std::string Names[3] = {"BFS", "DFS", "Dijkstra"};
        std::vector<SDL_Texture*> texArray;

        int fontSize = 30;
        SDL_Color fontColor = {255, 255, 255, 255};
        SDL_Rect dst[3];
        TTF_Font *font;

        SDL_Rect m_pos;
        SDL_Rect block_dst = {800, 10, 200, fontSize+30};

        int AlgsSelection = 0;
        bool ispointed = false;        

    public:

        SelectionBox() {}
        ~SelectionBox() {}

        void init(const char *filename);
        void load(std::string word);

        void update(SDL_Rect *mouse);
        void render();
        void handleEvent(SDL_Event *event);
};