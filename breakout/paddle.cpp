#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>
using namespace std;

#include "game_constants.h"
#include "paddle.h"
#include "geometry.h"

using namespace GameConstants;

void Paddle::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

void Paddle::setAsPaddle(bool val) {
	this->is_paddle = val;
}

void Paddle::setBoundingBox(double x, double y, double w, double h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	boundingBox.x = (int)(x);
	boundingBox.y = (int)(y);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);
}

void Paddle::draw(SDL_Renderer *renderer, double interpolation) {
	if (!exists) {
		return;
	}
	boundingBox.x = (int)(x + xVel * interpolation);
	boundingBox.y = (int)(y + yVel * interpolation);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
}

void Paddle::update(int mouse_x, int mouse_y) {

	//y = mouse_y;

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

	if (!exists) {
		return;
	}

}