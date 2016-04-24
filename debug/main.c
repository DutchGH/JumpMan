/*
 ============================================================================
 Name        : main.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Main file for execution of program for SDL
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "structs.h"
#include "events.h"
#include "render.h"
#include "map.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
int globalTime = 0;

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
	SDL_Surface *surface = NULL;
	surface = IMG_Load("gfx/oct.png");
	if(surface == NULL)
	{
		fprintf(stderr, "Cannot find oct.png\n");
		SDL_Quit();
		exit(1);
	}

	game->enemy = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);


	surface = IMG_Load("spritesheetmod.png");
	if(surface == NULL)
	{
		fprintf(stderr, "Cannot find spritesheetmod.png\n");
		SDL_Quit();
		exit(1);
	}

	game->player.sheetTexture = SDL_CreateTextureFromSurface(game->renderer, surface);
	printf("sheet loaded");
	SDL_FreeSurface(surface);

	surface = IMG_Load("gfx/brick.png");
	if(surface == NULL)
	{
		fprintf(stderr, "Cannot find brick.png\n");
		SDL_Quit();
		exit(1);
	}
	game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	loadMap(game, "data/maps/map01.dat");






	//setting inital parameters for the player
	game->player.x = 400;
	game->player.y = 300;
	game->player.onLedge = 0;
	game->player.facingLeft = 1;

	//prevents automatic movement bug
	game->player.playerMovement.left = 0;
	game->player.playerMovement.right = 0;
	game->player.playerMovement.jumping = false;


}

void updateLogic(GameState *game)
{
  game->player.y += game->player.dy;
  game->player.dy += 0.5;
  if(game->player.y > 300)
  {
    game->player.y = 300;
    game->player.dy = 0;
  }
  globalTime++;
}


int main(int argc, char* argv[])
{
	GameState gameState; //create a new gamestate (with all containing sprites and elements)
	SDL_Window *window = NULL; //create a window to display on
	SDL_Renderer *renderer = NULL; //renderer for SDL
	//SDL_Surface *enemySurface = NULL; //pointer to load enemy texture


	//call function to launch SDL
	initialiseSDL();

	//create an application window
	window = SDL_CreateWindow("sc15j3h - COMP1921 Project", //name of window
							   SDL_WINDOWPOS_UNDEFINED,		//x position
							   SDL_WINDOWPOS_UNDEFINED,		//y position
							   SCREEN_WIDTH,				//width of window
							   SCREEN_HEIGHT,				//height of window
							   0);							//flags

	//create renderer with vsync to prevent screen tearing
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	//make sure all elements are renered in the same window
	gameState.renderer = renderer;
	loadGame(&gameState);

	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

	done = processEvents(window, &gameState);
	updateLogic(&gameState);
	doRender(renderer, &gameState);
	SDL_Delay(10);

	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.player.sheetTexture);

	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
