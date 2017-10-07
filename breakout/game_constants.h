#pragma once
namespace GameConstants {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const int FONT_SIZE_PT = 28;
	const int UPDATES_PER_SECOND = 520; // GAME SPEED, game is updated this times a second
	const int MS_PER_UPDATE = 1000 / UPDATES_PER_SECOND;

	const int NUM_BALLS = 10;
	const double BALL_VELOCITY = 0.1;
	const int BALL_SIZE = 15;

	const int BRICK_ROWS = 7;
	const int BRICK_COLS = 5;
	const int BRICK_HEIGHT = 20;
	const int BRICK_WIDTH = 50;
	const int NUM_BRICKS = BRICK_COLS * BRICK_ROWS;
}