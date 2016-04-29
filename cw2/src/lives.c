/*
 * lives.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void initStatusLives(GameState *game)
{
	SDL_Color white = {255,255,255,255};

	SDL_Surface *temp = TTF_RenderText_Blended(game->font, "Lives x 3", white);
	game->labelW = temp->w;
	game->labelH = temp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, temp);
	SDL_FreeSurface(temp);
}

void drawStatusLives(GameState *game)
{
	SDL_SetRenderDrawColor(game->renderer, 0,0,0,255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer, 255,255,255,255);
	SDL_Rect textRect = {300,240, game->labelW, game->labelH};
	SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);

}

void shutDownStatusLives(GameState *game)
{
	SDL_DestroyTexture(game->label);
	game->label = NULL;
}
