#include "physics_component.h"
#include "game_constants.h"

PhysicsComponent::PhysicsComponent()
{
	// TODO(chesetti): Add default values here
}

void PhysicsComponent::setX(double x)
{
	this->x = x;
}

void PhysicsComponent::setY(double y)
{
	this->y = y;
}

void PhysicsComponent::setXY(double x, double y)
{
	setX(x);
	setY(y);
}

void PhysicsComponent::setWidth(double w)
{
	this->w = w;
}

void PhysicsComponent::setHeight(double h)
{
	this->h = h;
}

void PhysicsComponent::setSize(double w, double h)
{
	setWidth(w);
	setHeight(h);
}

void PhysicsComponent::setXYAndSize(double x, double y, double w, double h)
{
	setX(x);
	setY(y);
	setWidth(w);
	setHeight(h);
}

void PhysicsComponent::setXVel(double xVel)
{
	this->xVel = xVel;
}

void PhysicsComponent::setYVel(double yVel)
{
	this->yVel = yVel;
}

void PhysicsComponent::setVelocity(double xVel, double yVel)
{
	setXVel(xVel);
	setYVel(yVel);
}

double PhysicsComponent::getX()
{
	return x;
}

double PhysicsComponent::getY()
{
	return y;
}

double PhysicsComponent::getWidth()
{
	return w;
}

double PhysicsComponent::getHeight()
{
	return h;
}

double PhysicsComponent::getXVelocity()
{
	return xVel;
}

double PhysicsComponent::getYVelocity()
{
	return yVel;
}

void PhysicsComponent::update() {
	x = x + xVel * GameConstants::UPDATES_PER_SECOND;
	y = y + yVel * GameConstants::UPDATES_PER_SECOND;
}


PhysicsComponent::~PhysicsComponent()
{
}
