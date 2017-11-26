#include "graphics_component.h"

// Holds texture and does drawing of sprite.

GraphicsComponent::GraphicsComponent(PhysicsComponent *physics) {
	this->physicsComponent = physics;
}

void GraphicsComponent::setTexture(SDL_Texture *texture) {
	this->texture = texture;
}

void GraphicsComponent::draw(double interpolation, Graphics *graphics) {
	double x = physicsComponent->getX();
	double y = physicsComponent->getY();
	double w = physicsComponent->getWidth();
	double h = physicsComponent->getHeight();
	double xVel = physicsComponent->getXVelocity();
	double yVel = physicsComponent->getYVelocity();

	boundingBox.x = (int)(x + xVel * interpolation);
	boundingBox.y = (int)(y + yVel * interpolation);
	boundingBox.w = (int)(w);
	boundingBox.h = (int)(h);

	graphics->drawTexture(texture, &boundingBox);
}

GraphicsComponent::~GraphicsComponent() {

}