#pragma once
#include "raylib.h"
#include "player.h"
#include "ball.h"

enum game_type
{
	PvP,
	PvB
};

extern game_type game_Type;

void init_game_Type();
void draw_game();
void player_input();