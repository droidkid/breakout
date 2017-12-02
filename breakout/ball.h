#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "game_object.h"
#include "game_event_notifier.h"

class Ball : public GameObject {

public:
	Ball();
};