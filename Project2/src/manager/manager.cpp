#include "manager.h"

void init();
void update();
void update_game();
void draw();
gameState game_state;
Ball ball;
//aux, later change or remove them
bool game_start = false;
bool window_open;
float speed_up = 60.0f;
float foo;


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
	case MENU:
	{
		draw_menu();
		button_action();
	}
	break;
	case GAME:
	{
		draw_game();
	}
	break;
	case CREDITS:
	{
		draw_credits();
	}break;
	}


	EndDrawing();
}

void update()
{
	switch (game_state)
	{
	case MENU:
	{
		reset_pos_players();
		reset_ball();
		game_start = false;

		switch (button_action())
		{
		case 0:
		{
			game_Type = PvP;
			game_state = GAME;
		}break;
		case 1:
		{
			game_state = GAME;
			game_Type = PvB;
		}break;
		case 2:
		{
			game_state = CREDITS;
		}break;
		case 3:
		{
			EndDrawing();
			CloseWindow();
			window_open = false;
		}break;
		}

		if (IsKeyPressed(KEY_SPACE))
		{ 
			game_state = GAME;
		}
		if (IsKeyPressed(KEY_ESCAPE))
		{
			EndDrawing();
			CloseWindow();
			window_open = false;
		}
		if (IsKeyPressed(KEY_C))
		{
			switch ((game_Type))
			{
			case PvP:
			{
				game_Type = PvB;
			}break;
			case PvB:
			{
				game_Type = PvP;
			}break;
			}
		}
	}
	break;
	case GAME:
	{
		update_game();
		if (IsKeyPressed(KEY_ESCAPE))
			game_state = MENU;
	}
	break;
	case CREDITS:
	{
		if (IsKeyPressed(KEY_ESCAPE))
			game_state = MENU;
	}
	}
}




void check_pause()
{
	if (IsKeyPressed(KEY_P)) game_start = !game_start;
	if (!game_start)
	{
		DrawText("Press Space or P to resume", GetScreenWidth() / 3, GetScreenHeight() / 4, 20, BLUE);
		DrawText("Press ESCAPE to go back to the menu", GetScreenWidth() / 3.5, GetScreenHeight() / 4 - 30, 20, BLUE);
		if (IsKeyPressed(KEY_SPACE)) game_start = !game_start;
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

void player_collitions()
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
		else  {
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



void update_game()
{
	//Check Pause
	check_pause();

	//Check ball-roof/floor collision
	if ((ball.ball_position.y >= (GetScreenHeight() - ball.ball_radius)) || (ball.ball_position.y <= ball.ball_radius)) ball.ball_speed.y *= -1.0f;

	//Points
	check_points();
	player_collitions();
}