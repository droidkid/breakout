#pragma once

#include "graphics_component.h"
#include "brick.h"
#include "paddle.h"
#include "ball.h"

class CollisionEngine
{
	Ball *ball;
	Brick *bricks;
	Paddle *paddle;
	int numBricks;

	int handleBallBrickCollision(PhysicsComponent *p1, PhysicsComponent *p2);
	int handleBallPaddleCollision(PhysicsComponent *p1, PhysicsComponent *p2);
public:
	CollisionEngine();
	void setBall(Ball *ball);
	void setBricks(Brick *brick, int numBricks);
	void setPaddle(Paddle *paddle);
	void update();
	~CollisionEngine();
};

