#include "breakout.h"
#include "game_constants.h"
#include "sdl_system.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace GameConstants;

// Screen for breakout game.

// TODO(chesetti): Remove Magic Constants.

Breakout::Breakout(Resources *resources, InputQueue *inputQueue, Graphics *graphics) {
	this->inputQueue = inputQueue;
	this->graphics = graphics;
	this->resources = resources;

	this->score_value = 0;
	this->currentState = LAUNCH_BALL;

	// Initialize all the game objects.
	ball.getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
	ball.getPhysics()->setXYAndSize(500, 400, BALL_SIZE, BALL_SIZE);
	ball.getGraphics()->setTexture(resources->blueBallTexture);
	ball.getGameEventNotifier()->addObserver(this);

	int brick_cnt = 0;
	int color_cnt = 0;
	for (int i = 0; i < BRICK_ROWS; i++) {
		for (int j = 0; j < BRICK_COLS; j++) {
			bricks[brick_cnt].getPhysics()->setXYAndSize(j * BRICK_WIDTH, i * BRICK_HEIGHT + 100, BRICK_WIDTH, BRICK_HEIGHT);
			bricks[brick_cnt].getGraphics()->setTexture(resources->brickTextures[color_cnt]);
			bricks[brick_cnt].getGameEventNotifier()->addObserver(this);
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
	int paddleX, paddleY;

	switch (currentState) {
	case LAUNCH_BALL:
		// Move these to functions.
		paddle.update(inputQueue);
		paddleX = paddle.getPhysics()->getX();
		paddleY = paddle.getPhysics()->getY();
		ball.getPhysics()->setXY(paddleX + 48, paddleY - 15);
		ball.getPhysics()->setVelocity(0, 0);
		if (inputQueue->hasMouseLeftClickEvent()) {
			currentState = BALL_IN_PLAY;
			ball.getPhysics()->setYVel(BALL_VELOCITY);
		}
		break;
	case BALL_IN_PLAY:
		paddle.update(inputQueue);
		ball.update(inputQueue);
		for (int i = 0; i < NUM_BRICKS; i++) {
			bricks[i].update(inputQueue);
		}
		collisionEngine.update();
		break;
	case ALL_BRICKS_DESTROYED:
		// TODO(chesetti): After some time go back to LAUNCH_BALL 
		break;
	default:
		break;
	}
	inputQueue->consumeMouseLeftClickEvent();
}

void Breakout::draw() {
	graphics->clearScreen();
	graphics->drawText("WELCOME_TO_BREAKOUT!", Vec2d(10, 10), resources->font, { 255, 255, 255 });
	sprintf_s(score_text, "SCORE: %d", score_value);
	graphics->drawText(score_text, Vec2d(700, 10), resources->font, { 255, 255, 255 });

	if (currentState == ALL_BRICKS_DESTROYED) {
		graphics->drawText("THAT'S IT. NO CAKE.", Vec2d(300, 200), resources->font, { 255, 255, 255 });
	}
	else {

		ball.draw(0.0, graphics);
		for (int i = 0; i < NUM_BRICKS; i++) {
			bricks[i].draw(0.0, graphics);
		}
		paddle.draw(0.0, graphics);
	}
	graphics->renderScreen();
}

void Breakout::update(EventName event) {
	switch (event) {
	case BRICK_DISAPPEAR:
		score_value++;
		destroyed_bricks++;
		if (destroyed_bricks == BRICK_COLS*BRICK_ROWS) {
			currentState = ALL_BRICKS_DESTROYED;
		}
		break;
	case BALL_FALL_BELOW_SCREEN:
		currentState = LAUNCH_BALL;
	default:
		break;
	}
}

Breakout::~Breakout() {
}
