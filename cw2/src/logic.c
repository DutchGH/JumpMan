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
	//printf("SCROLLX VALUE = %g\n", game->scrollX);
	printf("playerposition: %g\n", game->player.x);
	if(game->scrollX > 0)
	{
		game->scrollX = 0;
	}
	else if(game->scrollX < 800-game->map.maxX)
	{
		game->scrollX = 800-game->map.maxX;
	}
	if (game->player.x > game->map.maxX-30)
	{
		game->player.x = game->map.maxX-30;
	}
	if(game->player.x < 0)
	{
		game->player.x = 0;
	}

}


