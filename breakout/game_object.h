#pragma once
#include "physics_component.h"
#include "graphics_component.h"

class GameObject
{
protected:
	// Should be initialized in subclass constructor.
	PhysicsComponent *physicsComponent;
	GraphicsComponent *graphicsComponent;
public:
	GameObject();
	~GameObject();
	void update();
	void draw(double interpolation);
	PhysicsComponent* getPhysics();
	GraphicsComponent *getGraphics();
};

