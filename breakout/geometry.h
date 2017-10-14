#pragma once

#include <SDL.h>


class Vec2d {
public:
	double x, y;
	Vec2d() :x(0), y(0) {};
	Vec2d(double x, double y) :x(x), y(y) {};
};

class Rect {
public:
	double x, y;
	double w, h;
	Rect() : x(0), y(0), w(0), h(0) {};
	Rect(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {};

};

int isRectIntersect(Rect r1, Rect r2);

Vec2d getDisplacementVector(Rect r1, Rect r2);
