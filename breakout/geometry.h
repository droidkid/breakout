#pragma once

#include <SDL.h>


int rect_intersect(SDL_Rect *r1, SDL_Rect *r2);
int is_point_in_rect(int x, int y, SDL_Rect *r);
int to_pull_up(SDL_Rect *ball, SDL_Rect *box);
int to_pull_down(SDL_Rect *ball, SDL_Rect *box);
int to_pull_right(SDL_Rect *ball, SDL_Rect *box);
int to_pull_left(SDL_Rect *ball, SDL_Rect *box);