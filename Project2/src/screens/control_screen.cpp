#include "control_screen.h"


namespace Godziela_pong
{


	int key;
	short ascii_offset = 32;
	short min_ascii, max_ascii;

	Control controls = UP_J1;


	bool change_controls(Player* a, Player* b)
	{
		min_ascii = 97;
		max_ascii = 122;
		key = GetKeyPressed();

		if (key >= min_ascii && key <= max_ascii)
			key -= ascii_offset;
		else if (key < min_ascii || key > max_ascii)
			key = NULL;

		if (key != NULL && ((key != KEY_P && key != KEY_P - 32) && key != KEY_ESCAPE))
		{
			switch (controls)
			{
			case UP_J1:
			{
				a->movement_up = key;
				controls = DOWN_J1;
			}break;
			case DOWN_J1:
			{
				a->movement_down = key;
				controls = UP_J2;
			}break;
			case UP_J2:
			{
				b->movement_up = key;
				controls = DOWN_J2;
			}break;
			case DOWN_J2:
			{
				b->movement_down = key;
				controls = finish;
			}break;
			}
		}
		key = NULL;

		if (controls == finish)
		{
			controls = UP_J1;
			return true;
		}
		else
			return false;
	}

	void draw_change_controls()
	{
		DrawText("Only letters for the moment", GetScreenWidth() / 4, GetScreenHeight() / 3, 15, BLUE);
		for (int i = 0; i < CANT_KEYS; i++)
		{
			switch (controls)
			{
			case UP_J1: {
				DrawText("Input UP control P1:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);
			}break;
			case DOWN_J1:
			{
				DrawText("Input DOWN control P1:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

			}break;
			case UP_J2:
			{
				DrawText("Input UP control P2:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

			}break;
			case DOWN_J2:
			{
				DrawText("Input DOWN control P2:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

			}break;
			}
		}
	}
}