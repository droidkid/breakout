#include "game.h"
#include "sdl_component.h"
#include "resources.h"
#include "game_loop.h"

// Initialize all objects required and start the game loop.

Game::Game() {
	component = new SDLComponent();
	resources = new Resources(component);
	text = new TextComponent(component, resources);
	events = new EventQueue();
	breakout = new Breakout(resources, component, events);
	gameLoop = new GameLoop(breakout, events, text);
	// TODO(chesetti): Initialize all screens here and pass them to game loop
	// Probably add some flags based on development mode or normal node.
}

void Game::run() {
	gameLoop->runLoop();
}

Game::~Game() {
}
