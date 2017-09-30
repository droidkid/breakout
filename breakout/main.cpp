#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

const char* SCREEN_NAME = "Breakout!";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FONT_SIZE_PT = 28;

const int UPDATES_PER_SECOND = 80; // GAME SPEED, game is updated this times a second
const int MS_PER_UPDATE = 1000 / UPDATES_PER_SECOND;

SDL_Event event;
Uint32 current_state_ms;
Uint32 lag_ms = 0;
bool quit = false;



class RectSprite {
	SDL_Texture *spriteTexture;
	SDL_Rect bBox;
	double x;
	double y;
	double xVel;
	double yVel;

public:
	// TODO(chesetti): Use creator methods?
	void initialize(int x, int y, int w, int h, SDL_Texture *texture, double xVel, double yVel) {

		// Initialize Bounding Box
		this->x = x;
		this->y = y;


		this->bBox.x = x;
		this->bBox.y = y;
		this->bBox.w = w;
		this->bBox.h = h;

		this->xVel = xVel; // Pixels per millisecond
		this->yVel = yVel; // Pixels per millisecond

		this->spriteTexture = texture;
	}

	void draw(SDL_Renderer *renderer, double interpolation) {

		bBox.x = (int)(x + xVel * interpolation);
		bBox.y = (int)(y + yVel * interpolation);

		printf("%d %d\n", bBox.x, bBox.y);

		SDL_RenderCopy(
			renderer,
			spriteTexture
			, NULL /*Src Rect - All of it*/,
			&bBox
		);
	}

	void update() {
		int ticks_passed_ms = MS_PER_UPDATE;

		if (x <= 0 && xVel < 0) {
			xVel = -xVel;
		}
		if (x + bBox.w >= SCREEN_WIDTH && xVel > 0) {
			xVel = -xVel;
		}
		if (y <= 0 && yVel < 0) {
			yVel = -yVel;
		}
		if (y + bBox.h >= SCREEN_HEIGHT && yVel > 0) {
			yVel = -yVel;

		}

		x += xVel * ticks_passed_ms;
		y += yVel * ticks_passed_ms;

		printf("%d\n", ticks_passed_ms);

	}

};

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

// Textures
SDL_Texture *greenBrickTexture;
SDL_Texture *ballTexture;

// Fonts
TTF_Font *gFont = NULL;

// GameObjects
RectSprite ball;

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
	ball.initialize(
		100, 15, 20, 20, /* bounding box*/
		ballTexture, -0.5, 0.5);
}

void handle_input() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		quit = true;
	}

}

void update() {
	ball.update();
}

void draw() {
	SDL_RenderClear(gRenderer);
	ball.draw(gRenderer, (1.0 * lag_ms) / MS_PER_UPDATE);
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