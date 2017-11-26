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


void Paddle::update(EventQueue *eventQueue) {
	int mouse_x = eventQueue->getMousePos().x;
	int mouse_y = eventQueue->getMousePos().y;
	if (mouse_x > SCREEN_WIDTH - physicsComponent->getWidth()) {
		physicsComponent->setX(SCREEN_WIDTH - physicsComponent->getWidth());
	}
	else {
		physicsComponent->setX(mouse_x);
	}
	physicsComponent->update();
}