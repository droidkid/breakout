#include "Game.h"
#include "SDLComponent.h"
#include "Resources.h"
#include "GameLoop.h"


SDLComponent *component;
Resources *resources;
GameLoop *gameLoop;


void Game() {
	component = new SDLComponent();
	resources = new Resources(component);
	gameLoop = new GameLoop();
}

void Game::run() {
	// Usually there'd be other stuff here (start, pause etc).
	// Just starting gameLoop for now.
	gameLoop->runLoop();
}

Game::~Game()
{
}
