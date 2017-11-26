#include <SDL.h>

#include "game_loop.h"
#include "game_constants.h"
#include "breakout.h"

#include <stdio.h>

using namespace GameConstants;

GameLoop::GameLoop(Breakout *breakout, EventQueue *events) {
	this->breakout = breakout;
	this->events = events;
}

void GameLoop::runLoop() {
	bool quit_event_received = false;
	current_tick_ms = SDL_GetTicks();

	while (!quit_event_received) {
		events->pollInput();
		lag_ms += SDL_GetTicks() - current_tick_ms;
		current_tick_ms = SDL_GetTicks();

		while (lag_ms >= MS_PER_UPDATE) {
			breakout->update();
			lag_ms -= MS_PER_UPDATE;
		}
		breakout->draw();
		quit_event_received = events->quitGame();
	}
}


GameLoop::~GameLoop() {
}
