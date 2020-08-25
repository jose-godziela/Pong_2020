//Reason to change menu, game and credits screens to diff .cpp is to be able to modify all different screens without creating unexpected errors
#pragma once
#include "raylib.h"

#define CANT_BUTTONS 4
#define BUTTON_WIDTH 100
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

enum Button_type
{
	vs_player,
	vs_IA,
	credits,
	close_game
};



extern Button_type button_type;
extern Button buttons[CANT_BUTTONS];