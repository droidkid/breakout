#ifndef SDL_LIB
#define SDL_LIB

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#endif

#ifndef GAME
#define GAME

#include "game_constants.h"
#include "ball.h"

#endif



using namespace GameConstants;

SDL_Event event;
Uint32 current_state_ms;
Uint32 lag_ms = 0;
bool quit = false;


SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

// Resources
SDL_Texture *greenBrickTexture;
SDL_Texture *ballTexture;
TTF_Font *gFont = NULL;

// GameObjects
Ball blueBall;


bool initialize() {
	// Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}

	// Initialize SDL_image
	int img_flags = IMG_INIT_PNG;
	if (IMG_Init(img_flags) != img_flags) {
		SDL_Log("Unable to initialize SDL_Image: %s", IMG_GetError());
		return false;
	}

	// Initialize SDL_ttf
	if (TTF_Init() != 0) {
		SDL_Log("Unable to initialize SDL_ttf: %s\n", TTF_GetError());
		return false;
	}

	/*
		Using SDL_WINDOW_SHOWN_MODE, which puts the game in a window. If using a full screen mode
		like SDL_WINDOW_FULLSCREEN_DESKTOP. You might want to use something like

		SDL_RenderSetLogicalSize(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);

		Develop for WIDTH*HEIGHT, SDL will handle the scaling to full screen.
	*/
	// Create Window and Renderer.
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &gWindow, &gRenderer);

	if (gWindow == NULL) {
		SDL_Log("Failed to create Window: %s\n", SDL_GetError());
		return false;
	}
	if (gRenderer == NULL) {
		SDL_Log("Failed to create Renderer: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

bool loadResources() {
	// Load Font.
	// TODO(chesetti): Remove Hardcoding
	gFont = TTF_OpenFont("assets/fonts/kenpixel_high.ttf", FONT_SIZE_PT);
	if (gFont == NULL) {
		SDL_Log("Failed to load text font: %s\n", TTF_GetError());
		return false;
	}

	// TODO(chesetti): Error handling, Remove hardcoding.
	SDL_Surface *surface = IMG_Load("assets/puzzlepack/png/ballBlue.png");
	ballTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("assets/puzzlepack/png/element_green_rectangle.png");
	greenBrickTexture = SDL_CreateTextureFromSurface(gRenderer, surface);
	SDL_FreeSurface(surface);

	return true;

}

void close() {
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}

void initializeGameObjects() {
	blueBall.setBallVelocity(0.1, 0.1);
	blueBall.setBoundingBox(50, 50, 30, 30);
	blueBall.setTexture(ballTexture);
}

void handle_input() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		quit = true;
	}
}

void update() {
	blueBall.update();
}

void draw() {
	SDL_RenderClear(gRenderer);
	blueBall.draw(gRenderer, (1.0 * lag_ms) / MS_PER_UPDATE);
	SDL_RenderPresent(gRenderer);

}


int main(int argc, char** argv) {


	if (!initialize()) {
		return 1;
	}
	if (!loadResources()) {
		return 1;
	}
	initializeGameObjects();


	// Game loop
	current_state_ms = SDL_GetTicks();

	while (!quit) {

		handle_input();

		lag_ms += SDL_GetTicks() - current_state_ms;
		current_state_ms = SDL_GetTicks();

		while (lag_ms >= MS_PER_UPDATE) {
			update();
			lag_ms -= MS_PER_UPDATE;
		}

		draw();
	}

	close();
	return 0;
}