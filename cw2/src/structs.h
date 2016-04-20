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
	int x, y; //co-ordinates of player
	short life; //lives of player
	char *name; //name of player
}Player;

typedef struct enemy
{
	int x,y; //co-ordinates of enemy
}Enemy;

//loads all players and sprites
typedef struct gameState
{
	//player
	Player player;

	//enemy type one - currently a placeholder megaman sprite
	Enemy megaman[10];
	Enemy plog [50]; //enemy type 1
	Enemy sprog[50]; //enemy type 2

	SDL_Texture *mario; //texture for player - Animations TBI
	SDL_Texture *enemy; //texture for enemy
	SDL_Renderer *renderer;
}GameState;

#endif /* STRUCTS_H_ */
