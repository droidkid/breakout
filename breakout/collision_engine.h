#pragma once

#include "graphics_component.h"
#include "brick.h"
#include "paddle.h"
#include "ball.h"

class CollisionEngine
{
	Ball *ball;
	Brick *bricks;
	int numBricks;
public:
	CollisionEngine();
	void setBall(Ball *ball);
	void setBricks(Brick *brick, int numBricks);
	void update();
	int detectCollision(PhysicsComponent *physics1, PhysicsComponent *physics2);
	~CollisionEngine();
};

