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
	boundingBox.x = (int)(x);
	boundingBox.y = (int)(y);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);
}

void Paddle::draw(SDL_Renderer *renderer, double interpolation) {
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

int cou = 0;
void Paddle::collideCorrect(Ball *b) {

	SDL_Rect *ball = b->getBoundingBox();
	SDL_Rect *box = &boundingBox;

	int code = rect_intersect((b->getBoundingBox()), &boundingBox);

	int dir = 0;

	if (code != 0) {
		int pull = to_pull_up(ball, box);
		if (pull > to_pull_down(ball, box)) {
			pull = to_pull_down(ball, box);
			dir = 1;
		}
		if (pull > to_pull_left(ball, box)) {
			pull = to_pull_left(ball, box);
			dir = 2;
		}
		if (pull > to_pull_right(ball, box)) {
			pull = to_pull_right(ball, box);
			dir = 3;
		}

		if (dir == 0) {
			printf("pull up\n");
			if (b->yVel > 0) {
				b->yVel = -(b->yVel);
			}
			if (b->y > y - b->h) {
				b->y = y - b->h;
			}
		}
		if (dir == 1) {
			if (b->yVel < 0) {
				b->yVel = -(b->yVel);
			}
			if (b->y < y + h) {
				b->y = y + h;
			}
		}
		if (dir == 2) {
			if (b->xVel > 0) {
				b->xVel = -(b->xVel);
			}
			if (b->x > x - b->w) {
				b->x = (x - b->w);
			}
		}
		if (dir == 3) {
			if (b->xVel < 0) {
				b->xVel = -(b->xVel);
			}
			if (b->x < x + w) {
				b->x = x + w;
			}
		}
	}

}