#pragma once
#include "geometry.h"
#include "resources.h"
#include "sdl_component.h"

#include <SDL.h>
#include <SDL_ttf.h>

class TextComponent
{
	SDL_Color textColor;
	TTF_Font *font;
	SDL_Renderer *renderer;
public:
	TextComponent(SDLComponent *sdl_component, Resources *resources);
	void drawText(char *txt, Vec2d pos);
	~TextComponent();
};

