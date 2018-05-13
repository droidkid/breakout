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

void Graphics::drawText(char * text, Vec2d pos, TTF_Font *font, SDL_Color textColor) {
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);


	SDL_Rect boundingBox;
	boundingBox.x = pos.x;
	boundingBox.y = pos.y;
	boundingBox.w = textSurface->w;
	boundingBox.h = textSurface->h;

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(texture);
}

void Graphics::renderScreen() {
	SDL_RenderPresent(renderer);
}
