/*
 * draw.c
 *
 *  Created on: 19 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "structs.h"
#include "defs.h"

extern void drawPlayer(void);
extern void drawEntities(void);
Game game;


void draw()
{
	SDL_FillRect(game.screen, NULL, 0);

	drawPlayer();
	SDL_Flip(game.screen);

	SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}

	if(frameLimit >ticks +16)
	{
		SDL_Delay(16);
	}

	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}
