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
	//call function to launch SDL
	initialiseSDL();

	SDL_Window *window = NULL; //create a window to display on
	SDL_Renderer *renderer = NULL; //renderer for SDL

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
	GameState gameState; //create a new gamestate (with all containing sprites and elements)
	gameState.renderer = renderer;
	gameState.window = window;
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

	exitSDL(&gameState, renderer, window);
	return(0);
}
