/*
 * structs.h
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_MAP_X 400
#define MAX_MAP_Y 300
#define MAX_TILES 10
#define TILE_SIZE 32
#define SCROLL_SPEED 8

typedef struct movement
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool jumping;
	bool falling;
}Movement;

typedef struct player
{
	Movement playerMovement;
	float x, y; //co-ordinates of player
	float dy; //used for physics
	int currentSprite, walking, facingLeft, visible;
	short life; //lives of player
	char *name; //name of player
	int onLedge;
	int jumpCount;

	SDL_Texture *sheetTexture;
}Player;

typedef struct enemy
{
	int x,y; //co-ordinates of enemy
}Enemy;


typedef struct map
{
	char *fileName;
	int startX, startY;
	int maxX, maxY;
	int tile[MAX_MAP_Y][MAX_MAP_X];
}Map;

//loads all players and sprites
typedef struct gameState
{
	Map map;
	SDL_Renderer *renderer;

	//player
	Player player;


	//enemy type one - currently a placeholder megaman sprite
	Enemy megaman[10];
	Enemy plog [50]; //enemy type 1
	Enemy sprog[50]; //enemy type 2

	//objects for map creation
	SDL_Texture *player1;
	SDL_Surface *brickImages[MAX_TILES];
	SDL_Texture *brick;
	SDL_Texture *enemy; //texture for enemy
}GameState;

#endif /* STRUCTS_H_ */
