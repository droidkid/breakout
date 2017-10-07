#include "Game.h"
#include "SDLComponent.h"
#include "Resources.h"
#include "GameLoop.h"




Game::Game() {
	component = new SDLComponent();
	resources = new Resources(component);
	breakout = new Breakout(resources, component);
	gameLoop = new GameLoop(breakout);
}

void Game::run() {
	// Usually there'd be other stuff here (start, pause etc).
	// Just starting gameLoop for now.
	gameLoop->runLoop();
}

Game::~Game()
{
}
