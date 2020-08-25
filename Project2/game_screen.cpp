#include "game_screen.h"

game_type game_Type;

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
}
void input()
{
	//Player 1 movement
	if (IsKeyDown(KEY_W))
		players[PLAYER1].rec.y -= VEL_PLAYER * GetFrameTime();
	if (IsKeyDown(KEY_S))
		players[PLAYER1].rec.y += VEL_PLAYER * GetFrameTime();
	//Player 2 movement
	//
	if (game_Type != PvP) {
		if (ball.ball_position.y < players[PLAYER2].rec.y && ball.ball_position.x >= GetScreenWidth() / 2) {
			players[PLAYER2].rec.y -= VEL_PLAYER * GetFrameTime();
		}
		if (ball.ball_position.y > players[PLAYER2].rec.y && ball.ball_position.x >= GetScreenWidth() / 2) {
			players[PLAYER2].rec.y += VEL_PLAYER * GetFrameTime();
		}
	}
	else {
		if (IsKeyDown(KEY_UP))
			players[PLAYER2].rec.y -= VEL_PLAYER * GetFrameTime();
		if (IsKeyDown(KEY_DOWN))
			players[PLAYER2].rec.y += VEL_PLAYER * GetFrameTime();
	}
}
void init_game_Type()
{
	game_Type = PvP;
}
//
