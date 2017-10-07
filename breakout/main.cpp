#include <stdlib.h>

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"

#include "SDLComponent.h"
#include "Resources.h"
#include "Game.h"

using namespace GameConstants;

SDL_Event event;
Uint32 current_state_ms;
Uint32 lag_ms = 0;
bool quit = false;


SDL_Renderer *gRenderer = NULL;



// GameObjects
const int numBalls = 50;
const int numPaddles = 20;
Ball balls[numBalls];
Paddle paddles[numPaddles];

SDLComponent component;
Resources resources(&component);

int mouse_x;
int mouse_y;

void initializeGameObjects() {
	for (int i = 0; i < numBalls; i++) {
		double vel = 0.02;
		int ballSize = 15;
		balls[i].setBallVelocity(vel * (rand() % 10), vel * (rand() % 10));
		balls[i].setBoundingBox(rand() % (SCREEN_WIDTH - 300), rand() % (SCREEN_HEIGHT - 300), ballSize, ballSize);
		balls[i].setTexture(resources.blueBallTexture);
	}
	int row = 1;
	int col = 0;
	for (int i = 0; i < numPaddles; i++) {
		paddles[i].setBoundingBox(row*100 + 10, col * 70 + 50, 40, 40);
		row++;
		if (row * 100 + 10 > SCREEN_WIDTH) {
			row = 0;
			col++;
		}
		paddles[i].setTexture(resources.greenBrickTexture);
	}

	balls[0].setTexture(resources.blueBallTexture);

	paddles[0].setBoundingBox(400, 500, 100, 50);
	paddles[0].setTexture(resources.paddleTexture);

}


void handle_input() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		quit = true;
	}
	if (event.type == SDL_MOUSEMOTION) {
		mouse_x = event.motion.x;
		mouse_y = event.motion.y;
	}
}

void update() {
	for (int i = 0; i < numBalls; i++) {
		balls[i].update();
	}
	paddles[0].update(mouse_x, mouse_y);
	for (int i = 0; i < numBalls; i++) {
		for (int j = 0; j < numPaddles; j++) {
			paddles[j].collideCorrect(&balls[i]);
		}
	}
	for (int i = 0; i < numBalls; i++) {
		for (int j = 0; j < numBalls; j++) {
			if (i != j) {
				balls[i].collideCorrect(&balls[j]);
			}
		}
	}
}

void draw() {
	SDL_RenderClear(gRenderer);
	double interpolation =( 1.0 * lag_ms) / MS_PER_UPDATE;
	for (int i = 0; i < numBalls; i++) {
		balls[i].draw(gRenderer, (1.0 * lag_ms) / MS_PER_UPDATE);
	}
	for (int i = 0; i < numPaddles; i++) {
		paddles[i].draw(gRenderer, interpolation);
	}
	SDL_RenderPresent(gRenderer);

}

Game game;

int main(int argc, char** argv) {
	game.run();
	return 0;
}