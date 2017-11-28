#include "game_object.h"

GameObject::GameObject() {
	// Responsibility of sub objects to specify these.
	this->physicsComponent = NULL;
	this->graphicsComponent = NULL;
}

GameObject::GameObject(PhysicsComponent *physicsComponent, GraphicsComponent *graphicsComponent) :
	physicsComponent(physicsComponent), graphicsComponent(graphicsComponent) {
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

PhysicsComponent* GameObject::getPhysics() {
	return this->physicsComponent;
}

GameObject::~GameObject() {
}
