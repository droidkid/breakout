#include "breakout.h"
#include "game_constants.h"
#include "sdl_component.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>

using namespace GameConstants;



Breakout::Breakout(Resources *resources, SDLComponent *component)
{
	renderer = component->getRenderer();

	for (int i = 0; i < NUM_BALLS; i++) {
		balls[i].setBallVelocity(BALL_VELOCITY, BALL_VELOCITY);
		balls[i].setBoundingBox(rand() % (SCREEN_WIDTH - 300), rand() % (SCREEN_HEIGHT - 300), BALL_SIZE, BALL_SIZE);
		balls[i].setTexture(resources->greyBallTexture);
	}

	int brick_cnt = 1;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].setBoundingBox((2 * i + 1)*BRICK_WIDTH, (2 * j + 1) * BRICK_HEIGHT, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].setTexture(resources->greenBrickTexture);
			brick_cnt++;
		}
	}

	balls[0].setTexture(resources->blueBallTexture);
	bricks[0].setBoundingBox(400, 500, 100, 50);
	bricks[0].setTexture(resources->paddleTexture);

}

void Breakout::update(int mouse_x, int mouse_y) {
	for (int i = 0; i < NUM_BALLS; i++) {
		balls[i].update();
	}
	bricks[0].update(mouse_x, mouse_y);
	for (int i = 0; i < NUM_BALLS; i++) {
		for (int j = 0; j < NUM_BRICKS+1; j++) {
			bricks[j].collideCorrect(&balls[i]);
		}
	}

	for (int i = 0; i < NUM_BALLS; i++) {
		for (int j = 0; j < NUM_BALLS; j++) {
			if (i != j) {
				balls[i].collideCorrect(&balls[j]);
			}
		}
	}
}

void Breakout::draw() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < NUM_BALLS; i++) {
		balls[i].draw(renderer, 0.0);
	}
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].draw(renderer, 0.0);
	}
	SDL_RenderPresent(renderer);
}


Breakout::~Breakout()
{
}
