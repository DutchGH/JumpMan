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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

SDL_Surface *screen;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void init(char *title)
{
	//Initialise SDL Video
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
	{
		printf("Could not initialise SDL: %s\n", SDL_GetError());
		exit(1);
	}

	//Open a screen with a resolution of 800x600
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,SDL_HWPALETTE);

	if(screen == NULL)
	{
		printf("Couldn't set screen mode to 640 x 480: %s\n",SDL_GetError());
		exit(1);
	}

	if(Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
	{
		printf("Could not open audio: %s\n", Mix_GetError());
		exit(1);
	}

	//Set the title of the screen
	SDL_WM_SetCaption(title, NULL);
}

void cleanup()
{
	Mix_CloseAudio();
	SDL_Quit(); //exit SDL
}

