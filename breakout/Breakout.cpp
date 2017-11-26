#include "breakout.h"
#include "game_constants.h"
#include "sdl_system.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>

using namespace GameConstants;

// Screen for breakout game.

Breakout::Breakout(SDLSystem *sdl, Resources *resources, EventQueue *events) {
	this->events = events;

	renderer = sdl->getRenderer();

	// Initialize all the game objects.
	ball.getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
	ball.getPhysics()->setXYAndSize(500, 400, BALL_SIZE, BALL_SIZE);
	ball.getGraphics()->setTexture(resources->blueBallTexture);
	ball.getGraphics()->setRenderer(renderer);

	int brick_cnt = 0;
	int color_cnt = 0;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].getPhysics()->setXYAndSize(j * BRICK_WIDTH, i * BRICK_HEIGHT + 100, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].getGraphics()->setTexture(resources->brickTextures[color_cnt]);
			bricks[brick_cnt].getGraphics()->setRenderer(renderer);
			brick_cnt++;
		}
		color_cnt++;
		if (color_cnt == NUM_COLORS) {
			color_cnt = 0;
		}
	}

	paddle.getPhysics()->setXYAndSize(400, 500, 110, 20);
	paddle.getGraphics()->setTexture(resources->paddleTexture);
	paddle.getGraphics()->setRenderer(renderer);

	// Tell the CollisionEngine about the newly created objects.
	collisionEngine.setBall(&ball);
	collisionEngine.setBricks(bricks, NUM_BRICKS);
	collisionEngine.setPaddle(&paddle);

}

void Breakout::update() {
	Vec2d mouse_pos = events->getMousePos();
	ball.update();
	paddle.update(mouse_pos.x, mouse_pos.y);
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


Breakout::~Breakout() {
}
