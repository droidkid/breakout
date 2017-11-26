#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "physics_component.h"

class GraphicsComponent
{
	SDL_Rect boundingBox;
	SDL_Renderer *renderer; // Remove this field. Pass this as a method parameter.
	SDL_Texture *texture;
	PhysicsComponent *physicsComponent;

public:
	GraphicsComponent(PhysicsComponent *physics);
	void setRenderer(SDL_Renderer *renderer);
	void setTexture(SDL_Texture *texture);
	void draw(double interpolation);
	~GraphicsComponent();
};
