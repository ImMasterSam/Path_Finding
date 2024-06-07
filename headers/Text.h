#pragma once

#include <Game.h>

class Text
{

    private:

        SDL_Texture* tex = nullptr;
        TTF_Font* font = nullptr;
        SDL_Color color;
        SDL_Rect dst;
        const char* word = "";
        bool active = true;
        int ypos = 0, f_size = 0;
        int StartTime = 0, duration = -1;
    
    public:

        Text();
        ~Text();

        void init(const char* filename, std::string word, SDL_Color c, int size, int y, bool show);

        void render();
        void show_up(int time);
        void set_word(std::string word);

        static void render_text(TTF_Font *font, std::string word)
        {
            SDL_Rect dst;

            dst.w = dst.h = 96;
            dst.x = 352;
            dst.y = 30;

            SDL_Surface *temp = TTF_RenderText_Blended(font, word.c_str(), {255, 255, 255, 70});
            SDL_Texture *text = SDL_CreateTextureFromSurface(Game::renderer, temp);

            SDL_FreeSurface(temp);

            SDL_RenderCopy(Game::renderer, text, NULL, &dst);
            SDL_DestroyTexture(text);
        }

};