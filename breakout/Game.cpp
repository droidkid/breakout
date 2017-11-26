#include "game.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	sdl = new SDLSystem();
	resources = new Resources(sdl);
	events = new EventQueue();
	breakout = new Breakout(sdl, resources, events);
	gameLoop = new GameLoop(breakout, events);
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
