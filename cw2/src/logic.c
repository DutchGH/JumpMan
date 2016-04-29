/*
 * logic.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void updateLogic(GameState *game)
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
	game->globalTime++;
}


