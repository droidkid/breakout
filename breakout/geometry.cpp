#pragma once
#include <SDL.h>
#include <stdio.h>

#include "geometry.h"

int isRectIntersect(Rect r1, Rect r2) {
	if (r1.x > r2.x + r2.w) return 0;
	if (r1.x + r1.w < r2.x) return 0;
	if (r1.y > r2.y + r2.h) return 0;
	if (r1.y + r1.h < r2.y) return 0;
	return 1;
}


