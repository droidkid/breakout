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

void CollisionEngine::setPaddle(Paddle *paddle) {
	this->paddle = paddle;
}

void CollisionEngine::update() {

	for (int i = 0; i < numBricks; i++) {
		if (bricks[i].isExists() && handleBallBrickCollision(ball->getPhysics(), bricks[i].getPhysics())) {
			bricks[i].makeDisappear();
			break;
		}
		handleBallPaddleCollision(ball->getPhysics(), paddle->getPhysics());
	}

}


int CollisionEngine::handleBallBrickCollision(PhysicsComponent *ballPhysics, PhysicsComponent *brickPhysics) {
	Rect r1 = ballPhysics->getRect();
	Rect r2 = brickPhysics->getRect();

	if (isRectIntersect(r1, r2)) {
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


		return 1;
	}

	return 0;
}

int CollisionEngine::handleBallPaddleCollision(PhysicsComponent *ballPhysics, PhysicsComponent *brickPhysics) {
	Rect r1 = ballPhysics->getRect();
	Rect r2 = brickPhysics->getRect();

	if (isRectIntersect(r1, r2)) {
		Vec2d disp = getDisplacementVector(r1, r2);

		double yVel = ball->getPhysics()->getYVelocity();
		double xVel = ball->getPhysics()->getXVelocity();

		// Set X Velocity
		double ball_cx = r1.x + (r1.w / 2);
		double ball_cy = r1.y + (r1.h / 2);
		double paddle_cx = r2.x + (r2.w / 2);
		double paddle_cy = r2.y + (r2.h / 2);

		double offset = (ball_cx - paddle_cx)/ (r2.w/2);

		if (fabs(disp.y) < fabs(disp.x)) {
			if (ball_cy > paddle_cy) {
				ball->getPhysics()->setYVel(fabs(yVel));
			}
			else {
				ball->getPhysics()->setYVel(-fabs(yVel));
			}
			// handle x collision


			double dist = (ball_cx - paddle_cx) / (r2.w / 2);
			ball->getPhysics()->setXVel(dist * 0.65);
			ball->getPhysics()->setY(r1.y - disp.y);
		}
		else {
			if (ball_cx > paddle_cx) {
				ball->getPhysics()->setXVel(fabs(xVel));
				double dist = (ball_cx - paddle_cx) / (r2.w / 2);
				ball->getPhysics()->setXVel(dist * 0.65);
			}
			else {
				ball->getPhysics()->setXVel(-fabs(xVel));
			}
			ball->getPhysics()->setX(r1.x - disp.x);
		}


		return 1;
	}

	return 0;
}

CollisionEngine::~CollisionEngine()
{
}
