#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FONT_SIZE_PT = 28;
const char* SCREEN_NAME = "Breakout!";
const int FRAMES_PER_SECOND = 30;
const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

// TODO(chesetti): What's the best way to handle error checking?

SDL_Window* gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
TTF_Font *gFont = NULL;

class RectSprite {

	SDL_Texture *texture;
	SDL_Rect bBox;
	int xVel;
	int yVel;

public:
	// TODO(chesetti): Use creator methods?
	RectSprite(SDL_Renderer *renderer, char *png_file_path) {
		// TODO(chesettI): Pass in the texture here... this way you can reuse textures.
		SDL_Surface* surface = IMG_Load(png_file_path);

		// Initialize Bounding Box
		bBox.x = 0;
		bBox.y = 0;
		bBox.w = surface->w;
		bBox.h = surface->h;

		xVel = -10;
		yVel = -10;

		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}

	void draw(SDL_Renderer *renderer) {
		SDL_RenderCopy(
			renderer, 
			texture
			, NULL /*Src Rect - All of it*/, 
			&bBox
		);
	}

	void update() {
		if (bBox.x <= 0) {
			xVel = -xVel;
		}
		if (bBox.x + bBox.w >= SCREEN_WIDTH) {
			xVel = -xVel;
		}
		if (bBox.y <= 0) {
			yVel = -yVel;
		}
		if (bBox.y + bBox.h >= SCREEN_HEIGHT) {
			yVel = -yVel;
		}
		bBox.x += xVel;
		bBox.y += yVel;
	}

};

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

	return true;
}

bool loadResources() {
	// Load Font.
	gFont = TTF_OpenFont("assets/fonts/kenpixel_high.ttf", FONT_SIZE_PT);
	if (gFont == NULL) {
		SDL_Log("Failed to load text font: %s\n", TTF_GetError());
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

void close() {
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}

int main(int argc, char** argv) {


	if (!initialize()) {
		return 1;
	}
	if (!loadResources()) {
		return 1;
	}

	RectSprite ballBlue = RectSprite(gRenderer, "assets/puzzlepack/png/ballBlue.png");



	// Game loop
	SDL_Event event;
	bool quit = false;

	Uint32 startTime = SDL_GetTicks();

	while (!quit) {
		startTime = SDL_GetTicks();

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			quit = true;
		}

		ballBlue.update();

		SDL_RenderClear(gRenderer);
		ballBlue.draw(gRenderer);
		SDL_RenderPresent(gRenderer);

		int sleep_time = SKIP_TICKS - (SDL_GetTicks() - startTime);

		if (sleep_time > 0) {
			SDL_Delay(sleep_time);
		}
	}

	close();
	return 0;
}