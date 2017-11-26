#pragma once

#include <SDL.h>
#include "sdl_system.h"
#include "geometry.h"

class Graphics {
	SDL_Renderer *renderer;
public:
	Graphics(SDLSystem *sdl);
	void clearScreen();
	void drawTexture(SDL_Texture *texture, SDL_Rect *boundingBox);
	void drawText(char * text, Vec2d pos, TTF_Font * font, SDL_Color textColor);
	void renderScreen();
	~Graphics();
};