#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Ball {
	SDL_Texture *texture;
	SDL_Rect boundingBox;

public:
	double x, y, w, h;
	double xVel, yVel;
	SDL_Rect* getBoundingBox();
	void setBoundingBox(double x, double y, double w, double h);
	void setBallVelocity(double xVel, double yVel);
	void setTexture(SDL_Texture *texture);
	void update();
	void draw(SDL_Renderer *renderer, double interpolation);
	void collideCorrect(Ball *ball2);
};