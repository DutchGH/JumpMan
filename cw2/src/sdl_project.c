/*
 ============================================================================
 Name        : sdl_project.c
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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
//window to render to
SDL_Window* gWindow = NULL;
//surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//image to load on the screen
SDL_Surface* gRequiem = NULL;

//Starts SDL & creates a window
bool init()
{
	//flag for initialisation
	bool success = true;

	//initialise SDL
	if(SDL_Init(SDL_INIT_VIDEO) <0)
	{
		printf("SDL could not initialise - SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Promethian Knights", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if(gWindow == NULL)
		{
			printf( "Window could not be created -  SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia()
{
	//success flag
	bool success = true;

	//load splash image
	gRequiem = IMG_Load("gfx/requiem.jpg");
	if(gRequiem == NULL)
	{
		printf("unable to load image %s - SDL Error: %s\n", "gfx/requiem.jpg",SDL_GetError());
		success = false;
	}
	return success;
}

void quit()
{
	//Deallocate surface
	SDL_FreeSurface(gRequiem);
	gRequiem = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	//Start SDL & create window
	if(!init())
	{
		printf("Failed To Initialise! \n");
	}
	else
	{
		//load Images
		if(!loadMedia())
		{
			printf("Failed to load image!\n");
		}
		else
		{
			bool go = true;
			SDL_Event e;
			while(go)
			{
				while(SDL_PollEvent(&e))
				{
					if(e.type == SDL_QUIT)
					{
						go = false;
					}
				}
				SDL_BlitSurface(gRequiem, NULL, gScreenSurface, NULL);
				SDL_UpdateWindowSurface(gWindow);
			}

		}

	}
	quit();
	exit(0);
}
