/*
 * lives.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void initStatusLives(GameState *game)
{
	//string to print
	char lifeString[128] = "";
	sprintf(lifeString, "LIVES LEFT: %d",game->player.lives);

	//set text colour to white
	SDL_Color white = {255,255,255,255};

	SDL_Surface *temp = TTF_RenderText_Blended(game->font, lifeString, white);
	game->labelW = temp->w;
	game->labelH = temp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, temp);
	SDL_FreeSurface(temp);
}

void drawStatusLives(GameState *game)
{
	//draw text on a black background
	SDL_SetRenderDrawColor(game->renderer, 0,0,0,255);
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer, 255,255,255,255);
	SDL_Rect textRect = {400-game->labelW/2, 300-game->labelH/2, game->labelW, game->labelH};
	SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);

}

void shutDownStatusLives(GameState *game)
{
	//free texture
	SDL_DestroyTexture(game->label);
	game->label = NULL;
}
