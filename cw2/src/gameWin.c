/*
 * gameWin.c
 *
 *  Created on: 1 May 2016
 *      Author: jake
 */
#include "defs.h"
void initVictory(GameState *game)
{
	SDL_Color white = {255,255,255,255};

	SDL_Surface *temp = TTF_RenderText_Blended(game->font, "CONGRATULATIONS!", white);
	game->labelW = temp->w;
	game->labelH = temp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, temp);
	SDL_FreeSurface(temp);
}

void drawVictory(GameState *game)
{
	SDL_SetRenderDrawColor(game->renderer, 255, 0, 0 ,255);
	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(game->renderer, 255,0,0,255);
	SDL_Rect textRect = {400-game->labelW/2, 300-game->labelH/2, game->labelW, game->labelH};
	SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);

}

void shutDownVictory(GameState *game)
{
	SDL_DestroyTexture(game->label);
	game->label = NULL;
}
