#pragma once
#include "raylib.h"
#include "player.h"

#define CANT_KEYS 4

namespace Godziela_pong
{

	enum Control
	{
		UP_J1,
		DOWN_J1,
		UP_J2,
		DOWN_J2,
		finish
	};

	bool change_controls(Player* a, Player* b);

	void draw_change_controls();

}