#pragma once
#include "geometry.h"
#include "resources.h"
#include "sdl_helper.h"

#include <SDL.h>
#include <SDL_ttf.h>

class TextTextureHelper {
	SDL_Color textColor;
	TTF_Font *font;
	SDL_Renderer *renderer;
public:
	TextTextureHelper(SDLHelper *sdl_component, Resources *resources);
	SDL_Texture* createTextTexture(char *txt);
	SDL_Texture* createTextTexture(char *txt, SDL_Color color);
	~TextTextureHelper();
};

