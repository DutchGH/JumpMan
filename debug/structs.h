/*
 * structs.h
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_MAP_X 40
#define MAX_MAP_Y 30

#define TILE_SIZE 32
#define SCROLL_SPEED 4
typedef struct player
{
	int x, y; //co-ordinates of player
	float dy; //used for physics
	int currentSprite, walking, facingLeft, shooting, visible, jumping;
	short life; //lives of player
	char *name; //name of player

	SDL_Texture *sheetTexture;
}Player;

typedef struct enemy
{
	int x,y; //co-ordinates of enemy
}Enemy;

typedef struct map
{
	int startX, startY;
	int maxX, maxY;
	int tile[MAX_MAP_Y][MAX_MAP_X];
}Map;

//loads all players and sprites
typedef struct gameState
{
	//player
	Player player;

	//enemy type one - currently a placeholder megaman sprite
	Enemy megaman[10];
	Enemy plog [50]; //enemy type 1
	Enemy sprog[50]; //enemy type 2

	//objects for map creation
	SDL_Texture *brickImage;

	SDL_Texture *player1[4]; //texture for player - Animations TBI
	SDL_Texture *enemy; //texture for enemy
	SDL_Renderer *renderer;
}GameState;

#endif /* STRUCTS_H_ */
