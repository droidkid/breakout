#include <SDL.h>

#include "game_loop.h"
#include "game_constants.h"
#include "breakout.h"

#include <stdio.h>

using namespace GameConstants;

// TODO(chesetti): Keep track of a Current 'Screen' and a list of all 'Screens'
// Only the active screen will be updated in runLoop
// 'Screen' will have some methods.

GameLoop::GameLoop(Breakout *breakout, EventQueue *events, TextComponent *textUtility)
{
	this->breakout = breakout;
	this->events = events;
	this->textUtility = textUtility;
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
		//breakout->draw();
		textUtility->drawText("Hello Text!", Vec2d(0, 0));
		quit_event_received = events->quitGame();
	}
}


GameLoop::~GameLoop()
{
}
