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
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
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
	
	game->enemy = IMG_LoadTexture(game->renderer, "gfx/oct.png");

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "spritesheetmod.png");

	game->brick = IMG_LoadTexture(game->renderer, "gfx/greybrick.png");

	//setting inital parameters for the player
	game->player.x = 400;
	game->player.y = 372;
	game->player.onLedge = 0;
	game->player.facingLeft = 1;

	//prevents automatic movement bug
	game->player.playerMovement.left = 0;
	game->player.playerMovement.right = 0;
	game->player.playerMovement.jumping = false;
	game->player.jumpCount = 0;
	
	//load the map
	loadMap(game);
	

}

void updateLogic(GameState *game)
{


  game->player.y += game->player.dy;
  game->player.dy += 0.5;
  if(game->player.y >= 372)
  {
    game->player.y = 372;
    game->player.dy = 0;
	game->player.jumpCount = 0; //do this only when /landing/ not when colliding.
  }
  else {
  }
  //~ printf("Player pos: %f\n",game->player.y);
  globalTime++;
}


int main(int argc, char* argv[])
{
	GameState gameState; //create a new gamestate (with all containing sprites and elements)
	SDL_Window *window = NULL; //create a window to display on
	SDL_Renderer *renderer = NULL; //renderer for SDL


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
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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
	//SDL_Delay(10);

	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.player.sheetTexture);
	SDL_DestroyTexture(gameState.enemy);

	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
