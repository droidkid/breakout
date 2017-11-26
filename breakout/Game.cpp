#include "game.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	sdl = new SDLSystem();
	events = new EventQueue();
	resources = new Resources(sdl);
	breakout = new Breakout(sdl, resources, events);
	gameLoop = new GameLoop(breakout, events);
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
