#include "resources.h"
#include "game_constants.h"


// Class to keep initialize and retrieve all resources (Textures, Fonts, Audio etc). 

Resources::Resources(SDLSystem *sdl) {
	SDL_Renderer *renderer = sdl->getRenderer();
	loadPNGintoTexture("assets/puzzlepack/png/element_green_rectangle.png", &brickTextures[GREEN], renderer);
	loadPNGintoTexture("assets/puzzlepack/png/element_red_rectangle.png", &brickTextures[RED], renderer);
	loadPNGintoTexture("assets/puzzlepack/png/element_yellow_rectangle.png", &brickTextures[YELLOW], renderer);
	loadPNGintoTexture("assets/puzzlepack/png/element_purple_rectangle.png", &brickTextures[PURPLE], renderer);
	loadPNGintoTexture("assets/puzzlepack/png/element_blue_rectangle.png", &brickTextures[BLUE], renderer);
	loadPNGintoTexture("assets/puzzlepack/png/element_grey_rectangle.png", &brickTextures[GREY], renderer);

	loadPNGintoTexture("assets/puzzlepack/png/ballGrey.png", &greyBallTexture, renderer);
	loadPNGintoTexture("assets/puzzlepack/png/ballBlue.png", &blueBallTexture, renderer);
	loadPNGintoTexture("assets/puzzlepack/png/paddleBlu.png", &paddleTexture, renderer);

	loadTTFfont("assets/fonts/kenpixel_high.ttf", GameConstants::FONT_SIZE_PT, &font);
}

void Resources::loadPNGintoTexture(char *fpath, SDL_Texture **texture, SDL_Renderer *renderer) {
	SDL_Surface *surface = IMG_Load(fpath);
	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Resources::loadTTFfont(char *fpath, int font_size, TTF_Font **font) {
	*font = TTF_OpenFont(fpath, font_size);
	if (*font == NULL) {
		SDL_Log("Failed to load text font: %s\n", TTF_GetError());
		throw "Failed to load text";
	}
}


Resources::~Resources() {
	//TODO(chesetti): Free all resources here.
}
