#include "brick.h"



Brick::Brick() : GameObject()
{
	this->exists = 1;
	this->physicsComponent = new PhysicsComponent();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}

int Brick::isExists() {
	return exists;
}

void Brick::makeDisappear() {
	exists = 0;
}

void Brick::draw(double interpolation) {
	if (exists) {
		GameObject::draw(interpolation);
	}
}

Brick::~Brick()
{
}
