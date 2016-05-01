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
	TTF_Init();

	//error handling for launching SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr,"SDL_Init failed %s", SDL_GetError());
	}
}

void initPlogs(GameState *game)
{

}

void loadGame(GameState *game)
{
    loadMap(game);
    game->globalTime = 0;

    game->bg = IMG_LoadTexture(game->renderer, "gfx/bg3.png");
	if(!game->bg)
	{
		printf("CANNOT FIND OCT.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	game->enemy = IMG_LoadTexture(game->renderer, "gfx/oct.png");
	if(!game->enemy)
	{
		printf("CANNOT FIND OCT.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "spritesheetmod.png");
	if(!game->player.sheetTexture)
	{
		printf("CANNOT FIND SPRITESHEETMOD.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	game->brick = IMG_LoadTexture(game->renderer, "gfx/brick2.png");
	if(!game->brick)
	{
		printf("CANNOT FIND BRICK.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	//LOAD FONT
	game->font = TTF_OpenFont("fonts/VCR.ttf",48);
	if(!game->font)
	{
		printf("CANNOT FIND FONT FILE!\n");
		SDL_Quit();
		exit(1);
	}

	game->label = NULL;


	game->player.x = 0;
	game->player.y = 378;
    game->player.dx = 0;
    game->player.dy = 0;
    game->player.onLedge = 0;
    game->player.slowingDown = 0;
    game->player.facingLeft = 0;
	game->player.jumpCount = 0;
	game->scrollX = 0;
	game->player.lives = 3;
	game->player.isDead = 0;
	game->gameStatus = GAME_STATE_LIVES;
	game->deathTime = -1;
	initPlogs(game);

	initStatusLives(game);

	//load the map
}

