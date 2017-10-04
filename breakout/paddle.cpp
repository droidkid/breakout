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

void Paddle::update(int mouse_x, int mouse_y) {

	y = mouse_y;

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

int cou = 0;
void Paddle::collideCorrect(Ball *b) {

	int code = rect_intersect((b->getBoundingBox()), &boundingBox);

	bool swap_y = true;
	bool swap_x = false;

	if (code == 12 || code == 3 || code == 0) {
		swap_x = false;
	}
	if (code == 6 || code == 9 || code == 0) {
		swap_y = false;
	}

	if (swap_y) {
		b->yVel = -(b->yVel);
	}
	if (swap_x) {
		b->xVel = -(b->xVel);
	}

	while (code != 0) {
		b->update();
		code = rect_intersect((b->getBoundingBox()), &boundingBox);
	}

}