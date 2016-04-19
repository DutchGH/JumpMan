/*
 * structs.h
 *
 *  Created on: 19 Apr 2016
 *      Author: jake
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct Game
{
	SDL_Surface *screen;
}Game;

typedef struct Sprites
{
	SDL_Surface *image;
}Sprites;

typedef struct Control
{
	int up,down,left,right;
}Control;

#endif /* STRUCTS_H_ */
