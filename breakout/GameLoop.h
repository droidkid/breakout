#pragma once

class GameLoop
{
	int current_tick_ms;
	int lag_ms;
	bool keep_loop_running;
public:
	GameLoop();
	void runLoop();
	~GameLoop();
};

