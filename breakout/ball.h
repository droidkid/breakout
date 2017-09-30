#pragma once

#ifndef SDL_LIB
#define SDL_LIB

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#endif

class Ball {
	SDL_Rect boundingBox;
	SDL_Texture *texture;

	double x, y, w, h;
	double xVel, yVel;

public:
	void setBoundingBox(double x, double y, double w, double h);
	void setBallVelocity(double xVel, double yVel);
	void setTexture(SDL_Texture *texture);
	void update();
	void draw(SDL_Renderer *renderer, double interpolation);
};