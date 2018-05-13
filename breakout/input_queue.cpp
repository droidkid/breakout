#include "input_queue.h"

#include <SDL.h>

/*
	Ideally this should be a class that runs in a separate thread (There are lots of good reasons for this).
	For now, the game_loop calls pollInput every cycle, and this class
	keeps track of last known event. Mouse Position and Quit events are
	also kept track of.
*/

InputQueue::InputQueue() {
	quit_event_received = false;
	mouse_click_event = false;
}

void InputQueue::pollInput() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit_event_received = true;
		}
		if (event.type == SDL_MOUSEMOTION) {
			mouse_pos.x = event.motion.x;
			mouse_pos.y = event.motion.y;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				mouse_click_event = true;
			}
		}
	}
}

Vec2d InputQueue::getMousePos() {
	return mouse_pos;
}

bool InputQueue::hasMouseLeftClickEvent() {
	return mouse_click_event;
}

void InputQueue::consumeMouseLeftClickEvent() {
	mouse_click_event = false;
}

bool InputQueue::quitGame() {
	return quit_event_received;
}


InputQueue::~InputQueue() {
}
