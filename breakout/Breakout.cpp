#include "breakout.h"
#include "game_constants.h"
#include "sdl_system.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>

using namespace GameConstants;

// Screen for breakout game.

Breakout::Breakout(Resources *resources, EventQueue *events, Graphics *graphics) {
	this->events = events;
	this->graphics = graphics;
	this->resources = resources;

	// Initialize all the game objects.
	ball.getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
	ball.getPhysics()->setXYAndSize(500, 400, BALL_SIZE, BALL_SIZE);
	ball.getGraphics()->setTexture(resources->blueBallTexture);

	int brick_cnt = 0;
	int color_cnt = 0;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].getPhysics()->setXYAndSize(j * BRICK_WIDTH, i * BRICK_HEIGHT + 100, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].getGraphics()->setTexture(resources->brickTextures[color_cnt]);
			brick_cnt++;
		}
		color_cnt++;
		if (color_cnt == NUM_COLORS) {
			color_cnt = 0;
		}
	}

	paddle.getPhysics()->setXYAndSize(400, 500, 110, 20);
	paddle.getGraphics()->setTexture(resources->paddleTexture);

	// Tell the CollisionEngine about the newly created objects.
	collisionEngine.setBall(&ball);
	collisionEngine.setBricks(bricks, NUM_BRICKS);
	collisionEngine.setPaddle(&paddle);
}

void Breakout::update() {
	ball.update(events);
	paddle.update(events);
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].update(events);
	}
	collisionEngine.update();
}

void Breakout::draw() {
	graphics->clearScreen();
	ball.draw(0.0, graphics);
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].draw(0.0, graphics);
	}
	paddle.draw(0.0, graphics);
	graphics->drawText("WELCOME_TO_BREAKOUT!", Vec2d(10, 10), resources->font, {255, 255, 255});
	graphics->renderScreen();
}


Breakout::~Breakout() {
}
