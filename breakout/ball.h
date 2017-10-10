#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "physics_component.h"

class Ball {
	SDL_Texture *texture;
	SDL_Rect boundingBox;
	PhysicsComponent *physicsComponent;

public:
	Ball();
	void update();
	PhysicsComponent* getPhysics();
	// Graphics Methods
	void setTexture(SDL_Texture *texture);
	void draw(SDL_Renderer *renderer, double interpolation);
};