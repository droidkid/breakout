#pragma once
#include "physics_component.h"
#include "graphics_component.h"

class GameObject {
protected:
	// Should be initialized in subclass constructor.
	// These are the minimum components every Game Object should have
	PhysicsComponent *physicsComponent;
	GraphicsComponent *graphicsComponent;
public:
	GameObject();
	GameObject(PhysicsComponent *physicsComponent, GraphicsComponent *graphicsComponent);
	~GameObject();
	PhysicsComponent* getPhysics();
	GraphicsComponent *getGraphics();
	// If adding new components, update the update() and draw() methods too
	void update();
	virtual void draw(double interpolation);
};

