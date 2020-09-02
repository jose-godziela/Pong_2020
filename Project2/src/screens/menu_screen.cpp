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

	draw_buttons();
	DrawText("Play vs Player",	static_cast<int>(buttons[0].rec.x) + aux_offset, static_cast<int>(buttons[0].rec.y), aux_font, RED);
	DrawText("Play vs IA",		static_cast<int>(buttons[1].rec.x) + aux_offset, static_cast<int>(buttons[1].rec.y), aux_font, RED);
	DrawText("Credits",			static_cast<int>(buttons[2].rec.x) + aux_offset, static_cast<int>(buttons[2].rec.y), aux_font, RED);
	DrawText("Change Controls",	static_cast<int>(buttons[3].rec.x) + aux_offset, static_cast<int>(buttons[3].rec.y), aux_font, RED);
	DrawText("Close Game",		static_cast<int>(buttons[4].rec.x) + aux_offset, static_cast<int>(buttons[4].rec.y), aux_font, RED);
}

void init_buttons()
{
	short aux_y, aux_x;
	aux_x = GetScreenWidth() / 4;
	aux_y = aux_x;

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
	for (int i = 0; i < CANT_BUTTONS; i++) {
		if (CheckCollisionPointRec(GetMousePosition(), buttons[i].rec))
		{
			buttons[i].col = SKYBLUE;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				return i;
			}
		}
		else
			buttons[i].col = BLUE;
	}
	return 5;
}

void draw_buttons()
{
	for (int i = 0; i < CANT_BUTTONS; i++)
	{
		DrawRectangleRec(buttons[i].rec, buttons[i].col);
	}
}