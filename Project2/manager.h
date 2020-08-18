#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "raylib.h"

#define FPS 60
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480

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
