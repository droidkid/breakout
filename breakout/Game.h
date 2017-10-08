#pragma once

#include "sdl_component.h"
#include "resources.h"
#include "game_loop.h"
#include "game.h"

class Game
{
	SDLComponent *component;
	Resources *resources;
	GameLoop *gameLoop;
	Breakout *breakout;
public:
	Game();
	void run();
	~Game();
};

