#pragma once
#include "raylib.h"
#define TOTAL_PLAYERS 2
#define PLAYER1 0
#define PLAYER2 1
#define VEL_PLAYER 385.0f

struct Player {
	Rectangle rec;
	Vector2 size;
	int score;
	Color color;
	int movement_up;
	int movement_down;
};

extern Player players[TOTAL_PLAYERS];

void init_players();
void reset_pos_players();