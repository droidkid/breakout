#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char** argv) {


	// All SDL calls seem to start as SDL_*

	// Step 1. Initialize SDL and the subsystems you want to use.
	// TODO(chesetti): What's the best way to handle error checking?
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	// Initialize the Window.
	SDL_Window* window = NULL;
	window = SDL_CreateWindow(
		"Breakout",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		SDL_Log("Unable to create window: %s\n", SDL_GetError());
		return 1;
	}

	// Initialize the Surface. A surface represents a bunch of pixels?
	// Surface is something you draw onto.
	SDL_Surface* screenSurface = NULL;
	screenSurface = SDL_GetWindowSurface(window);

	// Anything special about this?
	SDL_Delay(2000);

	// LazyFoo says this also takes care of the Surface.
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}