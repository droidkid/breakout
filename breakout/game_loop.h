#pragma once

#include "breakout.h"
#include "input_queue.h"

class GameLoop {
	int current_tick_ms;
	int lag_ms;
	bool keep_loop_running;
	Breakout *breakout; // Make this Screens.
	InputQueue *inputQueue;

public:
	GameLoop(Breakout *breakout, InputQueue *inputQueue);
	void runLoop();
	~GameLoop();
};

