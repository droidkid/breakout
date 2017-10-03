#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>
using namespace std;

#include "game_constants.h"
#include "paddle.h"

using namespace GameConstants;

void Paddle::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

void Paddle::setBoundingBox(double x, double y, double w, double h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void Paddle::draw(SDL_Renderer *renderer, double interpolation) {
	boundingBox.x = (int)(x + xVel * interpolation);
	boundingBox.y = (int)(y + yVel * interpolation);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
}

void Paddle::update(int mouse_x) {

	if (mouse_x < 0) {
		x = 0;
	}
	else if (mouse_x > SCREEN_WIDTH - w) {
		x = SCREEN_WIDTH - w;
	}
	else {
		x = mouse_x;
	}


}

void Paddle::collideCorrect(Ball *b) {
	// Not optimized at all, just roll with it
	double cx = (b->x + b->w / 2.0);
	double cy = (b->y + b->h / 2.0);
	double r = sqrt(2) * b->w/2;

	if (cx < x || cx > x + w) {
		return;
	}

	if (b->y + b->h > y && b->y + b->h < y + h && cy < y ) {
		b->yVel = -b->yVel;
		b->y = y - b->h;
		return;
	}

	if (b->y < y + h && cy > y) {
		b->yVel = -b->yVel;
		b->y = y + h;
		return;
	}


}