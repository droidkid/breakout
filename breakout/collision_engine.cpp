#include "collision_engine.h"
#include "geometry.h"
#include <stdio.h>

CollisionEngine::CollisionEngine()
{
}

void CollisionEngine::setBall(Ball * ball)
{
	this->ball = ball;
}

void CollisionEngine::setBricks(Brick * bricks, int numBricks)
{
	this->numBricks = numBricks;
	this->bricks = bricks;
}

int CollisionEngine::detectCollision(PhysicsComponent *physics1, PhysicsComponent *physics2)
{
	Rect r1 = physics1->getRect();
	Rect r2 = physics2->getRect();

	if (isRectIntersect(r1, r2)) {
		return 1;
	}
	return 0;
}

void CollisionEngine::update() {

	for (int i = 0; i < numBricks; i++) {
		if (detectCollision(ball->getPhysics(), bricks[i].getPhysics())) {
			// handle ball collision
			// do brick action.
		}
		// check paddle ball collision
	}

}


CollisionEngine::~CollisionEngine()
{
}
