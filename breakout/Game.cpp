#include "game.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	sdl = new SDLSystem();
	inputQueue = new InputQueue();
	graphics = new Graphics(sdl);
	resources = new Resources(sdl);
	breakout = new Breakout(resources, inputQueue, graphics);
	gameLoop = new GameLoop(breakout, inputQueue);
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
