#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* SCREEN_NAME = "Breakout!";

// TODO(chesetti): What's the best way to handle error checking?

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

bool initialize() {
	// Initialize SDL and the subsystems you want to use.
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}

	// Initialize PNG loading
	int img_flags = IMG_INIT_PNG;
	if (IMG_Init(img_flags) != img_flags) {
		SDL_Log("Unable to initialize SDL_Image: %s", IMG_GetError());
		return false;
	}

	// Initialize the Window.
	gWindow = SDL_CreateWindow(
		SCREEN_NAME,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (gWindow == NULL) {
		SDL_Log("Unable to create window: %s\n", SDL_GetError());
		return false;
	}

	gScreenSurface = NULL;
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return true;
}

void close() {
	// LazyFoo says this also takes care of Window Surface.
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}

int main(int argc, char** argv) {


	if (!initialize()) {
		return 1;
	}

	// Copy BMP onto SDL_Surface 
	SDL_Surface* helloworld = IMG_Load("hello_world.png");
	SDL_Surface* optHelloworld = SDL_ConvertSurface(helloworld, gScreenSurface->format, NULL);
	// Copy helloworld surface to window surface.
	SDL_BlitSurface(optHelloworld, NULL, gScreenSurface, NULL);
	// Update the window surface.
	SDL_UpdateWindowSurface(gWindow);

	SDL_Delay(2000);

	close();

	return 0;
}