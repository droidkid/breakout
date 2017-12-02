#include "brick.h"
#include "game_event_notifier.h"

Brick::Brick() : GameObject() {
	this->exists = 1;
	this->gameEventNotifier = new GameEventNotifier();
	this->physicsComponent = new PhysicsComponent();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}

int Brick::isExists() {
	return exists;
}

void Brick::makeDisappear() {
	if (exists == 1) {
		gameEventNotifier->notify(BRICK_DISAPPEAR);
	}
	exists = 0;
}

void Brick::draw(double interpolation, Graphics *graphics) {
	if (exists) {
		GameObject::draw(interpolation, graphics);
	}
}

Brick::~Brick() {
}
