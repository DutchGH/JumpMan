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

//parameters for map generation
typedef struct Map
{
	int startX, startY; //starting coordinates
	int maxX, maxY; //max coordinates
} Map;

//parameters for the ledge
typedef struct Ledge
{
  int x, y, w, h;
} Ledge;

//gamestate struct - used to load all the sprites and textures.
typedef struct gameState
{
	SDL_Renderer *renderer;
	Map map;
	//player
	Player player;

	
	Enemy plog [50]; //enemy type 1
	Enemy sprog[50]; //enemy type 2
	Ledge ledge [3000]; //TODO: Make Dynamic for efficient memory use.

	//objects for map creation
	SDL_Texture *brick;
	SDL_Texture *enemy; //texture for enemy
}GameState;

#endif /* STRUCTS_H_ */
