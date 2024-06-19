#pragma once

#include <Game.h>
#include <Text.h>

class Analyzer
{

    private:

        
        static std::string time_word;
        static std::string pathlength_word;

        static Text *pathlength_text;
        static Text *pathlength;
        static Text *time_text;
        static Text *time;

    public:

        static long long processTime;

        static void init();
        static void update();
        static void render();

};