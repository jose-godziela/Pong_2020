#include "game_screen.h"

namespace Godziela_pong
{
	game_type game_Type;
	Ball power_up_pickup;
	Class_power_up class_power_up;
	short random_time;
	short counter;
	short pos_x;
	short pos_y;

	void draw_game()
	{
		//point draw
		DrawText(FormatText("%i", players[PLAYER1].score), GetScreenWidth() / 2 - 30, GetScreenHeight() - 40, 20, RAYWHITE);
		DrawText(":", GetScreenWidth() / 2 - 15, GetScreenHeight() - 40, 20, RAYWHITE);
		DrawText(FormatText("%i", players[PLAYER2].score), GetScreenWidth() / 2 - 1, GetScreenHeight() - 40, 20, RAYWHITE);
		//player draw
		DrawRectangleRec(players[PLAYER1].rec, players[PLAYER1].color);
		DrawRectangleRec(players[PLAYER2].rec, players[PLAYER2].color);
		//ball draw
		DrawCircleV(ball.ball_position, ball.ball_radius, ball.color);
		//power_up draw
		if (power_up_pickup.active)
			DrawCircleV(power_up_pickup.ball_position, power_up_pickup.ball_radius, power_up_pickup.color);
	}
	void player_input()
	{
		//Player 1 movement
		if (IsKeyDown(players[PLAYER1].movement_up))
			players[PLAYER1].rec.y -= VEL_PLAYER * GetFrameTime();
		if (IsKeyDown(players[PLAYER1].movement_down))
			players[PLAYER1].rec.y += VEL_PLAYER * GetFrameTime();
		//Player 2 movement
		//
		if (game_Type != PvP) {
			if (ball.ball_position.y < players[PLAYER2].rec.y && ball.ball_position.x >= GetScreenWidth() / 2) {
				players[PLAYER2].rec.y -= VEL_PLAYER * GetFrameTime() * 0.9f;
			}
			if (ball.ball_position.y > players[PLAYER2].rec.y && ball.ball_position.x >= GetScreenWidth() / 2) {
				players[PLAYER2].rec.y += VEL_PLAYER * GetFrameTime() * 0.9f;
			}
		}
		else {
			if (IsKeyDown(players[PLAYER2].movement_up))
				players[PLAYER2].rec.y -= VEL_PLAYER * GetFrameTime();
			if (IsKeyDown(players[PLAYER2].movement_down))
				players[PLAYER2].rec.y += VEL_PLAYER * GetFrameTime();
		}
	}
	void init_game_Type()
	{
		//Init game type
		game_Type = PvP;
		counter = 0;

		//Init power_up
		power_up_pickup.ball_position = { 0,0 };
		power_up_pickup.ball_speed = { NULL, NULL };
		power_up_pickup.ball_speed_init = ball.ball_speed;
		power_up_pickup.ball_radius = POWER_UP_RADIUS;
		power_up_pickup.color = DARKGREEN;
		power_up_pickup.active = false;
		random_time = GetRandomValue(0, MAX_TIME_POWER_UP);
		pos_x = GetRandomValue(SCREEN_OFFSET_X, GetScreenWidth());
		pos_y = GetRandomValue(SCREEN_OFFSET_Y, GetScreenHeight());
	}

	void power_up()
	{
		if (counter == random_time)
		{
			power_up_pickup.ball_position.x = pos_x;
			power_up_pickup.ball_position.y = pos_y;
			power_up_pickup.power_up = NULL;
			power_up_pickup.active = true;

			//I have to do this, because it won't let me compare Vector2 with another Vector2
			if (CheckCollisionCircles(power_up_pickup.ball_position,power_up_pickup.ball_radius
									  ,ball.ball_position,ball.ball_radius))
			{
				pos_x = GetRandomValue(SCREEN_OFFSET_X, GetScreenWidth());
				pos_y = GetRandomValue(SCREEN_OFFSET_Y, GetScreenHeight());
				power_up_pickup.active = false;
				counter = 0;
			}
		}
		else
			counter++;
	}
	void reset_power_up()
	{
		power_up_pickup.active = false;
	}
}