/*
 * events.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "structs.h"
int processEvents(SDL_Window *window, GameState *game)
{
	int done = 0;
	SDL_Event event;
	//check for events
	while(SDL_PollEvent(&event))
	{//Wait for Event...
		switch(event.type)
		{//event type switch
		case SDL_WINDOWEVENT_CLOSE:
			if(window)
			{//if(window)
				SDL_DestroyWindow(window);
				window = NULL;
			}//if(window
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = 1;
				break;
			}
			break;

		case SDL_QUIT:
			done = 1;
			break;
		}//event type switch
	}//Wait for event...

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if(state[SDL_SCANCODE_LEFT])
	{
		game->player.x -= 10;
	}
	if(state[SDL_SCANCODE_RIGHT])
	{
		game->player.x += 10;
	}
	if(state[SDL_SCANCODE_UP])
	{
		game->player.y -=10;
	}
	if(state[SDL_SCANCODE_DOWN])
	{
		game->player.y +=10;
	}

	return done;
}
