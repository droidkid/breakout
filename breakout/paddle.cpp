#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <algorithm>

#include "game_constants.h"
#include "paddle.h"
#include "geometry.h"

using namespace std;
using namespace GameConstants;

void PaddlePhysics::update(int mouse_x, int mouse_y) {
	if (mouse_x > SCREEN_WIDTH - getWidth()) {
		setX(SCREEN_WIDTH - getWidth());
	}
	else {
		setX(mouse_x);
	}
}

Paddle::Paddle() {
	this->paddlePhysics = new PaddlePhysics();
	this->physicsComponent = paddlePhysics;
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}


void Paddle::update(int mouse_x, int mouse_y) {
	paddlePhysics->update(mouse_x, mouse_y);
}