#include "graphics.h"

Graphics::Graphics(SDLSystem * sdl) {
	this->renderer = sdl->getRenderer();
}

void Graphics::clearScreen() {
	SDL_RenderClear(renderer);
}

void Graphics::drawTexture(SDL_Texture *texture, SDL_Rect *boundingBox) {
	SDL_RenderCopy(renderer, texture, NULL, boundingBox);
}

void Graphics::renderScreen() {
	SDL_RenderPresent(renderer);
}
