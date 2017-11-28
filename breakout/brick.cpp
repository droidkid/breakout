#include "brick.h"
#include "event.h"

Brick::Brick() : GameObject() {
	this->exists = 1;
	this->physicsComponent = new PhysicsComponent();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
	this->notifier = new Notifier();
}

int Brick::isExists() {
	return exists;
}

void Brick::makeDisappear() {
	if (exists == 1) {
		notifier->notify(BRICK_DISAPPEAR);
	}
	exists = 0;
}

void Brick::addObserver(Observer *observer) {
	this->notifier->addObserver(observer);
}

void Brick::draw(double interpolation, Graphics *graphics) {
	if (exists) {
		GameObject::draw(interpolation, graphics);
	}
}

Brick::~Brick() {
}
