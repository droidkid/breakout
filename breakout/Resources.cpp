#include "resources.h"
#include "game_constants.h"



Resources::Resources(SDLComponent *component)
{
	component->loadPNGintoTexture("assets/puzzlepack/png/element_green_rectangle.png", &brickTextures[GREEN]);
	component->loadPNGintoTexture("assets/puzzlepack/png/element_red_rectangle.png", &brickTextures[RED]);
	component->loadPNGintoTexture("assets/puzzlepack/png/element_yellow_rectangle.png", &brickTextures[YELLOW]);
	component->loadPNGintoTexture("assets/puzzlepack/png/element_purple_rectangle.png", &brickTextures[PURPLE]);
	component->loadPNGintoTexture("assets/puzzlepack/png/element_blue_rectangle.png", &brickTextures[BLUE]);
	component->loadPNGintoTexture("assets/puzzlepack/png/element_grey_rectangle.png", &brickTextures[GREY]);

	component->loadPNGintoTexture("assets/puzzlepack/png/ballGrey.png", &greyBallTexture);
	component->loadPNGintoTexture("assets/puzzlepack/png/ballBlue.png", &blueBallTexture);
	component->loadPNGintoTexture("assets/puzzlepack/png/paddleBlu.png", &paddleTexture);

	component->loadTTFfont("assets/fonts/kenpixel_high.ttf", GameConstants::FONT_SIZE_PT, &font);
}


Resources::~Resources()
{
	//TODO(chesetti): Free all resources here.
}
