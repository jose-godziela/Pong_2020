#pragma once
#include <math.h>
#include "raylib.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define FPS 60

#include "player.h"
#include "ball.h"
#include "menu_screen.h"
#include "game_screen.h"

void game();



enum gameState
{
	MENU,
	GAME,
	CREDITS
};

extern gameState game_state;
