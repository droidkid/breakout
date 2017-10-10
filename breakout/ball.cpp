#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>
using namespace std;

#include "game_constants.h"
#include "ball.h"
#include "physics_component.h"

using namespace GameConstants;

class BallPhysics : public PhysicsComponent {
	void update() {
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
};

Ball::Ball() {
	this->physicsComponent = new BallPhysics();
}

void Ball::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

PhysicsComponent* Ball::getPhysics() {
	return (this->physicsComponent);
}


void Ball::draw(SDL_Renderer *renderer, double interpolation) {
	double x = physicsComponent->getX();
	double y = physicsComponent->getY();
	double w = physicsComponent->getWidth();
	double h = physicsComponent->getHeight();
	double xVel = physicsComponent->getXVelocity();
	double yVel = physicsComponent->getYVelocity();

	boundingBox.x = (int)(x + xVel * interpolation);
	boundingBox.y = (int)(y + yVel * interpolation);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
}

void Ball::update() {
	physicsComponent->update();
}
