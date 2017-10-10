#pragma once
#include "sdl_component.h"

enum BrickColors {
	RED = 0,
	GREEN,
	YELLOW,
	PURPLE,
	BLUE,
	GREY,
	NUM_COLORS
};

class Resources
{

public:
	SDL_Texture *brickTextures[NUM_COLORS];
	SDL_Texture *paddleTexture;
	SDL_Texture *greyBallTexture;
	SDL_Texture *blueBallTexture;
	TTF_Font *font = NULL;
	Resources(SDLComponent *component);
	~Resources();
};

