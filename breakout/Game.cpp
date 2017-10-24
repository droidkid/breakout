#include "game.h"
#include "sdl_component.h"
#include "resources.h"
#include "game_loop.h"




Game::Game() {
	component = new SDLComponent();
	resources = new Resources(component);
	breakout = new Breakout(resources, component);
	gameLoop = new GameLoop(breakout);
	// TODO(chesetti): Initialize all screens here and pass them to game loop
	// Probably add some flags based on development mode or normal node.
}

void Game::run() {
	
	gameLoop->runLoop();
}

Game::~Game()
{
}
