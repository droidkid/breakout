#pragma once

#include <SDL.h>
#include "sdl_system.h"

class Graphics {
	SDL_Renderer *renderer;
public:
	Graphics(SDLSystem *sdl);
	void clearScreen();
	void drawTexture(SDL_Texture *texture, SDL_Rect *boundingBox);
	void renderScreen();
	~Graphics();
};