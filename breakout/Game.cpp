#include "game.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	sdl = new SDLSystem();
	resources = new Resources(sdl);
	text = new TextComponent(sdl, resources);
	events = new EventQueue();
	breakout = new Breakout(resources, sdl, events);
	gameLoop = new GameLoop(breakout, events, text);
	// TODO(chesetti): Initialize all screens here and pass them to game loop
	// Probably add some flags based on development mode or normal node.
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
