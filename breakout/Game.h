#pragma once

#include "sdl_component.h"
#include "resources.h"
#include "game_loop.h"
#include "game.h"
#include "event_queue.h"

class Game
{
	SDLComponent *component;
	Resources *resources;
	GameLoop *gameLoop;
	Breakout *breakout;
	EventQueue *events;
public:
	Game();
	void run();
	~Game();
};

