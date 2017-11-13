#pragma once

#include "geometry.h"

class PhysicsComponent {
protected:
	Rect box;
	Vec2d vel;
public:
	PhysicsComponent();
	void setX(double x);
	void setY(double y);
	void setXY(double x, double y);
	void setWidth(double w);
	void setHeight(double h);
	void setSize(double w, double h);
	void setXYAndSize(double x, double y, double w, double h);
	void setXVel(double xVel);
	void setYVel(double yVel);
	void setVelocity(double xVel, double yVel);

	double getX();
	double getY();
	double getWidth();
	double getHeight();
	double getXVelocity();
	double getYVelocity();

	Rect getRect();
	Vec2d getVelocity();

	virtual void update();

	~PhysicsComponent();
};

