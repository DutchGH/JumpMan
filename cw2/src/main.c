/*
 ============================================================================
 Name        : sdl_project.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Main file for execution of program for SDL
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "defs.h"
#include "structs.h"
#include "init.h"
#include "input.h"
#include "graphics.h"
#include "audio.h"

extern SDL_Surface *requiem;
Mix_Chunk *blurp;

int main(int argc, char* argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go = 1;

	//Start SDL

	init("Promethian Knights");

	//cleanup when application exits

	atexit(cleanup);
	requiem = loadImage("gfx/requiem.jpg");
	if(requiem == NULL)
	{
		exit(0);
	}

	blurp = loadSound("audio/blurp.wav");

	if(blurp == NULL)
	{
		exit(0);
	}

	while (go == 1)
	{
		getInput();
		updateScreen();

		/* Sleep briefly to stop sucking up all the CPU time */

		SDL_Delay(16);
	}


	exit(0);
}
