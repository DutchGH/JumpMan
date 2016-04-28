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
				//if player is not yet already double-jumping:
//				if(game->player.jumpCount < 2 && event.key.repeat == 0)
//				{
//					//
//					//printf("Jumping\n");
//					game->player.dy = -10;
//					game->player.playerMovement.jump = true;
//					game->player.jumpCount++;
//				}
			    if(game->player.jumpCount < 2 || game->player.onLedge && event.key.repeat == 0)
			            {
			              game->player.dy = -8;
			              game->player.onLedge = 0;
			              game->player.jumpCount++;
			            }
		
				break;
			case SDLK_LEFT:
				game->player.playerMovement.left = true;
				break;
			case SDLK_RIGHT:
				game->player.playerMovement.right = true;
				break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
			case SDLK_LEFT:
				game->player.playerMovement.left = false;
				break;
			case SDLK_RIGHT:
				game->player.playerMovement.right = false;
				break;
			}
			break;
		case SDL_QUIT:
			done = 1;
			break;
		}//event type switch
	}//Wait for event...


	// MOVEMENT CONTROLS
	if(game->player.playerMovement.left) //if player is holding left
	{
		//move him left and flip the sprite
		game->player.x -= 5; //move player left
		if(game->player.dx == 6)
		{
			game->player.dx = 6;
		}

		game->player.walking = 1;
		game->player.facingLeft = 1;
		game->player.slowingDown = 0;


		if (game->globalTime%10 == 0)
		{
			//increment the sprite sheet 
			game->player.currentSprite++;
			game->player.currentSprite %=8;
		}
	}
	else if(game->player.playerMovement.right)
	{
		//move player right
		game->player.x += 5;
		if(game->player.dx > 6)
		{
			game->player.dx = 6;
		}
		game->player.walking = 1;
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
		game->player.currentSprite = 9;
		game->player.slowingDown = 1;
		    if(fabsf(game->player.dx) < 0.1f)
		    {
		      game->player.dx = 0;
		    }
	}







	return done;
}
