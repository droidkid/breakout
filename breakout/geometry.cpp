#pragma once
#include <SDL.h>

#include "geometry.h"

int rect_intersect(SDL_Rect *r1, SDL_Rect *r2) {
	int ret = 0;
	// top left
	if (is_point_in_rect(r1->x, r1->y, r2)) {
		ret += 1;
	}
	// top right
	if (is_point_in_rect(r1->x + r1->w, r1->y, r2)) {
		ret += 2;
	}
	// bottom left
	if (is_point_in_rect(r1->x, r1->y + r1->h, r2)) {
		ret += 4;
	}
	// bottom right
	if (is_point_in_rect(r1->x + r1->w, r1->y + r1->h, r2)) {
		ret += 8;
	}
	return ret;
}

int is_point_in_rect(int x, int y, SDL_Rect *r) {

	if (x < r->x || x > r->x + r->w) {
		return 0;
	}
	if (y < r->y || y > r->y + r->h) {
		return 0;
	}
	return 1;
}

