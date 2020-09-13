#pragma once
#include "raylib.h"

const int TOTAL_PLAYERS = 2;
const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int VEL_PLAYER = 385.0f;

namespace Godziela_pong
{

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
}