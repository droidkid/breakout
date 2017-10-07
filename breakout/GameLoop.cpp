#include <SDL.h>

#include "GameLoop.h"
#include "game_constants.h"

using namespace GameConstants;



GameLoop::GameLoop()
{
}

void GameLoop::runLoop() {
	keep_loop_running = true;
	current_tick_ms = SDL_GetTicks();

	while (!keep_loop_running) {
		// handle_input();
		lag_ms += SDL_GetTicks() - current_tick_ms;
		current_tick_ms = SDL_GetTicks();
		while (lag_ms >= MS_PER_UPDATE) {
			// update();
			lag_ms -= MS_PER_UPDATE;
		}
		// draw();
	}
}


GameLoop::~GameLoop()
{
}
