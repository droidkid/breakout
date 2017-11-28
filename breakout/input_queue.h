#pragma once

#include "geometry.h"

class InputQueue {
	SDL_Event event;
	bool quit_event_received;
	Vec2d mouse_pos;
public:
	InputQueue();
	void pollInput();
	Vec2d getMousePos();
	bool quitGame();
	~InputQueue();
};

