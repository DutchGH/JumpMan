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
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//draw a blue background with a white square in the centre
void doRender(SDL_Renderer *renderer, Player *player)
{
	SDL_SetRenderDrawColor(renderer, 0,0,255,255);
	//clear screen to blue
	SDL_RenderClear(renderer);
	//set drawing colour to white
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	//create a rectangle in the centre with defined co-ordinates
	SDL_Rect rectangle = {player->x,player->y,200,200};
	SDL_RenderFillRect(renderer, &rectangle);

	//render everything on the screen
	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	//initialise SDL
	SDL_Init(SDL_INIT_VIDEO);

	Player player;
		player.x = 300;
		player.y = 200;


	//create an application window
	window = SDL_CreateWindow("sc15j3h - COMP1921 Project",
							   SDL_WINDOWPOS_UNDEFINED,
							   SDL_WINDOWPOS_UNDEFINED,
							   SCREEN_WIDTH,
							   SCREEN_HEIGHT,
							   0);

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

		if(processEvents(window, &player) == 1)
		{
			done = 1;
		}
		doRender(renderer, &player);
		SDL_Delay(10);

	}//while(!done)

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
