#pragma once

#include "sdl_system.h"
#include "resources.h"
#include "game_loop.h"
#include "game.h"
#include "input_queue.h"
#include "graphics.h"

class Game
{
	// Holder for all assets.
	Resources *resources;

	// Libraries that have a specific purpose.
	SDLSystem *sdl;
	Graphics *graphics;

	// Classes that represent processes that run.
	GameLoop *gameLoop;
	InputQueue *inputQueue;

	// Classes that represent the state of the game.
	Breakout *breakout;
public:
	Game();
	void run();
	~Game();
};

