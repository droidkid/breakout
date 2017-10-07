#pragma once

#include "SDLComponent.h"
#include "Resources.h"
#include "GameLoop.h"
#include "Game.h"

class Game
{
	SDLComponent *component;
	Resources *resources;
	GameLoop *gameLoop;
	Breakout *breakout;
public:
	Game();
	void run();
	~Game();
};

