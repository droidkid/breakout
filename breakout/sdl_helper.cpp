#include "sdl_helper.h"

#include "game_constants.h"
using namespace GameConstants;


// TODO(chesetti): Rename to this something like SDL_Utility

// Initializes SDL libraries.

SDLHelper::SDLHelper() {
	initLibs();
	initVideo();
}

void SDLHelper::initLibs() {
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
		throw "Unable to initialize SDL";
	}

	// Initialize SDL_image
	int img_flags = IMG_INIT_PNG;
	if (IMG_Init(img_flags) != img_flags) {
		SDL_Log("Unable to initialize SDL_Image: %s", IMG_GetError());
		throw "Unable to initialize SDL_Image";
	}

	// Initialize SDL_ttf
	if (TTF_Init() != 0) {
		SDL_Log("Unable to initialize SDL_ttf: %s\n", TTF_GetError());
		throw "Unable to initialize SDL_ttf";
	}

}

void SDLHelper::initVideo() {

	// Create Window and Renderer.
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Disable Cursor.
	SDL_ShowCursor(SDL_DISABLE);


	if (window == NULL) {
		SDL_Log("Failed to create Window: %s\n", SDL_GetError());
		throw "Unable to initialize SDL Window";
	}
	if (renderer == NULL) {
		SDL_Log("Failed to create Renderer: %s\n", SDL_GetError());
		throw "Unable to initialize Renderer";
	}
}

SDL_Renderer* SDLHelper::getRenderer() {
	return renderer;
}

SDLHelper::~SDLHelper() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
