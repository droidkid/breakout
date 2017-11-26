#pragma once

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "resources.h"
#include "sdl_system.h"
#include "collision_engine.h"
#include "screen.h"
#include "event_queue.h"
#include "graphics.h"

class Breakout : public Screen {
	Ball ball;
	Brick bricks[GameConstants::NUM_BRICKS];
	Paddle paddle;
	CollisionEngine collisionEngine;
	EventQueue *events;
	Graphics *graphics;
	Resources *resources;

public:
	Breakout(Resources *resource, EventQueue *events, Graphics *graphics);
	void update();
	void draw();
	~Breakout();
};

