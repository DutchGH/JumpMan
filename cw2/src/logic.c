/*
 * logic.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void updateLogic(GameState *game)
{
	game->globalTime++;
	if(game->globalTime > 120)
	{
		game->gameStatus =GAME_STATE_GAME;

	}
	if(game->gameStatus == GAME_STATE_GAME)
	{
		//increase co-ordinates with directional velocity
		game->player.x += game->player.dx;
		game->player.y += game->player.dy;
		//reset double jump counter once player lands
		if(game->player.onLedge == 1)
		{
			game->player.jumpCount = 0;
		}
		//impose gravity upon the player
		game->player.dy += GRAVITY;
	}

	game->scrollX = -game->player.x+320;
	if(game->scrollX > 0)
	{
		game->scrollX = 0;
	}
	if(game->player.x < 0)
	{
		game->player.x = 0;
	}
}


