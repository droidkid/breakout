#include "resources.h"
#include "game_constants.h"



Resources::Resources(SDLComponent *component)
{
	component->loadPNGintoTexture("assets/puzzlepack/png/element_green_rectangle.png", &greenBrickTexture);
	component->loadPNGintoTexture("assets/puzzlepack/png/ballGrey.png", &greyBallTexture);
	component->loadPNGintoTexture("assets/puzzlepack/png/ballBlue.png", &blueBallTexture);
	component->loadPNGintoTexture("assets/puzzlepack/png/paddleBlu.png", &paddleTexture);

	component->loadTTFfont("assets/fonts/kenpixel_high.ttf", GameConstants::FONT_SIZE_PT, &font);
}


Resources::~Resources()
{
	//TODO(chesetti): Free all resources here.
}
