#include "physics_component.h"
#include "game_constants.h"

PhysicsComponent::PhysicsComponent() {
}

void PhysicsComponent::setX(double x) {
	this->box.x = x;
}

void PhysicsComponent::setY(double y) {
	this->box.y = y;
}

void PhysicsComponent::setXY(double x, double y) {
	setX(x);
	setY(y);
}

void PhysicsComponent::setWidth(double w) {
	this->box.w = w;
}

void PhysicsComponent::setHeight(double h) {
	this->box.h = h;
}

void PhysicsComponent::setSize(double w, double h) {
	setWidth(w);
	setHeight(h);
}

void PhysicsComponent::setXYAndSize(double x, double y, double w, double h) {
	setX(x);
	setY(y);
	setWidth(w);
	setHeight(h);
}

void PhysicsComponent::setXVel(double xVel) {
	this->vel.x = xVel;
}

void PhysicsComponent::setYVel(double yVel) {
	this->vel.y = yVel;
}

void PhysicsComponent::setVelocity(double xVel, double yVel) {
	setXVel(xVel);
	setYVel(yVel);
}

double PhysicsComponent::getX() {
	return box.x;
}

double PhysicsComponent::getY() {
	return box.y;
}

double PhysicsComponent::getWidth() {
	return box.w;
}

double PhysicsComponent::getHeight() {
	return box.h;
}

double PhysicsComponent::getXVelocity() {
	return vel.x;
}

double PhysicsComponent::getYVelocity() {
	return vel.y;
}

Rect PhysicsComponent::getRect() {
	return box;
}

Vec2d PhysicsComponent::getVelocity() {
	return vel;
}

void PhysicsComponent::update() {
	box.x = box.x + vel.x * GameConstants::MS_PER_UPDATE;
	box.y = box.y + vel.y * GameConstants::MS_PER_UPDATE;
}


PhysicsComponent::~PhysicsComponent() {
}
