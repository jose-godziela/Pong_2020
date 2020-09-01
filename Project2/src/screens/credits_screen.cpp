#include "credits_screen.h"



void draw_credits()
{
	DrawText("Programming: Felix Godziela", GetScreenWidth() / 5, GetScreenHeight() / 3, 30, DARKBLUE);

	DrawText("Press ESCAPE to go back",GetScreenWidth() / 10, GetScreenHeight() / 10, 20, DARKBLUE);
}