#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>
using namespace std;

#include "game_constants.h"
#include "ball.h"

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

SDL_Rect* Ball::getBoundingBox() {
	boundingBox.x = (int)(x);
	boundingBox.y = (int)(y);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);
	return &boundingBox;
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
	if (y >= SCREEN_HEIGHT && yVel > 0) {
		y = 0;

	}

	x += xVel * MS_PER_UPDATE;
	y += yVel * MS_PER_UPDATE;
}

void Ball::collideCorrect(Ball *b) {
	// Not optimized at all, just roll with it
	double cx1 = (x + w / 2.0);
	double cy1 = (y + h / 2.0);
	double r1 = sqrt(2) * w/2;

	double cx2 = (b->x + b->w / 2.0);
	double cy2 = (b->y + b->h / 2.0);
	double r2 = sqrt(2)  * b->w/2;

	double distance = (cx2 - cx1) * (cx2 - cx1) + (cy2 - cy1) * (cy2 - cy1);
	double radiusDis = (r1*r1 + r2*r2);

	if (distance <= radiusDis) {
		swap(xVel, b->xVel);
		swap(yVel, b->yVel);
	}
	while (distance <= radiusDis) {
		cx1 += xVel * MS_PER_UPDATE;
		cy1 += yVel * MS_PER_UPDATE;
		cx2 += b->xVel * MS_PER_UPDATE;
		cy2 += b->yVel * MS_PER_UPDATE;
		distance = (cx2 - cx1) * (cx2 - cx1) + (cy2 - cy1) * (cy2 - cy1);
	}

	x = cx1 - w / 2.0;
	y = cy1 - h / 2.0;
	b->x = cx2 - b->w / 2.0;
	b->y = cy2 - b->h / 2.0;

}