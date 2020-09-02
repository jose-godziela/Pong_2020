#include "control_screen.h"
#include <iostream>

int key;
short c = 0;
short ascii_offset = 32;
short min_ascii, max_ascii;

bool change_controls(Player* a, Player* b)
{
	min_ascii = 97;
	max_ascii = 122;
	key = GetKeyPressed();
	
	if (key >= min_ascii && key <= max_ascii) 
		key -= ascii_offset;

	if (key <= min_ascii && key >= max_ascii) 
		key = NULL;

	if (key != NULL && ((key != KEY_P && key != KEY_P - 32) && key != KEY_ESCAPE))
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