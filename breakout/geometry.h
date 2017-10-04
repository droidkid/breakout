#pragma once

#include <SDL.h>


int rect_intersect(SDL_Rect *r1, SDL_Rect *r2);
int is_point_in_rect(int x, int y, SDL_Rect *r);