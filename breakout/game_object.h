#pragma once
#include "physics_component.h"
#include "graphics_component.h"
#include "input_queue.h"
#include "game_event_notifier.h"

class GameObject {
protected:
	// Should be initialized in subclass constructor.
	// These are the minimum components every Game Object should have
	PhysicsComponent *physicsComponent;
	GraphicsComponent *graphicsComponent;
	GameEventNotifier *gameEventNotifier;
public:
	GameObject();
	GameObject(PhysicsComponent *physicsComponent, GraphicsComponent *graphicsComponent);
	~GameObject();
	PhysicsComponent* getPhysics();
	GraphicsComponent *getGraphics();
	GameEventNotifier* getGameEventNotifier();
	void update(InputQueue *inputQueue);
	virtual void draw(double interpolation, Graphics *graphics);
};

