#include "game_object.h"



GameObject::GameObject()
{
}

void GameObject::draw(double interpolation) {
	graphicsComponent->draw(interpolation);
}

void GameObject::update() {
	physicsComponent->update();
}

GraphicsComponent* GameObject::getGraphics() {
	return this->graphicsComponent;
}

PhysicsComponent* GameObject::getPhysics() {
	return this->physicsComponent;
}

GameObject::~GameObject()
{
}
