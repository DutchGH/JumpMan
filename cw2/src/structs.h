/*
 * structs.h
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct player
{
	int x, y;
	short life;
	char *name;
}Player;

typedef struct enemy
{
	int x,y;
}Enemy;


typedef struct gameState
{
	//player
	Player player;

	//enemy type one - currently a placeholder megaman sprite
	Enemy megaman[10];
	SDL_Texture *enemy;
	SDL_Renderer *renderer;
}GameState;

#endif /* STRUCTS_H_ */
