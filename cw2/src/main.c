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




int main(int argc, char* argv[])
{
	GameState gameState;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *enemySurface = NULL;
	//initialise SDL
	SDL_Init(SDL_INIT_VIDEO);


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
	enemySurface = IMG_Load("gfx/megaman.png");
	if(enemySurface == NULL)
	{
		printf("Cannot find megaman.png!\n");
		SDL_Quit();
		return 1;
	}

	gameState.enemy = SDL_CreateTextureFromSurface(renderer, enemySurface);
	SDL_FreeSurface(enemySurface);
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

	SDL_DestroyTexture(gameState.enemy);
	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
