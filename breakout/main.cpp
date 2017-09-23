#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char** argv) {


	// All SDL calls seem to start as SDL_*

	// TODO(chesetti): What's the best way to handle error checking?
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize: %s\n", SDL_GetError());
		return 0;
	}

	SDL_Window* window = NULL;
	window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// TODO(chesetti): What's the best way to handle error checking?
	if (window == NULL) {
		printf("Window could not be initialized: %s\n", SDL_GetError());
		return 0;
	}

	// Surface is something you draw onto.
	SDL_Surface* screenSurface = NULL;
	screenSurface = SDL_GetWindowSurface(window);

	// Anything special about this?
	SDL_Delay(2000);


	// TODO(chesetti): Why is this needed? SDL_Quit seems to work just fine?
	// How do I just use the window buttons?
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}