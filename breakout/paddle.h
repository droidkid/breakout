#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "ball.h"
#include "game_object.h"
#include "physics_component.h"

class PaddlePhysics : public PhysicsComponent {
public:
	void update(int mouse_x, int mouse_y);
};

class Paddle : public GameObject {
	PaddlePhysics *paddlePhysics;
public:
	Paddle();
	void update(EventQueue *eventQueue);
};
