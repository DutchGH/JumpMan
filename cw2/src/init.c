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
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	TTF_Init();
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096); //initialize sound
	//error handling for launching SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr,"SDL_Init failed %s", SDL_GetError());
	}
}

void initPlogs(GameState *game)
{
	for(int i = 0; i<8; i++)
	{
		game->plog[i].baseX = (i+1) * 6;
		game->plog[i].baseY = 384;
	}
	game->plog[0].baseX = (27*32);
	game->plog[1].baseX = (35*32);
	game->plog[2].baseX = (29*32);
	game->plog[3].baseX = (47*32);
	game->plog[4].baseX = (64*32);
	game->plog[5].baseX = (63*32);
	game->plog[6].baseX = (77*32);
	game->plog[7].baseX = (84*32);

	game->plog[2].baseY = (7*32);
	game->plog[4].baseY = (17*32);



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

	game->enemy = IMG_LoadTexture(game->renderer, "gfx/enemy.png");
	if(!game->enemy)
	{
		printf("CANNOT FIND OCT.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "gfx/spritesheetmod.png");
	if(!game->player.sheetTexture)
	{
		printf("CANNOT FIND SPRITESHEETMOD.PNG!\n");
		SDL_Quit();
		exit(1);
	}

	game->player.deathSheet = IMG_LoadTexture(game->renderer, "gfx/spritesheetDead.png");
	if(!game->player.deathSheet)
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

	game->bgMusic = Mix_LoadWAV("audio/bgMusic.wav");
	if(game->bgMusic != NULL)
	{
		Mix_VolumeChunk(game->bgMusic, 32);
	}
	game->dieSound = Mix_LoadWAV("death.wav");
	game->jumpSound = Mix_LoadWAV("jump.wav");
	game->victorySound = Mix_LoadWAV("victory.wav");

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

	//initPlogs(game);

	initStatusLives(game);
	initPlogs(game);

	//load the map
}

