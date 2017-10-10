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
		balls[i].getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
		balls[i].getPhysics()->setXYAndSize(500, 400, BALL_SIZE, BALL_SIZE);
		balls[i].setTexture(resources->greyBallTexture);
	}

	int brick_cnt = 0;
	int color_cnt = 0;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].setBoundingBox( j * BRICK_WIDTH + 30, i * BRICK_HEIGHT + 100, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].setTexture(resources->brickTextures[color_cnt]);
			brick_cnt++;
		}
			color_cnt++;
			if (color_cnt == NUM_COLORS) {
				color_cnt = 0;
			}
	}

	balls[0].setTexture(resources->blueBallTexture);
	paddle.setBoundingBox(400, 500, 100, 20);
	paddle.setTexture(resources->paddleTexture);
	paddle.setAsPaddle(true);

}

void Breakout::update(int mouse_x, int mouse_y) {
	for (int i = 0; i < NUM_BALLS; i++) {
		balls[i].update();
	}
	paddle.update(mouse_x, mouse_y);
	for (int i = 0; i < NUM_BALLS; i++) {
		for (int j = 0; j < NUM_BRICKS+1; j++) {
			bricks[j].collideCorrect(&balls[i]);
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
	paddle.draw(renderer, 0.0);
	SDL_RenderPresent(renderer);
}


Breakout::~Breakout()
{
}
