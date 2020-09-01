//Reason to change menu, game and credits screens to diff .cpp is to be able to modify all different screens without creating unexpected errors
#pragma once
#include "raylib.h"

#define CANT_BUTTONS 4
#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 30
#define BUTTON_SPACE 50

void draw_menu();
void init_buttons();
int button_action();

struct Button
{
	Rectangle rec;
	Color col;
};

extern Button buttons[CANT_BUTTONS];