#include <TextureManager.h>

/*         角色 Texture 加載器        */

SDL_Texture* TextureManager::LoadTexture(const char *filename){

    SDL_Texture *tex;

    SDL_Surface *tempSurface = IMG_Load(filename);
    tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    std::cout << "Loaded: " << filename << "\n";

    return tex;

}


void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst){

    SDL_RenderCopy(Game::renderer, tex, &src, &dst);

}