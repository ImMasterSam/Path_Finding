#include <Analyzer.h>
#include <AlgorithmManager.h>

std::string Analyzer::time_word = "";
std::string Analyzer::pathlength_word = "";

Text *Analyzer::pathlength_text = nullptr;
Text *Analyzer::pathlength = nullptr;
Text *Analyzer::time_text = nullptr;
Text *Analyzer::time = nullptr;

long long Analyzer::processTime = 0;

void Analyzer::init()
{
    pathlength_text = new Text();
    pathlength_text->init("FFFFORWA.TTF", "-- Path Length --", 20, 100);
    pathlength = new Text();
    pathlength->init("FFFFORWA.TTF", "#######", 20, 150);
    time_text = new Text();
    time_text->init("FFFFORWA.TTF", "-- Exe. Time --", 20, 200);
    time = new Text();
    time->init("FFFFORWA.TTF", "#######", 20, 250);
}

void Analyzer::update()
{   

    if(processTime == 0)
        time_word = "#######";
    else
    {   
        //std::cout << "ProcessTime: " << processTime << "\n";

        long long temp = processTime;
        time_word = " ms";
        while(temp){

            if(time_word.size() == 6){

                time_word = "." + time_word;
                continue;

            }

            time_word = (char)(temp%10 + '0') + time_word;
            temp /= 10;

        }
        

    }

    time->set_word(time_word);

    //std::cout << "Path Size: " << AlgorithmManager::getPathSize() << "\n";

    if(AlgorithmManager::getPathSize() == 0)
        pathlength->set_word("#######");
    else
    {
        long long temp = AlgorithmManager::getPathSize();
        pathlength_word = "";
        while(temp){

            pathlength_word = (char)(temp%10 + '0') + pathlength_word;
            temp /= 10;

        }
        pathlength->set_word(pathlength_word);
    }

}

void Analyzer::render()
{
    pathlength_text->render();
    pathlength->render();
    time_text->render();
    time->render();
}