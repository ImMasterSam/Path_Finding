#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

class Game{

    private:
        SDL_Window *window = nullptr;
        SDL_Event event;

        SDL_Rect m_pos;
        bool m_pressed = false;

        bool Running = true;
        int count = 0;

    public:

        Game();
        ~Game();

        void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

        void reset();
        
        void update();
        void render();
        void clean();
        void handleEvent();

        bool isRunning() { return Running; }

        static SDL_Renderer *renderer;
        static int Game_Tick;

};