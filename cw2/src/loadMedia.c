/*
 * load_media.c
 *
 *  Created on: 18 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Surface* gRequiem;

bool loadMedia()
{
	//success flag
	bool success = true;

	//load splash image
	gRequiem = IMG_Load("gfx/requiem.jpg");
	if(gRequiem == NULL)
	{
		printf("unable to load image %s - SDL Error: %s\n", "gfx/requiem.jpg",SDL_GetError());
		success = false;
	}
	return success;
}


