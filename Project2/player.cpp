#include "player.h"


float posX_player1 = 0;
float posX_player2 = 0;
float posY_players = 0;
float vel_player = 385.0f;
Player players[TOTAL_PLAYERS];

void init_players()
{
	posX_player1 = 10;
	posX_player2 = GetScreenWidth() - 20;
	posY_players = GetScreenHeight() / 2;


	for (int i = 0; i < TOTAL_PLAYERS; i++) {
		players[i].score = 0;
		players[i].size.x = 10.0f;
		players[i].size.y = 80.0f;

		players[i].rec.x = posX_player1;
		players[i].rec.y = posY_players;

		players[i].rec.width = players[i].size.x;
		players[i].rec.height = players[i].size.y;
		players[i].color = BLUE;

		if (i == PLAYER2)
		{
			//Player 2 X position and base color
			players[PLAYER2].rec.x = posX_player2;
			players[PLAYER2].color = RED;

		}
	}

}

void reset_pos_players()
{
	players[PLAYER1].rec.x = posX_player1;
	players[PLAYER1].rec.y = posY_players;
	players[PLAYER2].rec.x = posX_player2;
	players[PLAYER2].rec.y = posY_players;
}