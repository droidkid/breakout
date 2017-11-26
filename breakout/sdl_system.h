#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class SDLSystem
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	void initVideo();
	void initLibs();

public:
	SDLSystem();
	~SDLSystem();
	SDL_Renderer* getRenderer();
};

