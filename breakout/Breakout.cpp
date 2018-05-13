#include "breakout.h"
#include "game_constants.h"
#include "sdl_system.h"
#include "resources.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace GameConstants;

// Screen for breakout game.

Breakout::Breakout(Resources *resources, InputQueue *inputQueue, Graphics *graphics) {
	this->inputQueue = inputQueue;
	this->graphics = graphics;
	this->resources = resources;
	this->score_value = 0;
	curGameState = START_SCREEN;

	// Initialize all the game objects.
	ball.getPhysics()->setVelocity(BALL_VELOCITY, BALL_VELOCITY);
	ball.getPhysics()->setXYAndSize(450, 480, BALL_SIZE, BALL_SIZE);
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

	paddle.getPhysics()->setXYAndSize(400, 500, 100, 20);
	paddle.getGraphics()->setTexture(resources->paddleTexture);

	// Tell the CollisionEngine about the newly created objects.
	collisionEngine.setBall(&ball);
	collisionEngine.setBricks(bricks, NUM_BRICKS);
	collisionEngine.setPaddle(&paddle);
}

void Breakout::update() {
	paddle.update(inputQueue);
	if (curGameState == IN_GAME) {
		ball.update(inputQueue);
		for (int i = 0; i < NUM_BRICKS; i++) {
			bricks[i].update(inputQueue);
		}
		collisionEngine.update();
	}
	if (curGameState == START_SCREEN) {
		ball.getPhysics()->setXY(paddle.getPhysics()->getX() + paddle.getPhysics()->getWidth()/2.0 - ball.getPhysics()->getWidth()/2.0,
								paddle.getPhysics()->getY() - ball.getPhysics()->getHeight());
		if (inputQueue->hasMouseLeftClickEvent()) {
			inputQueue->consumeMouseLeftClickEvent();
			curGameState = IN_GAME;
		}
	}
	if (curGameState == GAME_OVER_LOST || curGameState == GAME_OVER_WON) {
		if (inputQueue->hasMouseLeftClickEvent()) {
			inputQueue->consumeMouseLeftClickEvent();
			for (int i = 0; i < NUM_BRICKS; i++) {
				bricks[i].makeReappear();
			}
			score_value = 0;
			curGameState = START_SCREEN;
		}
	}
}

void Breakout::draw() {
	graphics->clearScreen();
	ball.draw(0.0, graphics);
	for (int i = 0; i < NUM_BRICKS; i++) {
		bricks[i].draw(0.0, graphics);
	}
	paddle.draw(0.0, graphics);
	graphics->drawText("WELCOME_TO_BREAKOUT!", Vec2d(10, 10), resources->font, {255, 255, 255});
	sprintf_s(score_text, "SCORE: %d", score_value);
	graphics->drawText(score_text, Vec2d(700, 10), resources->font, {255, 255, 255});
	if (curGameState == START_SCREEN) {
		graphics->drawText("LEFT CLICK TO START." , Vec2d(SCREEN_HEIGHT/2 , SCREEN_WIDTH/2), resources->font, {255, 255, 255});
	}
	if (curGameState == GAME_OVER_LOST) {
		graphics->drawText("YOU LOST :(" , Vec2d(SCREEN_HEIGHT/2 , SCREEN_WIDTH/2 - 20), resources->font, {255, 255, 255});
		graphics->drawText("LEFT CLICK TO TRY AGAIN." , Vec2d(SCREEN_HEIGHT/2 , SCREEN_WIDTH/2), resources->font, {255, 255, 255});
	}
	if (curGameState == GAME_OVER_WON) {
		graphics->drawText("YOU WON! TREAT YOURSELF, YOU DESERVE IT :)" , Vec2d(SCREEN_HEIGHT/2 , SCREEN_WIDTH/2 - 20), resources->font, {255, 255, 255});
		graphics->drawText("LEFT CLICK TO PLAY AGAIN." , Vec2d(SCREEN_HEIGHT/2 , SCREEN_WIDTH/2), resources->font, {255, 255, 255});
	}
	graphics->renderScreen();
}

void Breakout::update(EventName event) {
	switch (event) {
	case BRICK_DISAPPEAR:
		score_value++;
		if (score_value == NUM_BRICKS) {
			curGameState = GAME_OVER_WON;
		}
		break;
	case BALL_FALL_BELOW_SCREEN:
		curGameState = GAME_OVER_LOST;
	default:
		break;
	}
}

Breakout::~Breakout() {
}
