#include "control_screen.h"

int key;
short c = 0;

bool change_controls(Player* a, Player* b)
{
	key = GetKeyPressed();

	if (key != NULL && key != KEY_P && key != KEY_ESCAPE)
	{
		switch (c)
		{
			case 0:
			{
				a->movement_up = key;
				c++;
			}break;
			case 1:
			{
				a->movement_down = key;
				c++;
			}break;
			case 2:
			{
				b->movement_up = key;
				c++;
			}break;
			case 3:
			{
				b->movement_down = key;
				c++;
			}break;
		}
	}
	key = NULL;

	if (c == CANT_KEYS)
	{
		c = 0;
		return true;
	}
	else
		return false;
}

void draw_change_controls()
{
	for (int i = 0; i < CANT_KEYS; i++)
	{

		switch (c)
		{
		case 0: {
			DrawText("Input UP control P1:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);
		}break;
		case 1:
		{
			DrawText("Input DOWN control P1:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

		}break;
		case 2:
		{
			DrawText("Input UP control P2:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

		}break;
		case 3:
		{
			DrawText("Input DOWN control P2:", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);

		}break;
		}
	}
}