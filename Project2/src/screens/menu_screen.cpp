#include "menu_screen.h"
#include <iostream>

Button buttons[CANT_BUTTONS];

void draw_buttons();

//aux
int aux_offset = 5;
int aux_font = 30;


void draw_menu()
{

	DrawText("Need name for pong rip-off", GetScreenWidth() / 5, GetScreenHeight() / 5, 30, RED);
	DrawText("Controls: WS (player1) / UP DOWN (player2)", GetScreenWidth() / 5, GetScreenHeight() / 10, 20, RAYWHITE);

	draw_buttons();
	DrawText("Play vs Player", buttons[0].rec.x + aux_offset, buttons[0].rec.y, aux_font, RED);
	DrawText("Play vs IA", buttons[1].rec.x + aux_offset, buttons[1].rec.y, aux_font, RED);
	DrawText("Credits", buttons[2].rec.x + aux_offset, buttons[2].rec.y, aux_font, RED);
	DrawText("GTFO", buttons[3].rec.x + aux_offset, buttons[3].rec.y, aux_font, RED);
}

void init_buttons()
{
	short aux_y, aux_x;
	aux_x = GetScreenWidth() / 4;
	aux_y = aux_x;
	/* 4 buttons:
	* 1-PLayer vs player
	* 2-Player vs IA
	* 3-Credits
	* 4-Close
	*
	* 1 starts a 1v1 local game
	* 2 stars a 1vPC local game
	* 3 shows music, graphics and other things used in game
	* 4 closes the game
	*
	* Button is a rec, which will check if the mouse is hovering over it (change color/do something) and if it clicked on it (checkcollisionpointrec())
	*/


	//Initialize buttons
	for (int i = 0; i < CANT_BUTTONS; i++)
	{
		buttons[i].rec.width = BUTTON_WIDTH;
		buttons[i].rec.height = BUTTON_HEIGHT;
		buttons[i].rec.x = aux_x;
		buttons[i].rec.y = aux_y;
		buttons[i].col = BLUE;

		aux_y += BUTTON_SPACE;
	}

	//What will do each button

}

int button_action()
{

	for (int i = 0; i < CANT_BUTTONS; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), buttons[i].rec))
		{
			buttons[i].col = SKYBLUE;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttons[0].rec))
				return 0; //PvP
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttons[1].rec))
				return 1; //PvB
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttons[2].rec))
				return 2; //Credits
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), buttons[3].rec))
				return 3; //Close
		}
		else
			buttons[i].col = BLUE;
	}
}
void draw_buttons()
{
	for (int i = 0; i < CANT_BUTTONS; i++)
	{
		DrawRectangleRec(buttons[i].rec, buttons[i].col);
	}
}