#pragma once

#include <Game.h>

class Map
{
    private:

        SDL_Rect Cell = {1, 1, 18, 18};

    public:

        Map();
        ~Map();
        
        static void init();
        void update(SDL_Rect &m_pos);
        void draw_mouse(SDL_MouseButtonEvent &b, SDL_Rect &m_pos);
        void draw_keyb(SDL_Keycode &k, SDL_Rect &m_pos);
        void render_map();
        
        bool searchable() { return sx!=-1 && sy!=-1 && ex!=-1 && ey != -1; }

        static int cells[40][40];
        int row=40, col=40;
        int sx=-1, sy=-1, ex=-1, ey=-1;
        
};