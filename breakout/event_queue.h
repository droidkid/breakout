#pragma once

#include "geometry.h"

class EventQueue {
	SDL_Event event;
	bool quit_event_received;
	Vec2d mouse_pos;
public:
	EventQueue();
	void pollInput();
	Vec2d getMousePos();
	bool quitGame();
	~EventQueue();
};

