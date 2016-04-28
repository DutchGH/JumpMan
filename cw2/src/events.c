/*
 * events.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
		{//event type switch|
		case SDL_WINDOWEVENT_CLOSE:
			if(window)
			{//if(window)
				SDL_DestroyWindow(window);
				window = NULL;
			}//if(window)
			break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			case SDLK_UP:
			    if((game->player.jumpCount < 2 || game->player.onLedge) && event.key.repeat == 0)
				{
				  game->player.dy = -8;
				  game->player.onLedge = 0;
				  game->player.jumpCount++;
				}
				break;
			}
			break;
		case SDL_QUIT:
			done = 1;
			break;
		}//event type switch
	}//Wait for event...

	  const Uint8 *state = SDL_GetKeyboardState(NULL);
	  if(state[SDL_SCANCODE_UP])
	  {
	    game->player.dy -= 0.2f;
	  }

	  //Walking
	  if(state[SDL_SCANCODE_LEFT])
	  {
	    game->player.dx -= 0.5;
	    if(game->player.dx < -6)
	    {
	      game->player.dx = -6;
	    }
	    game->player.facingLeft = 1;
	    game->player.slowingDown = 0;
		if (game->globalTime%10 == 0)
			{
				//shift sprite with gametime
				game->player.currentSprite++;
				game->player.currentSprite %=8;
			}
	  }
	  else if(state[SDL_SCANCODE_RIGHT])
	  {
	    game->player.dx += 0.5;
	    if(game->player.dx > 6)
	    {
	      game->player.dx = 6;
	    }
	    game->player.facingLeft = 0;
	    game->player.slowingDown = 0;
		if (game->globalTime%10 == 0)
			{
				//shift sprite with gametime
				game->player.currentSprite++;
				game->player.currentSprite %=8;
			}
	  }


	//if player is stationary
	else
	{
		//set defult sprite and stop his movement 
		game->player.walking = 0;
		game->player.dx *= 0.8f;
		game->player.currentSprite = 9;
		game->player.slowingDown = 1;
		if(fabsf(game->player.dx) < 0.1f)
		{
		  game->player.dx = 0;
		}
	}

	return done;
}
