//Reason to change menu, game and credits screens to diff .cpp is to be able to modify all different screens without creating unexpected 
#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H
#include "raylib.h"

const int CANT_BUTTONS = 5;
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 30;
const int BUTTON_SPACE = 50;

namespace Godziela_pong
{

	void draw_menu();
	void init_buttons();
	int button_action();

	struct Button
	{
		Rectangle rec;
		Color col;
	};

	extern Button buttons[CANT_BUTTONS];
}
#endif