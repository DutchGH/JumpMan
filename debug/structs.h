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
	//position modifications
	float x, y; //co-ordinates of player
	float dx, dy; //movement velocities

	//motion/sprite generation
	int currentSprite, walking, facingLeft, slowingDown;

	//situation bools
	int lives; //lives of player
	int jumpCount;
	int onLedge, isDead;

	//Textures
	SDL_Texture *sheetTexture; //Alive Texture
	SDL_Texture *deathSheet; //Death Texture
	SDL_Texture *lifeState; //Texture to Load on situation
}Player;

typedef struct enemy
{
	//co-ordinates
	int x,y, baseX, baseY, mode;

	//TODO: Vary for sinF of each sprite
	float phase;
}Enemy;

//parameters for map generation
typedef struct Map
{
	//starting coordinates
	int startX, startY;

	//max coordinates
	int maxX, maxY;
} Map;

//parameters for the ledge
typedef struct Ledge
{
	//position and measurements
	int x, y, w, h;

	//block positions for collision detection
	float by, bx;
} Ledge;

//gamestate struct - used to load all the sprites and textures.
typedef struct gameState
{
	//Renderer for gameState functions
	SDL_Renderer *renderer;
	SDL_Window *window;

	//Sprites
	Player player; //creates a player
	Enemy plog[MAX_ENEMY]; //enemy type 1


	//timings for game and death
	int globalTime, deathTime;
	//dictates what screen should be shown
	int	gameStatus;

	//Map contents
	Map map; //used for map
	Ledge ledge [MAX_TILES]; //ledges
	int tileCount; //used to count tiles for array
	float scrollX; //used to scroll the map


	//Textures
	SDL_Texture *bg;
	SDL_Texture *brick;
	SDL_Texture *enemy; //texture for enemy

	//font generation - SDL_TTF required
	TTF_Font *font;
	SDL_Texture *label;
	int labelW, labelH;

	//SFX
	int musicChannel;
	Mix_Chunk *bgMusic, *jumpSound, *dieSound, *victorySound,*gameOver;

}GameState;

#endif /* STRUCTS_H_ */
