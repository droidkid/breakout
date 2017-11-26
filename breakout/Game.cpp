#include "game.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	sdl = new SDLSystem();
	events = new EventQueue();
	graphics = new Graphics(sdl);
	resources = new Resources(sdl);
	breakout = new Breakout(resources, events, graphics);
	gameLoop = new GameLoop(breakout, events);
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
