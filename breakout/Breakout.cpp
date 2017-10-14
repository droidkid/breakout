#include "breakout.h"
#include "game_constants.h"
#include "sdl_component.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>

using namespace GameConstants;

Breakout::Breakout(Resources *resources, SDLComponent *component)
{
	// TODO(chesetti): This construction logic needs to be better organized.
	renderer = component->getRenderer();

	ball.getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
	ball.getPhysics()->setXYAndSize(500, 400, BALL_SIZE, BALL_SIZE);
	ball.getGraphics()->setTexture(resources->greyBallTexture);
	ball.getGraphics()->setRenderer(renderer);
	ball.getGraphics()->setTexture(resources->blueBallTexture);

	int brick_cnt = 0;
	int color_cnt = 0;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].getPhysics()->setXYAndSize(j * BRICK_WIDTH , i * BRICK_HEIGHT + 100, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].getGraphics()->setTexture(resources->brickTextures[color_cnt]);
			bricks[brick_cnt].getGraphics()->setRenderer(renderer);
			brick_cnt++;
		}
		color_cnt++;
		if (color_cnt == NUM_COLORS) {
			color_cnt = 0;
		}
	}

	paddle.getPhysics()->setXYAndSize(400, 500, 100, 20);
	paddle.getGraphics()->setTexture(resources->paddleTexture);
	paddle.getGraphics()->setRenderer(renderer);

	collisionEngine.setBall(&ball);
	collisionEngine.setBricks(bricks, NUM_BRICKS);
	collisionEngine.setPaddle(&paddle);

}

void Breakout::update(int mouse_x, int mouse_y) {
	ball.update();
	paddle.update(mouse_x, mouse_y);
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].update();
	}
	collisionEngine.update();
}

void Breakout::draw() {
	SDL_RenderClear(renderer);
	ball.draw(0.0);
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].draw(0.0);
	}
	paddle.draw(0.0);
	SDL_RenderPresent(renderer);
}


Breakout::~Breakout()
{
}
