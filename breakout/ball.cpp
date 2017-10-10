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

PhysicsComponent* Ball::getPhysicsComponent() {
	return &(this->physicsComponent);
}


void Ball::draw(SDL_Renderer *renderer, double interpolation) {
}

void Ball::update() {
	physicsComponent.update();
}
