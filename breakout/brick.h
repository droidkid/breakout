#pragma once
#include "game_object.h"
#include "notifier.h"

class Brick : public GameObject {
	int exists;
	Notifier *notifier;
public:
	Brick();
	int isExists();
	void makeDisappear();
	void addObserver(Observer * observer);
	virtual void draw(double interpolation, Graphics *graphics);
	~Brick();
};

