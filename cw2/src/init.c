/*
 * init.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void initialiseSDL()
{
	//initialise SDL
	SDL_Init(SDL_INIT_VIDEO);

	//error handling for launching SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr,"SDL_Init failed %s", SDL_GetError());
	}
}


void loadGame(GameState *game)
{
    loadMap(game);
    game->globalTime = 0;

	game->enemy = IMG_LoadTexture(game->renderer, "gfx/oct.png");

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "spritesheetmod.png");

	game->brick = IMG_LoadTexture(game->renderer, "gfx/greybrick.png");

	//setting inital parameters for the player
	game->player.x = 0;
	game->player.y = 378;
    game->player.dx = 0;
    game->player.dy = 0;
    game->player.onLedge = 0;
    game->player.slowingDown = 0;

    game->player.facingLeft = 0;
	//prevents automatic movement bug
	game->player.jumpCount = 0;

	//load the map
}

