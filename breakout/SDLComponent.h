#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class SDLComponent
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	void initVideo();
	void initLibs();

public:
	SDLComponent();
	~SDLComponent();
	SDL_Renderer* getRenderer();
	void loadPNGintoTexture(char *filePath, SDL_Texture **texture);
	void loadTTFfont(char *filePath, int font_size, TTF_Font **font);

};

