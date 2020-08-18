#include "menu_screen.h"

Button buttons[CANT_BUTTONS];
Button_type button_type;

void draw_buttons();

void draw_menu()
{

	DrawText("Need name for pong ripoff", GetScreenWidth() / 5, GetScreenHeight() / 5, 30, RED);
	DrawText("press space to begin", GetScreenWidth() / 3, GetScreenHeight() / 3, 20, RED);
	DrawText("Controls: WS (player1) / UP DOWN (player2)", GetScreenWidth() / 5, GetScreenHeight() / 10, 20, RAYWHITE);
	//draw_buttons();
}

void init_buttons()
{
	short aux_y, aux_x;
	aux_x = GetScreenWidth() / 3;
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
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				switch (button_type)
				{
				case vs_player:
				{
					//don't activate IA player
					return 0;
				}break;
				case vs_IA:
				{
					//Activate IA player
					return 1;
				}break;
				case credits:
				{
					//Show credits screen
					return 2;
				}break;
				case close_game:
				{
					//Close game (duh!)
					return 3;
				}break;
				}
			}

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