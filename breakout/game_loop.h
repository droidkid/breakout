#pragma once

#include "breakout.h"
#include "event_queue.h"

class GameLoop {
	int current_tick_ms;
	int lag_ms;
	bool keep_loop_running;
	Breakout *breakout;
	EventQueue *events;

public:
	GameLoop(Breakout *breakout, EventQueue *events);
	void runLoop();
	~GameLoop();
};

