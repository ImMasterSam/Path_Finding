#pragma once

#include <Game.h>

class Text
{

    private:

        SDL_Texture* tex = nullptr;
        TTF_Font* font = nullptr;
        SDL_Color color = {255, 255, 255, 255};
        SDL_Rect dst;
        const char* word = "";
        bool active = true;
        int ypos = 0, f_size = 0;
        int StartTime = 0, duration = -1;
    
    public:

        Text();
        ~Text();

        void init(const char* filename, std::string word, int size, int y);

        void render();
        void show_up(int time);
        void set_word(std::string word);

};