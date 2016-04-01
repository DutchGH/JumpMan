/*
 ============================================================================
 Name        : init.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Initialization of SDL window
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"

SDL_Surface *screen;

void init(char *title)
{
	//Initialise SDL Video
	if (SDL_Init(SDL_INIT_VIDEO) <0)
	{
		printf("Could not initialise SDL: %s\n", SDL_GetError());
		exit(1);
	}

	//Open a screen with a resolution of 640x480
	screen = SDL_SetVideoMode(640,480,0,SDL_HWPALETTE);

	if(screen == NULL)
	{
		printf("Couldn't set screen mode to 640 x 480: %s\n",SDL_GetError());
		exit(1);
	}

	//Set the title of the screen
	SDL_WM_SetCaption(title, NULL);
}

void cleanup()
{
	SDL_Quit(); //exit SDL
}

