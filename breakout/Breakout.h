#pragma once

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "resources.h"
#include "sdl_component.h"
#include "collision_engine.h"

class Breakout
{
	SDL_Renderer *renderer;
	Ball ball;
	Brick bricks[GameConstants::NUM_BRICKS];
	Paddle paddle;
	CollisionEngine collisionEngine;

public:
	Breakout(Resources *resources, SDLComponent *sdlComponent);
	void update(int mouse_x, int mouse_y);
	void draw();
	~Breakout();
};

