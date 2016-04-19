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
#include "SDL/SDL_mixer.h"
#include "defs.h"
#include "structs.h"


extern Sprites sprite[MAX_SPRITES];
extern Game game;
extern SDL_Surface *screen;
SDL_Surface *requiem;



SDL_Surface *loadImage(char *name)
{
	//load image via SDL_Image
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;

	if(temp == NULL)
	{
		printf("Failed to load image: %s\n", name);
	}

	//transparent background
	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, 0, 0, 0));

	//convert image to screens native format
	image = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	if(image == NULL)
	{
		printf("Failed To Convert Image: %s\n",name);
		return NULL;
	}

	//return the processed image.
	return image;
}

void drawImage(SDL_Surface *image, int x, int y)
{
	SDL_Rect dest;

	//set rectangle to source of the source img
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;

	//blit image onto screen at specified co-ordinates
	SDL_BlitSurface(image, NULL, screen, &dest);
}

void loadSprite(int index, char *name)
{
	//load image into sprite bank
	if (index >=MAX_SPRITES || index <0)
		{
			printf("Invalid index for sprite!\n");
			exit(1);
		}

	sprite[index].image = loadImage(name);
	if(sprite[index].image == NULL)
	{
		exit(1);
	}
}

void *getSprites(int index)
{
	if (index >= MAX_SPRITES||index <0)
	{
		printf("invalid index for sprite!\n");
		exit(1);
	}

	return sprite[index].image;
}

void freeSprites()
{
	int i;
	//loop through sprite bank and clear images
	for(i=0;i<MAX_SPRITES;i++)
	{
		if(sprite[i].image != NULL)
		{
			SDL_FreeSurface(sprite[i].image);
		}
	}
}

void loadAllSprites()
{
	//load Megaman sprite FOR TESTING PURPOSES ONLY
	//TODO: Make new sprite for game.
	loadSprite(PLAYER_SPRITE, "gfx/megaman.png");
}

void updateScreen()
{
	//draw image from top left of screen.
	SDL_FillRect(screen, NULL, 0);
	drawImage(requiem, 0,0);
	SDL_Flip(screen);
}
