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
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "init.h"
#include "input.h"
#include "graphics.h"

extern SDL_Surface *requiem;

int main(int argc, char* argv[])
{
	int go = 1;

	//Start SDL

	init("Promethian Knights - Development Copy");

	//cleanup when application exits

	atexit(cleanup);
	requiem = loadImage("gfx/requiem.jpg");

	while (go == 1)
	{
		getInput();
		updateScreen();

		/* Sleep briefly to stop sucking up all the CPU time */

		SDL_Delay(16);
	}


	exit(0);
}
