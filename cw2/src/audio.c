/*
 * audio.c
 *
 *  Created on: 19 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

Mix_Chunk *loadSound(char *name)
{
	Mix_Chunk *sfx = Mix_LoadWAV(name);

	if(sfx == NULL)
	{
		printf("Failed to load sound %s\n", name);
	}

	return sfx;
}

void playSound(Mix_Chunk *sfx)
{
	Mix_PlayChannel(-1,sfx,0);
}

