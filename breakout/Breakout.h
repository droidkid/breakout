#pragma once

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "resources.h"
#include "sdl_system.h"
#include "collision_engine.h"
#include "screen.h"
#include "input_queue.h"
#include "graphics.h"
#include "observer.h"

class Breakout : public Screen, Observer {
	Ball ball;
	Brick bricks[GameConstants::NUM_BRICKS];
	Paddle paddle;
	CollisionEngine collisionEngine;
	InputQueue *inputQueue;
	Graphics *graphics;
	Resources *resources;

	int score_value;
	char score_text[20];

public:
	Breakout(Resources *resource, InputQueue *inputQueue, Graphics *graphics);
	void update();
	void draw();
	void update(Event event);
	~Breakout();
};

