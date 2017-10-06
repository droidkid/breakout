#pragma once
#include <SDL.h>
#include <stdio.h>

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

int to_pull_up(SDL_Rect *ball, SDL_Rect *box) {
	return abs(ball->y + ball->h - box->y);
}
int to_pull_down(SDL_Rect *ball, SDL_Rect *box) {
	return abs(ball->y - box->y - box->h);
}
int to_pull_right(SDL_Rect *ball, SDL_Rect *box) {
	return abs(ball->x  - box->x - box->w);
}
int to_pull_left(SDL_Rect *ball, SDL_Rect *box) {
	return abs(ball->x + ball->w - box->x);
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

