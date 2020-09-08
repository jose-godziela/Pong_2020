#pragma once
#include "raylib.h"
#include "player.h"
#include "ball.h"

#define MAX_TIME_POWER_UP 15
namespace Godziela_pong
{
	enum game_type
	{
		PvP,
		PvB
	};
	enum Class_power_up
	{
		Big_chungus = 1,
		More_speed,
		Shield,
		Obstacles,
	};

	extern game_type game_Type;
	extern Ball power_up_pickup;

	void init_game_Type();
	void draw_game();
	void player_input();
	void power_up();
}