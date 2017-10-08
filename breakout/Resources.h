#pragma once
#include "sdl_component.h"

class Resources
{
public:
	SDL_Texture *greenBrickTexture;
	SDL_Texture *greyBallTexture;
	SDL_Texture *blueBallTexture;
	SDL_Texture *paddleTexture;
	TTF_Font *font = NULL;
	Resources(SDLComponent *component);
	~Resources();
};

