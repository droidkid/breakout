#pragma once
#include "physics_component.h"
#include "graphics_component.h"
#include "event_queue.h"

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
	void update(EventQueue *eventQueue);
	virtual void draw(double interpolation, Graphics *graphics);
};

