/*
 * graphics.c
 *
 *  Created on: 10 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

extern SDL_Surface *screen;
SDL_Surface *requiem;

SDL_Surface *loadImage(char *name)
{
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;

	if(temp == NULL)
	{
		printf("Failed to load image: %s\n", name);
	}

	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, 0, 0, 0));

	image = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	if(image == NULL)
	{
		printf("Failed To Convert Image: %s\n",name);
		return NULL;
	}

	return image;
}

void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;

	SDL_BlitSurface(image, NULL, screen, &dest);
}

void updateScreen()
{
	SDL_FillRect(screen, NULL, 0);
	drawImage(requiem, 160,120);
	SDL_Flip(screen);
}
