#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "ball.h"
#include "game_object.h"
#include "physics_component.h"

class Paddle : public GameObject {
public:
	Paddle();
	void update(InputQueue *inputQueue);
};
