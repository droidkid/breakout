#pragma once

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "resources.h"
#include "sdl_helper.h"
#include "collision_engine.h"
#include "screen.h"
#include "event_queue.h"

class Breakout : public Screen
{
	SDL_Renderer *renderer;
	Ball ball;
	Brick bricks[GameConstants::NUM_BRICKS];
	Paddle paddle;
	CollisionEngine collisionEngine;
	EventQueue *events;

public:
	Breakout(Resources *resources, SDLHelper *sdlComponent, EventQueue *events);
	void update();
	void draw();
	~Breakout();
};

