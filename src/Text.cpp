#include <Game.h>
#include <Text.h>


Text::Text() {}
Text::~Text() {}

void Text::init(const char *filename, std::string w, int size, int y)
{	
	font = TTF_OpenFont(filename, size);
	f_size = size;

	dst.h = f_size;
	dst.y = y;

	set_word(w);

}

void Text::render()
{	
	SDL_RenderCopy(Game::renderer, tex, NULL, &dst);
}

void Text::set_word(std::string w)
{
	int len = w.size();

	dst.w = f_size * len / 2;
	dst.x = 900 - (dst.w / 2);

	word = w.c_str();

	SDL_Surface* temp = TTF_RenderText_Blended(font, word, color);
	tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
	SDL_FreeSurface(temp);
}
