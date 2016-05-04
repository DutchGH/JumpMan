/*
 * quit.c
 *
 *  Created on: 2 May 2016
 *      Author: jake
 */
#include "defs.h"
//clean up textures
void exitSDL (GameState *game, SDL_Renderer *renderer, SDL_Window *window)
{
	//DESTROY ANY TEXTURE AND FREE ALL ENTITES
	SDL_DestroyTexture(game->player.sheetTexture);
	SDL_DestroyTexture(game->player.deathSheet);
	SDL_DestroyTexture(game->enemy);
	SDL_DestroyTexture(game->brick);
	SDL_DestroyTexture(game->teleporter);

	//FREE FONTS
	if(game->label != NULL)
	{
		SDL_DestroyTexture(game->label);
	}
	TTF_CloseFont(game->font);

	//FREE SOUNDS
	Mix_FreeChunk(game->bgMusic);
	Mix_FreeChunk(game->dieSound);
	Mix_FreeChunk(game->jumpSound);
	Mix_FreeChunk(game->victorySound);



	//destroy SDL elements to free up memory once done.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;

	//clean up program
	TTF_Quit();
	SDL_Quit();

}

