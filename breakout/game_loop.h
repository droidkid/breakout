#pragma once

#include "breakout.h"

class GameLoop
{
	int current_tick_ms;
	int lag_ms;
	bool keep_loop_running;
	Breakout *breakout;

	SDL_Event event;
	int mouse_x;
	int mouse_y;
public:
	GameLoop(Breakout *breakout);
	void runLoop();
	void pollInput();
	~GameLoop();
};

