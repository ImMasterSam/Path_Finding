#pragma once

#include <Game.h>

class Map
{
    private:

        SDL_Rect Cell = {1, 1, 18, 18};
        SDL_Point m_pos = {-1, -1};

        int draw_type = 0;
        bool draw = false;

    public:

        Map();
        ~Map();

        enum
        {
            SPACE,
            WALL,
            START,
            END,
            VISITED,
            PATH,
        };
        
        static void init();

        // Functions
        void update(SDL_Rect &m_pos);
        void render_map();
        void setup();
        void clear();

        // Input Handling
        void handleEvent(SDL_Event *event);
        void draw_mouse(SDL_MouseButtonEvent &b, SDL_Point &m_pos);
        void draw_keyb(SDL_Keycode &k, SDL_Point &m_pos);
        
        
        bool searchable() { return sx!=-1 && sy!=-1 && ex!=-1 && ey != -1; }

        static int cells[40][40];
        int row=40, col=40;
        int sx=-1, sy=-1, ex=-1, ey=-1;
        
};