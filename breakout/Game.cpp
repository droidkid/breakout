#include "game.h"
#include "sdl_component.h"
#include "resources.h"
#include "game_loop.h"

Game::Game() {
	component = new SDLComponent();
	resources = new Resources(component);
	events = new EventQueue();
	breakout = new Breakout(resources, component, events);
	gameLoop = new GameLoop(breakout, events);
	// TODO(chesetti): Initialize all screens here and pass them to game loop
	// Probably add some flags based on development mode or normal node.
}

void Game::run() {
	
	gameLoop->runLoop();
}

Game::~Game()
{
}
