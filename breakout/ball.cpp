#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>
using namespace std;

#include "game_constants.h"
#include "ball.h"
#include "physics_component.h"

#include <stdio.h>

using namespace GameConstants;

class BallPhysics : public PhysicsComponent {
	void update() {
		if (box.x <= 0 && vel.x < 0) {
			vel.x = -vel.x;
		}
		if (box.x + box.w >= SCREEN_WIDTH && vel.x > 0) {
			vel.x = -vel.x;
		}
		if (box.y <= 0 && vel.y < 0) {
			vel.y = -vel.y;
		}
		if (box.y >= SCREEN_HEIGHT && vel.y > 0) {
			vel.y = -vel.y;
		}

		PhysicsComponent::update();
	}
};

Ball::Ball()  {
	this->physicsComponent = new BallPhysics();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}
