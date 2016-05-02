/*
 ============================================================================
 Name        : main.c
 Author      : Jacob Holland
 Version     :
 Copyright   : Your copyright notice
 Description : Main file for execution of program for SDL
 ============================================================================
 */
#include "defs.h"

//TODO: Add enemy sprites - design new sprite
//TODO: Implement SDL_Sound for SFX/Music.

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
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	loadGame(&gameState);

	//flag for event loop for program
	int done = 0;

	//create an event loop for the game
	while(!done)
	{//while(!done)

		done = processEvents(window, &gameState);
		updateLogic(&gameState);
		collisionDetect(&gameState);
		//enemyLogic(&gameState);

		//render display
		doRender(renderer, &gameState);

	}//while(!done)

	//clean up textures
	SDL_DestroyTexture(gameState.player.sheetTexture);
	SDL_DestroyTexture(gameState.enemy);
	SDL_DestroyTexture(gameState.brick);
	if(gameState.label != NULL)
	{
		SDL_DestroyTexture(gameState.label);
	}
	TTF_CloseFont(gameState.font);
	Mix_FreeChunk(gameState.bgMusic);
	Mix_FreeChunk(gameState.dieSound);
	Mix_FreeChunk(gameState.jumpSound);
	Mix_FreeChunk(gameState.victorySound);



	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//clean up program
	TTF_Quit();
	SDL_Quit();
	return(0);
}
