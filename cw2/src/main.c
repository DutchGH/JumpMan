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
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "structs.h"
#include "events.h"
#include "render.h"
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

//function to call and load sprite
void spriteLoad(char *file, SDL_Surface *surface, SDL_Renderer *renderer, SDL_Texture **object)
{
	//load sprite for enemy
	surface = IMG_Load(file);
	if(surface == NULL)
	{
		printf("Cannot find %s\n", file);
		SDL_Quit();
		exit(1);
	}

	//load texture onto sprite
	(*object) = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

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
	SDL_Surface *enemySurface = NULL; //pointer to load enemy texture


	//call function to launch SDL
	initialiseSDL();

	//set initial co-ordinates for player
	gameState.player.x = 400;
	gameState.player.y = 300;
	gameState.player.currentSprite = 4;
	gameState.player.facingLeft = 1;
	gameState.player.jumping = 0;




	//create an application window
	window = SDL_CreateWindow("sc15j3h - COMP1921 Project", //name of window
							   SDL_WINDOWPOS_UNDEFINED,		//x position
							   SDL_WINDOWPOS_UNDEFINED,		//y position
							   SCREEN_WIDTH,				//width of window
							   SCREEN_HEIGHT,				//height of window
							   0);							//flags

	//create renderer with vsync to prevent screen tearing
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	//load sprites and animated frames.
//	spriteLoad("gfx/megaman.png", playerSurface, renderer, &(gameState.player[0]));
//	spriteLoad("gfx/megaman.png", playerSurface, renderer, &(gameState.player[1]));
//	spriteLoad("gfx/megaman.png", playerSurface, renderer, &(gameState.player[2]));
//	spriteLoad("gfx/megaman.png", playerSurface, renderer, &(gameState.player[3]));
	spriteLoad("gfx/oct.png", enemySurface, renderer, &(gameState.enemy));

	SDL_Surface *sheet = IMG_Load("gfx/sheet.png");
	if (sheet == NULL)
	{
		printf("failed to load sheet for sprite\n");
	}
	gameState.player.sheetTexture = SDL_CreateTextureFromSurface(renderer, sheet);
	SDL_FreeSurface(sheet);
	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

		if(processEvents(window, &gameState) == 1)
		{
			done = 1;
		}
		updateLogic(&gameState);
		doRender(renderer, &gameState);
		//SDL_Delay(10);
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
