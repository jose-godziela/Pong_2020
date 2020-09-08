#pragma once
#include "raylib.h"
#include "player.h"
#include "ball.h"

#define MAX_TIME_POWER_UP 25
#define SCREEN_OFFSET_X 100
#define SCREEN_OFFSET_Y 25
#define POWER_UP_RADIUS 10
namespace Godziela_pong
{
	enum game_type
	{
		PvP,
		PvB
	};
	enum Class_power_up
	{
		None = 0,
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
	void reset_power_up();
}