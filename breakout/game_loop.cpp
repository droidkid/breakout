#include <SDL.h>

#include "game_loop.h"
#include "game_constants.h"
#include "breakout.h"

#include <stdio.h>

using namespace GameConstants;

// TODO(chesetti): Keep track of a Current 'Screen' and a list of all 'Screens'
// Only the active screen will be updated in runLoop
// 'Screen' will have some methods.

GameLoop::GameLoop(Breakout *breakout)
{
	this->breakout = breakout;
}

// TODO(chesetti): This should not be here.
void GameLoop::pollInput() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		keep_loop_running = false;
	}
	if (event.type == SDL_MOUSEMOTION) {
		mouse_x = event.motion.x;
		mouse_y = event.motion.y;
	}
}

void GameLoop::runLoop() {
	keep_loop_running = true;
	current_tick_ms = SDL_GetTicks();

	while (keep_loop_running) {
		pollInput();
		lag_ms += SDL_GetTicks() - current_tick_ms;
		current_tick_ms = SDL_GetTicks();

		while (lag_ms >= MS_PER_UPDATE) {
			breakout->update(mouse_x, mouse_y);
			lag_ms -= MS_PER_UPDATE;
		}
		breakout->draw();
	}
}


GameLoop::~GameLoop()
{
}
