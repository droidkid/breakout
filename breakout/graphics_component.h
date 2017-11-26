#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "physics_component.h"
#include "graphics.h"

class GraphicsComponent
{
	SDL_Rect boundingBox;
	SDL_Texture *texture;
	PhysicsComponent *physicsComponent;

public:
	GraphicsComponent(PhysicsComponent *physics);
	void setTexture(SDL_Texture *texture);
	void draw(double interpolation, Graphics *graphics);
	~GraphicsComponent();
};
