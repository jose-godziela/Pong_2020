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
#define CANT_PLAYERS 2

#include "player.h"
#include "ball.h"
#include "menu_screen.h"
#include "game_screen.h"
#include "credits_screen.h"
#include "control_screen.h"

void game();



enum class gameState
{
	MENU,
	GAME,
	CREDITS,
	CONTROL_SCREEN
};

extern gameState game_state;
