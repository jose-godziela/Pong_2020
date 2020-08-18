#pragma once
#include "ball.h"

void init_ball()
{
	ball.ball_position_init.x = GetScreenWidth() / 2;
	ball.ball_position_init.y = GetScreenHeight() / 2;
	ball.ball_position = ball.ball_position_init;
	ball.ball_speed_init.x = 250.0f;
	ball.ball_speed_init.y = 400.0f;
	ball.ball_speed = ball.ball_speed_init;
	ball.color = GRAY;
	ball.ball_radius = 20;
}