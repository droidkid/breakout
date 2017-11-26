#pragma once
#include "geometry.h"
#include "resources.h"
#include "sdl_system.h"

#include <SDL.h>
#include <SDL_ttf.h>

// DO NOT USE THIS CLASS. JUST A PLACEHOLDER TO FIGURE OUT HOW TO RENDER TEXT.
class TextComponent {
	SDL_Color textColor;
	TTF_Font *font;
	SDL_Renderer *renderer;
public:
	TextComponent(SDLSystem *sdl, Resources *resources);
	void drawText(char *txt, Vec2d pos);
	~TextComponent();
};

