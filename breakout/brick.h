#pragma once
#include "game_object.h"
#include "game_event_notifier.h"

class Brick : public GameObject {
	int exists;
public:
	Brick();
	int isExists();
	void makeDisappear();
	virtual void draw(double interpolation, Graphics *graphics);
	~Brick();
};

