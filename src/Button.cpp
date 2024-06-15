#include <Button.h>
#include <AlgorithmManager.h>

Button::Button() {}
Button::~Button() {}

void Button::init(const char *filename, int x, int y, int w, int h, int scale)
{   
    std::string name = filename;

    tex1 = TextureManager::LoadTexture((name + "_1.png").c_str());
    tex2 = TextureManager::LoadTexture((name + "_2.png").c_str());

    src = {0, 0, w, h};
    dst = {x, y, w*scale, h*scale};

    pos = {x, y};
    width = x;
    height = y;

    show = true;

}

void Button::update(SDL_Rect *m)
{
    dst.x = pos.x;
    dst.y = pos.y;

    mouse = m;
}

void Button::render()
{   
    if(!show) return;

    if(!ispointed())
        TextureManager::Draw(tex1, src, dst);
    else
        TextureManager::Draw(tex2, src, dst);
}

bool Button::ispointed()
{
    
    if((mouse->x >= pos.x && mouse->x <= (pos.x + width)) && (mouse->y >= pos.y && mouse->y <= (pos.y + height)))
        return true;
    else
        return false;

}

void Button::handleEvent(SDL_Event *event, Map *map)
{

    switch(event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(ispointed())
                AlgorithmManager::StartSearch(map);
            else
                return;

        default:
            return;

    }

}