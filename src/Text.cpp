#include <Game.h>
#include <Text.h>


Text::Text() {}
Text::~Text() {}

void Text::init(const char *filename, std::string w, SDL_Color c, int size, int y, bool show)
{	
	font = TTF_OpenFont(filename, size);
	color = c;
	f_size = size;

	active = (show ? true : false);

	dst.h = f_size;
	dst.y = y;

	set_word(w);

}

void Text::render()
{	

	if(duration != -1 &&Game::Game_Tick - StartTime >= duration)
	{
		duration = -1;
		active = false;
	}

	if(active)
		SDL_RenderCopy(Game::renderer, tex, NULL, &dst);
}

void Text::show_up(int time)
{

	StartTime = Game::Game_Tick;
	duration = time;
	active = true;

}

void Text::set_word(std::string w)
{
	int len = w.size();

	dst.w = f_size * len;
	dst.x = 400 - (dst.w / 2);

	word = w.c_str();

	SDL_Surface* temp = TTF_RenderText_Blended(font, word, color);
	tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
	SDL_FreeSurface(temp);
}
