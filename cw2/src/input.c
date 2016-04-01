/*
 ============================================================================
 Name        : sdl_project.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Manage Keyboard/IO inputs for SDL
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"

void getInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//closing the window or pressing ESC will cause the application to close

			case SDL_QUIT:
				exit(0);
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
					break;

					default:
					break;
				}
			break;
		}
	}
}

