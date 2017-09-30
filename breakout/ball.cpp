#ifndef SDL_LIB
#define SDL_LIB

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#endif


#ifndef GAME
#define GAME

#include "game_constants.h"
#include "ball.h"

#endif


using namespace GameConstants;

void Ball::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

void Ball::setBallVelocity(double xVel, double yVel) {
	this->xVel = xVel;
	this->yVel = yVel;
}

void Ball::setBoundingBox(double x, double y, double w, double h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Ball::draw(SDL_Renderer *renderer, double interpolation) {
	boundingBox.x = (int)(x + xVel * interpolation);
	boundingBox.y = (int)(y + yVel * interpolation);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
}

void Ball::update() {

	if (x <= 0 && xVel < 0) {
		xVel = -xVel;
	}
	if (x + w >= SCREEN_WIDTH && xVel > 0) {
		xVel = -xVel;
	}
	if (y <= 0 && yVel < 0) {
		yVel = -yVel;
	}
	if (y + h >= SCREEN_HEIGHT && yVel > 0) {
		yVel = -yVel;

	}

	x += xVel * MS_PER_UPDATE;
	y += yVel * MS_PER_UPDATE;
}