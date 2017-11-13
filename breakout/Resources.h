#pragma once
#include "sdl_helper.h"

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

public:
	SDL_Texture *brickTextures[NUM_COLORS];
	SDL_Texture *paddleTexture;
	SDL_Texture *greyBallTexture;
	SDL_Texture *blueBallTexture;
	TTF_Font *font = NULL;
	Resources(SDLHelper *helper);
	void loadPNGintoTexture(char *fpath, SDL_Texture **texture, SDL_Renderer *renderer);
	void loadTTFfont(char *fpath, int font_size, TTF_Font **font);
	~Resources();
};

