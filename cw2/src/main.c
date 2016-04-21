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
void spriteLoad(char *file, SDL_Surface *surface, SDL_Renderer *renderer, GameState *game, char *object)
{
	//load sprite for enemy
	surface = IMG_Load(file);
	if(surface == NULL)
	{
		printf("Cannot find %s\n", file);
		SDL_Quit();
		exit(1);
	}

	//load texture for renderer
	if(strcmp(object,"mario") == 0)
	{
		game->mario = SDL_CreateTextureFromSurface(renderer, surface);
	}
	if(strcmp(object, "enemy") == 0)
	{
		game->enemy = SDL_CreateTextureFromSurface(renderer, surface);
	}
	//free the surface as its no longer necessary
	SDL_FreeSurface(surface);

}


int main(int argc, char* argv[])
{
	GameState gameState; //create a new gamestate (with all containing sprites and elements)
	SDL_Window *window = NULL; //create a window to display on
	SDL_Renderer *renderer = NULL; //renderer for SDL
	SDL_Surface *enemySurface = NULL; //pointer to load enemy texture
	SDL_Surface *playerSurface = NULL;

	//call function to launch SDL
	initialiseSDL();

	//set initial co-ordinates for player
	gameState.player.x = 350;
	gameState.player.y = 250;


	//create an application window
	window = SDL_CreateWindow("sc15j3h - COMP1921 Project", //name of window
							   SDL_WINDOWPOS_UNDEFINED,		//x position
							   SDL_WINDOWPOS_UNDEFINED,		//y position
							   SCREEN_WIDTH,				//width of window
							   SCREEN_HEIGHT,				//height of window
							   0);							//flags

	//create renderer with vsync to prevent screen tearing
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);


	spriteLoad("gfx/megaman.png", playerSurface, renderer, &gameState, "mario");
//	playerSurface = IMG_Load("gfx/megaman.png");
//		if(playerSurface == NULL)
//		{
//			printf("Cannot find megaman.png!\n");
//			SDL_Quit();
//			return 1;
//		}
//
//		//load texture for renderer
//		gameState.mario = SDL_CreateTextureFromSurface(renderer, playerSurface);
//		//free the surface as its no longer necessary
//		SDL_FreeSurface(playerSurface);

spriteLoad("gfx/oct.png", enemySurface, renderer, &gameState, "enemy");
//	//load sprite for enemy
//	enemySurface = IMG_Load("gfx/megaman.png");
//	if(enemySurface == NULL)
//	{
//		printf("Cannot find megaman.png!\n");
//		SDL_Quit();
//		return 1;
//	}
//
//	//load texture for renderer
//	gameState.enemy = SDL_CreateTextureFromSurface(renderer, enemySurface);
//	//free the surface as its no longer necessary
//	SDL_FreeSurface(enemySurface);

	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

		if(processEvents(window, &gameState) == 1)
		{
			done = 1;
		}
		doRender(renderer, &gameState);
	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.enemy);

	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
