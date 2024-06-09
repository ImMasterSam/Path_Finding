#pragma once

#include <Game.h>
#include <TextureManager.h>

class Button
{

    private:

        SDL_Texture *tex1, *tex2;
        SDL_Rect src, dst;
        SDL_Rect *mouse;

        SDL_Point pos;
        int width, height;

        bool show = true;

    public:

        Button();
        ~Button();

        void init(const char *filename, int x, int y, int w, int h, int scale);
        void update(SDL_Rect *m);
        void render();

        bool ispointed();

};