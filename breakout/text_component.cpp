#include "text_component.h"

// Merge into Resources, make all text textures at start.

TextComponent::TextComponent(SDLHelper *sdlComponent, Resources *resources) {
	this->textColor = { 255, 0,0 }; // White for text.
	this->font = resources->font;
	this->renderer = sdlComponent->getRenderer();
}

// TODO(chesetti): Create all resources at start and reuse. Fix SDL_Render stuff.
void TextComponent::drawText(char *text, Vec2d pos) {
	SDL_RenderClear(renderer);
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
	SDL_Rect boundingBox;

	boundingBox.x = pos.x;
	boundingBox.y = pos.y;
	boundingBox.w = textSurface->w;
	boundingBox.h = textSurface->h;

	SDL_RenderCopy(renderer, texture, NULL, &boundingBox);
	SDL_RenderPresent(renderer);
}


TextComponent::~TextComponent() {
}
