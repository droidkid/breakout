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

Paddle::Paddle() {
	this->physicsComponent = new PaddlePhysics();
	this->graphicsComponent = new GraphicsComponent(physicsComponent);
}


void Paddle::update(InputQueue *inputQueue) {
	int mouse_x = inputQueue->getMousePos().x;
	int mouse_y = inputQueue->getMousePos().y;
	if (mouse_x > SCREEN_WIDTH - physicsComponent->getWidth()) {
		physicsComponent->setX(SCREEN_WIDTH - physicsComponent->getWidth());
	}
	else {
		physicsComponent->setX(mouse_x);
	}
	physicsComponent->update();
}