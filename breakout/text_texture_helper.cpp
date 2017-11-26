#include "text_texture_helper.h"

// Merge into Resources, make all text textures at start.

TextTextureHelper::TextTextureHelper(SDLHelper *sdlComponent, Resources *resources) {
	this->textColor = { 255, 255, 255}; // White for text.
	this->font = resources->font;
	this->renderer = sdlComponent->getRenderer();
}

SDL_Texture *TextTextureHelper::createTextTexture(char *text) {
	return createTextTexture(text, this->textColor);
}

SDL_Texture *TextTextureHelper::createTextTexture(char *text, SDL_Color textColor) {
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}


TextTextureHelper::~TextTextureHelper() {
}
