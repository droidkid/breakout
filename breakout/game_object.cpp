#include "game_object.h"

GameObject::GameObject() {
	// Responsibility of sub objects to specify these.
	this->physicsComponent = NULL;
	this->graphicsComponent = NULL;
	this->gameEventNotifier = NULL;
}

void GameObject::draw(double interpolation, Graphics *graphics) {
	graphicsComponent->draw(interpolation, graphics);
}

void GameObject::update(InputQueue *inputQueue) {
	physicsComponent->update();
}

GraphicsComponent* GameObject::getGraphics() {
	return this->graphicsComponent;
}

GameEventNotifier* GameObject::getGameEventNotifier() {
	return this->gameEventNotifier;
}

PhysicsComponent* GameObject::getPhysics() {
	return this->physicsComponent;
}

GameObject::~GameObject() {
}
