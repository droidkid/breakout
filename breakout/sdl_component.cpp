#include "sdl_component.h"

#include "game_constants.h"
using namespace GameConstants;


// TODO(chesetti): Rename to this something like SDL_Utility

SDLComponent::SDLComponent()
{
	initLibs();
	initVideo();
}

void SDLComponent::initLibs() {
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

void SDLComponent::initVideo() {

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

void SDLComponent::loadPNGintoTexture(char *fpath, SDL_Texture **texture) {
	SDL_Surface *surface = IMG_Load(fpath);
	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void SDLComponent::loadTTFfont(char *fpath, int font_size, TTF_Font **font) {

	*font = TTF_OpenFont(fpath, font_size);
	if (*font == NULL) {
		SDL_Log("Failed to load text font: %s\n", TTF_GetError());
		throw "Failed to load text";
	}
}

SDL_Renderer* SDLComponent::getRenderer() {
	return renderer;
}

SDLComponent::~SDLComponent()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}
