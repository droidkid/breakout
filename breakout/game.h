#pragma once

#include "sdl_system.h"
#include "resources.h"
#include "game_loop.h"
#include "game.h"
#include "event_queue.h"

class Game
{
	SDLSystem *sdl;
	Resources *resources;
	GameLoop *gameLoop;
	Breakout *breakout;
	EventQueue *events;
public:
	Game();
	void run();
	~Game();
};

