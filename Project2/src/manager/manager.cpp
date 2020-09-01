#include "manager.h"
#include <iostream>

void init();
void update();
void update_game();
void draw();
void input();

gameState game_state;
Ball ball;
//aux, later change or remove them
bool game_start = false;
bool window_open;
float speed_up = 60.0f;
float foo;
bool exit_controls;


void init()
{
	SetExitKey(NULL);
	init_players();
	init_ball();
	init_buttons();
	init_game_Type();
}


void game()
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window Test");
	window_open = true;
	SetTargetFPS(FPS);
	init();

	while (!WindowShouldClose() && window_open)
	{
		input();
		draw();
		update();
	}

	if (window_open)
		CloseWindow();

}

void draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	switch (game_state)
	{
	case gameState::MENU:
	{
		draw_menu();
		button_action();
	}
	break;
	case gameState::GAME:
	{
		draw_game();
	}
	break;
	case gameState::CREDITS:
	{
		draw_credits();
	}break;
	case gameState::CONTROL_SCREEN:
	{
		draw_change_controls();
	}break;
	}


	EndDrawing();
}

void update()
{
	switch (game_state)
	{
	case gameState::MENU:
	{
		reset_pos_players();
		reset_ball();
		game_start = false;

		switch (button_action())
		{
		case 0:
		{
			game_Type = PvP;
			game_state = gameState::GAME;
		}break;
		case 1:
		{
			game_Type = PvB;
			game_state = gameState::GAME;
		}break;
		case 2:
		{
			game_state = gameState::CREDITS;
		}break;
		case 3:
		{
			game_state = gameState::CONTROL_SCREEN;
		}break;
		case 4:
		{
			EndDrawing();
			CloseWindow();
			window_open = false;
		}break;

		}
	}
	break;
	case gameState::GAME:
	{
		update_game();
	}
	break;
	case gameState::CREDITS:
	{
		if (IsKeyPressed(KEY_ESCAPE))
			game_state = gameState::MENU;
	}break;
	case gameState::CONTROL_SCREEN:
	{
		exit_controls = change_controls(&players[PLAYER1], &players[PLAYER2]);
		
		
		if (exit_controls) {
			game_state = gameState::MENU;
			std:: cout << "ME RAJO" << std::endl;
		}
	}break;
	}
}




void check_pause()
{
	if (IsKeyPressed(KEY_P) || IsKeyReleased(KEY_ESCAPE)) game_start = !game_start;

	if (!game_start)
	{
		DrawText("Press Space or P to resume", GetScreenWidth() / 3, GetScreenHeight() / 4, 20, BLUE);
		DrawText("Press ESCAPE to go back to the menu", GetScreenWidth() / 3.5, GetScreenHeight() / 4 - 30, 20, BLUE);
		if (IsKeyPressed(KEY_SPACE)) game_start = !game_start;
		if (IsKeyPressed(KEY_ESCAPE))
			game_state = gameState::MENU;
	}
}

void check_points()
{
	if (ball.ball_position.x <= 0) {
		players[PLAYER2].score++;
		ball.ball_speed = ball.ball_speed_init;
		ball.ball_position = ball.ball_position_init;
		ball.color = WHITE;
		reset_pos_players();
		game_start = false;
	}
	if (ball.ball_position.x >= GetScreenWidth()) {
		players[PLAYER1].score++;
		reset_pos_players();
		ball.ball_position = ball.ball_position_init;
		ball.ball_speed = ball.ball_speed_init;
		ball.color = WHITE;
		game_start = false;
	}
}

void player_collisions()
{
	//Player-Ball Collision
	if (CheckCollisionCircleRec(ball.ball_position, ball.ball_radius, players[PLAYER1].rec) ||
		CheckCollisionCircleRec(ball.ball_position, ball.ball_radius, players[PLAYER2].rec)) {
		ball.ball_speed.x *= -1.0f;
		if (ball.ball_speed.x < 0) {
			ball.ball_speed.x -= speed_up;
			ball.ball_speed.y = (ball.ball_position.y - players[PLAYER1].rec.y) / (players[PLAYER1].rec.x / 2) * 6;
			ball.ball_position.x -= ball.ball_radius;
		}
		else {
			ball.ball_speed.x += speed_up;
			ball.ball_speed.y = (ball.ball_position.y - players[PLAYER2].rec.y) / (players[PLAYER2].rec.x / 2) * 6;
			ball.ball_position.x += ball.ball_radius;
		}
	}
	//wall player's collition
	if (players[PLAYER1].rec.y > GetScreenHeight() - players[PLAYER1].rec.height) players[PLAYER1].rec.y = (float)GetScreenHeight() - 80;
	if (players[PLAYER1].rec.y < 0) players[PLAYER1].rec.y = 0;
	if (players[PLAYER2].rec.y > GetScreenHeight() - players[PLAYER2].rec.height) players[PLAYER2].rec.y = (float)GetScreenHeight() - 80;
	if (players[PLAYER2].rec.y < 0) players[PLAYER2].rec.y = 0;
	if (game_start) {
		ball.ball_position.x += ball.ball_speed.x * GetFrameTime();
		ball.ball_position.y += ball.ball_speed.y * GetFrameTime();
	}
}

void input()
{
	if (game_start)
	{
		player_input();
	}
}

void update_game()
{
	//Check Pause
	check_pause();

	//Check ball-roof/floor collision
	if ((ball.ball_position.y >= (GetScreenHeight() - ball.ball_radius)) || (ball.ball_position.y <= ball.ball_radius))
		ball.ball_speed.y *= -1.0f;

	//Points
	check_points();
	player_collisions();
}