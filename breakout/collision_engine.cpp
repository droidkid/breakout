#include "collision_engine.h"
#include "geometry.h"
#include <algorithm>
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

		int cnt = 0;
	for (int i = 0; i < numBricks; i++) {
		if (bricks[i].isExists() && detectCollision(ball->getPhysics(), bricks[i].getPhysics())) {
			Rect r1 = ball->getPhysics()->getRect();
			Rect r2 = bricks[i].getPhysics()->getRect();

			cnt++;

			double yVel = ball->getPhysics()->getYVelocity();
			double xVel = ball->getPhysics()->getXVelocity();

			double y1Dist = r1.y - r2.y + r2.h;
			double y2Dist = r1.y + r1.h - r2.y;

			double x1Dist = r1.x - (r2.x + r2.w);
			double x2Dist = r1.x + r1.w - r2.x;

			double yDisp = (abs(y1Dist) < abs(y2Dist)) ? y1Dist : y2Dist;
			double xDisp = (abs(x1Dist) < abs(x2Dist)) ? x1Dist : x2Dist;

			printf("%0.8f %0.8f\n", xDisp, yDisp);

			if (abs(yDisp) < abs(xDisp)) {
				if (yVel * yDisp >= 0) {
					ball->getPhysics()->setYVel(-yVel);
					printf("yReflected!\n");
				}
				printf("yCorrected!\n");
				ball->getPhysics()->setY(r1.y - yDisp);
			}
			else {
				if (xVel * xDisp >= 0) {
					ball->getPhysics()->setXVel(-xVel);
					printf("xReflected!\n");
				}
				printf("xCorrected! %f %f\n" , ball->getPhysics()->getXVelocity(), xDisp);
				ball->getPhysics()->setX(r1.x - xDisp);
			}
			bricks[i].makeDisappear();
			break;
		}
		// check paddle ball collision
	}
	if (cnt > 0) {
		printf("%d\n", cnt);
	}

}


CollisionEngine::~CollisionEngine()
{
}
