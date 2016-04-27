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


void loadGame(GameState *game)
{
    loadMap(game);
    game->globalTime = 0;

	game->enemy = IMG_LoadTexture(game->renderer, "gfx/oct.png");

	game->player.sheetTexture = IMG_LoadTexture(game->renderer, "spritesheetmod.png");

	game->brick = IMG_LoadTexture(game->renderer, "gfx/greybrick.png");

	//setting inital parameters for the player
    game->player.x = 320 - 40;
    game->player.y = 240 - 40;
    //game->player.dx = 0;
    game->player.dy = 0;
    game->player.onLedge = 0;
    game->player.slowingDown = 0;

    game->player.facingLeft = 0;
	//prevents automatic movement bug
	game->player.playerMovement.left = 0;
	game->player.playerMovement.right = 0;
	game->player.jumpCount = 0;
	
	//load the map
}

void updateLogic(GameState *game)
{
	game->player.x += game->player.dx;
	game->player.y += game->player.dy;
	if(game->player.onLedge == 1)
	{
		game->player.jumpCount = 0; //do this only when /landing/ not when colliding.

	}
	game->player.dy += 0.5;
	game->globalTime++;

}

void collisionDetect(GameState *game)
{
  //Check for collision with any ledges (brick blocks)
  for(int i = 0; i < 664; i++)
  {
	float bx = game->ledge[i].bx;
	float by = game->ledge[i].by;
    float mw = 30, mh = 50;
    float mx = game->player.x, my = game->player.y;
    float bw = 32, bh = 32;
    //printf("%g %g %g %g\n",bw, by, bw, bw);

    if(mx+mw/2 > bx && mx+mw/2<bx+bw)
    {
      //are we bumping our head?
      if(my < by+bh && my > by && game->player.dy < 0)
      {
        //correct y
        game->player.y = by+bh;
        my = by+bh;

        //bumped our head, stop any jump velocity
        game->player.dy = 0;
        game->player.onLedge = 1;
      }
    }
    if(mx+mw > bx && mx<bx+bw)
    {
      //are we landing on the ledge
      if(my+mh > by && my < by && game->player.dy > 0)
      {
        //correct y
        game->player.y = by-mh;
        my = by-mh;

        //landed on this ledge, stop any jump velocity
        game->player.dy = 0;
        game->player.onLedge = 1;
      }
    }

    if(my+mh > by && my<by+bh)
    {
      //rubbing against right edge
      if(mx < bx+bw && mx+mw > bx+bw && game->player.dx < 0)
      {
        //correct x
        game->player.x = bx+bw;
        mx = bx+bw;

        game->player.dx = 0;
      }
      //rubbing against left edge
      else if(mx+mw > bx && mx < bx && game->player.dx > 0)
      {
        //correct x
        game->player.x = bx-mw;
        mx = bx-mw;

        game->player.dx = 0;
      }
    }
  }
}

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

	//make sure all elements are rendered in the same window
	gameState.renderer = renderer;
	loadGame(&gameState);

	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

		done = processEvents(window, &gameState);
		updateLogic(&gameState);
		collisionDetect(&gameState);

		//render display
		doRender(renderer, &gameState);

	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.player.sheetTexture);
	SDL_DestroyTexture(gameState.enemy);
	SDL_DestroyTexture(gameState.brick);



	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	SDL_Quit();
	return(0);
}
