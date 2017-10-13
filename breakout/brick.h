#pragma once
#include "game_object.h"

class Brick : public GameObject
{
	int exists;
public:
	Brick();
	int isExists();
	void makeDisappear();
	virtual void draw(double interpolation);
	~Brick();
};

