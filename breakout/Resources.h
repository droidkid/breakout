#pragma once
#include "sdl_system.h"

enum BrickColors {
	RED = 0,
	GREEN,
	YELLOW,
	PURPLE,
	BLUE,
	GREY,
	NUM_COLORS
};

class Resources {

	void loadPNGintoTexture(char *fpath, SDL_Texture **texture, SDL_Renderer *renderer);
	void loadTTFfont(char *fpath, int font_size, TTF_Font **font);
public:
	Resources(SDLSystem *sdl);
	~Resources();
	SDL_Texture *brickTextures[NUM_COLORS];
	SDL_Texture *paddleTexture;
	SDL_Texture *greyBallTexture;
	SDL_Texture *blueBallTexture;
	TTF_Font *font;
};

