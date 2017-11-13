#pragma once

#include "sdl_helper.h"
#include "resources.h"
#include "game_loop.h"
#include "game.h"
#include "event_queue.h"
#include "text_component.h"

class Game
{
	SDLHelper *component;
	Resources *resources;
	GameLoop *gameLoop;
	Breakout *breakout;
	EventQueue *events;
	TextComponent *text;
public:
	Game();
	void run();
	~Game();
};

