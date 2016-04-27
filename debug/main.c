/*
 ============================================================================
 Name        : main.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Main file for execution of program for SDL
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "structs.h"
#include "events.h"
#include "render.h"
#include "map.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define GRAVITY_SPEED 0.8
#define BLANK_TILE 0
#define MAX_FALL_SPEED 20

#define PLAYER_SPEED 4
int globalTime = 0;

void initialiseSDL()
{
	//initialise SDL
	SDL_Init(SDL_INIT_VIDEO);

	//error handling for launching SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr,"SDL_Init failed %s", SDL_GetError());
	}
}

//~ void initPlayer(GameState *game)
//~ {
	//~ game->player.x = game->player.y = 0;
	//~ game->player.dx = game->player.dy = 300;
	
	//~ game->player.w = 30;
	//~ game->player.h = 50;
	
	//~ game->player.thinkTime = 0;
//~ }



void loadGame(GameState *game)
{
    loadMap(game);

	game->enemy = IMG_LoadTexture(game->renderer, "gfx/oct.png");

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "spritesheetmod.png");

	game->brick = IMG_LoadTexture(game->renderer, "gfx/greybrick.png");

	//setting inital parameters for the player
	//initPlayer(game);
    game->player.x = 0;
	//game->player.y = 300;
    //~ game->player.w = 30;
    //~ game->player.h  = 50;
	//game->player.onLedge = 1;
	game->player.facingLeft = 1;
    game->player.dx = 0;

	//prevents automatic movement bug
	game->player.playerMovement.left = 0;
	game->player.playerMovement.right = 0;
	//game->player.playerMovement.jump = false;
	game->player.jumpCount = 0;
	
	//load the map

	

}

void updateLogic(GameState *game)
{
  game->player.y += game->player.dy;
  game->player.dy += 0.5;
  if(game->player.y > 300)
  {
    game->player.y = 350;
    game->player.dy = 0;
	game->player.jumpCount = 0; //do this only when /landing/ not when colliding.
    game->player.onLedge = 0;
  }
  else {
  }
  printf("Player pos: %f\n",game->player.y);
  globalTime++;
}

	//~ if (game->player.playerMovement.jump == true)
		//~ {
			//~ if (game->player.onLedge == 1)
			//~ {
				//~ game->player.dy = -11;
			//~ }
			
			//~ game->player.playerMovement.jump = false;
		//~ }

//~ void checkToMap(GameState *game)
//~ {
    
	//~ int i, x1, x2, y1, y2;
	
	//~ /* Remove the user from the ground */
	
	//~ game->player.onLedge = false;
	
	//~ /* Test the horizontal movement first */
	
	//~ i = game->player.h > TILE_SIZE ? TILE_SIZE : game->player.h;
	
	//~ for (;;)
	//~ {
		//~ x1 = (game->player.x + game->player.dx) / 32;
		//~ x2 = (game->player.x + game->player.dx + game->player.w - 1) / TILE_SIZE;
	
		//~ y1 = (game->player.y) / TILE_SIZE;
		//~ y2 = (game->player.y + i - 1) / TILE_SIZE;
		
		//~ if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		//~ {
			//~ if (game->player.dx > 0)
			//~ {
				//~ /* Trying to move right */
		
				//~ if ((mapArray[y1][x2] != BLANK_TILE) || (mapArray[y2][x2] != BLANK_TILE))
				//~ {
					//~ /* Place the player as close to the solid tile as possible */
		
					//~ game->player.x = x2 * TILE_SIZE;
					
					//~ game->player.x -= game->player.w + 1;
		
					//~ game->player.dx = 0;
				//~ }
			//~ }
		
			//~ else if (game->player.dx < 0)
			//~ {
				//~ /* Trying to move left */
		
				//~ if ((mapArray[y1][x1] != BLANK_TILE) || (mapArray[y2][x1] != 0))
				//~ {
					//~ /* Place the player as close to the solid tile as possible */
					
					//~ game->player.x = (x1 + 1) * 32;
		
					//~ game->player.dx = 0;
				//~ }
			//~ }
		//~ }
		
		//~ /* Exit this loop if we have tested all of the body */
		
		//~ if (i == game->player.h)
		//~ {
			//~ break;
		//~ }
		
		//~ /* Test the next block */
		
		//~ i += TILE_SIZE;
		
		//~ if (i > game->player.h)
		//~ {
			//~ i = game->player.h;
		//~ }
	//~ }

	//~ /* Now test the vertical movement */
	
	//~ i = game->player.w > 32 ? 32 : game->player.w;
	
	//~ for (;;)
	//~ {
		//~ x1 = (game->player.x) / TILE_SIZE;
		//~ x2 = (game->player.x + i) / TILE_SIZE;
	
		//~ y1 = (game->player.y + game->player.dy) / TILE_SIZE;
		//~ y2 = (game->player.y + game->player.dy + game->player.h) / TILE_SIZE;
		
		//~ if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
		//~ {
			//~ if (game->player.dy > 0)
			//~ {
				//~ /* Trying to move down */
				
				//~ if ((mapArray[y2][x1] != BLANK_TILE) || (mapArray[y2][x2] != BLANK_TILE))
				//~ {
					//~ /* Place the player as close to the solid tile as possible */
					
					//~ game->player.y = y2 * TILE_SIZE;
					//~ game->player.y -= game->player.h;
		
					//~ game->player.dy = 0;
					
					//~ game->player.onLedge = 1;
				//~ }
			//~ }
		
			//~ else if (game->player.dy < 0)
			//~ {
				//~ /* Trying to move up */
		
				//~ if ((mapArray[y1][x1] != BLANK_TILE) || (mapArray[y1][x2] != BLANK_TILE))
				//~ {
					//~ /* Place the player as close to the solid tile as possible */
		
					//~ game->player.y = (y1 + 1) * TILE_SIZE;
		
					//~ game->player.dy = 0;
				//~ }
			//~ }
		//~ }
		
		//~ if (i == game->player.w)
		//~ {
			//~ break;
		//~ }
		
		//~ i += TILE_SIZE;
		
		//~ if (i > game->player.w)
		//~ {
			//~ i = game->player.w;
		//~ }
	//~ }

	//~ /* Now apply the movement */

	//~ game->player.x += game->player.dx;
	//~ game->player.y += game->player.dy;
	
	//~ if (game->player.x < 0)
	//~ {
		//~ game->player.x = 0;
	//~ }
	
	//~ else if (game->player.x + game->player.w >= game->map.maxX)
	//~ {
		//~ game->player.x = game->map.maxX - game->player.w - 1;
	//~ }
	
	//~ if (game->player.y > game->map.maxY)
	//~ {
		//~ game->player.thinkTime = 60;
	//~ }
//~ }


//~ void centerEntityOnMap(GameState *game)
//~ {
	//~ game->map.startX = game->player.x - (SCREEN_WIDTH / 2);
	
	//~ if (game->map.startX < 0)
	//~ {
		//~ game->map.startX = 0;
	//~ }
	
	//~ else if (game->map.startX + SCREEN_WIDTH >= game->map.maxX)
	//~ {
		//~ game->map.startX = game->map.maxX - SCREEN_WIDTH;
	//~ }
	
	//~ game->map.startY = game->player.y - (SCREEN_HEIGHT / 2);
	
	//~ if (game->map.startY < 0)
	//~ {
		//~ game->map.startY = 0;
	//~ }
	
	//~ else if (game->map.startY + SCREEN_HEIGHT >= game->map.maxY)
	//~ {
		//~ game->map.startY = game->map.maxY - SCREEN_HEIGHT;
	//~ }
//~ }



//~ void doPlayer(GameState *game)
//~ {
	//~ if (game->player.thinkTime == 0)
	//~ {
		//~ game->player.dx = 0;
	
		//~ /* Gravity always pulls the player down */
	
		//~ game->player.dy += GRAVITY_SPEED;
		
		//~ if (game->player.dy >= MAX_FALL_SPEED)
		//~ {
			//~ game->player.dy = MAX_FALL_SPEED;
		//~ }
		
		//~ if (game->player.playerMovement.left == true)
		//~ {
			//~ game->player.dx -= PLAYER_SPEED;
		//~ }
		
		//~ else if (game->player.playerMovement.right == true)
		//~ {
			//~ game->player.dx += PLAYER_SPEED;
		//~ }
		
	
		
		//~ checkToMap(game);
		
		//centerEntityOnMap(game);
	//~ }
	
	//~ if (game->player.thinkTime > 0)
	//~ {
		//~ game->player.thinkTime--;
		
		//~ if (game->player.thinkTime == 0)
		//~ {
			//~ initPlayer(game);
		//~ }
	//~ }
	//~ globalTime++;
//~ }


int main(int argc, char* argv[])
{
	GameState gameState; //create a new gamestate (with all containing sprites and elements)
	SDL_Window *window = NULL; //create a window to display on
	SDL_Renderer *renderer = NULL; //renderer for SDL


	//call function to launch SDL
	initialiseSDL();

	//create an application window
	window = SDL_CreateWindow("sc15j3h - COMP1921 Project", //name of window
							   SDL_WINDOWPOS_UNDEFINED,		//x position
							   SDL_WINDOWPOS_UNDEFINED,		//y position
							   SCREEN_WIDTH,				//width of window
							   SCREEN_HEIGHT,				//height of window
							   0);							//flags

	//create renderer with vsync to prevent screen tearing
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//make sure all elements are renered in the same window
	gameState.renderer = renderer;
	loadGame(&gameState);

	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

	done = processEvents(window, &gameState);
    //~ doPlayer(&gameState);
    updateLogic(&gameState);

	doRender(renderer, &gameState);
	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.player.sheetTexture);
	SDL_DestroyTexture(gameState.enemy);

	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
