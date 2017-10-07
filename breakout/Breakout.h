#pragma once

#include "game_constants.h"
#include "ball.h"
#include "paddle.h"
#include "Resources.h"
#include "SDLComponent.h"

class Breakout
{
	SDL_Renderer *renderer;
	Ball balls[GameConstants::NUM_BALLS];
	Paddle bricks[GameConstants::NUM_BRICKS + 1];

public:
	Breakout(Resources *resources, SDLComponent *sdlComponent);
	void update(int mouse_x, int mouse_y);
	void draw();
	~Breakout();
};

