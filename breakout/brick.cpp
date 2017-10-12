#include "brick.h"



Brick::Brick() : GameObject()
{
	this->physicsComponent = new PhysicsComponent();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}


Brick::~Brick()
{
}
