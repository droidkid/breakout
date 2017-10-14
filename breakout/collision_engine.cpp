#include "collision_engine.h"
#include "geometry.h"
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

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
		if (bricks[i].isExists() && detectCollision(ball->getPhysics(), bricks[i].getPhysics())) {
			Rect r1 = ball->getPhysics()->getRect();
			Rect r2 = bricks[i].getPhysics()->getRect();
			Vec2d disp = getDisplacementVector(r1, r2);

			double yVel = ball->getPhysics()->getYVelocity();
			double xVel = ball->getPhysics()->getXVelocity();

			if (fabs(disp.y) < fabs(disp.x)) {
				if (yVel * disp.y >= 0) {
					ball->getPhysics()->setYVel(-yVel);
				}
				ball->getPhysics()->setY(r1.y - disp.y);
			}
			else {
				if (xVel * disp.x >= 0) {
					ball->getPhysics()->setXVel(-xVel);
				}
				ball->getPhysics()->setX(r1.x - disp.x);
			}
			bricks[i].makeDisappear();
			break;
		}
		// check paddle ball collision
	}

}


CollisionEngine::~CollisionEngine()
{
}
