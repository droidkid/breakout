#pragma once
#include <SDL.h>
#include <stdio.h>
#include <math.h>

#include "geometry.h"

int isRectIntersect(Rect r1, Rect r2) {
	if (r1.x > r2.x + r2.w) return 0;
	if (r1.x + r1.w < r2.x) return 0;
	if (r1.y > r2.y + r2.h) return 0;
	if (r1.y + r1.h < r2.y) return 0;
	return 1;
}

Vec2d getDisplacementVector(Rect r1, Rect r2) {

	double y1Dist = r1.y - r2.y + r2.h;
	double y2Dist = r1.y + r1.h - r2.y;

	double x1Dist = r1.x - (r2.x + r2.w);
	double x2Dist = r1.x + r1.w - r2.x;

	double yDisp = (fabs(y1Dist) < fabs(y2Dist)) ? y1Dist : y2Dist;
	double xDisp = (fabs(x1Dist) < fabs(x2Dist)) ? x1Dist : x2Dist;

	return Vec2d(xDisp, yDisp);
}


