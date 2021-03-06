/*
 * gameOver.c
 *
 *  Created on: 1 May 2016
 *      Author: jake
 */
#include "defs.h"
void initGameOver(GameState *game)
{
	SDL_Color white = {255,255,255,255};

	//generate white text and create a texture from it
	SDL_Surface *temp = TTF_RenderText_Blended(game->font, "GAME OVER!", white);
	game->labelW = temp->w;
	game->labelH = temp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, temp);
	SDL_FreeSurface(temp);
}

void drawGameOver(GameState *game)
{
	//generate a red background
	SDL_SetRenderDrawColor(game->renderer, 255, 0, 0 ,255);
	SDL_RenderClear(game->renderer);

	//place newly generated text texture from init
	SDL_SetRenderDrawColor(game->renderer, 255,0,0,255);
	SDL_Rect textRect = {400-game->labelW/2, 300-game->labelH/2, game->labelW, game->labelH};
	SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);

}

void shutDownGameOver(GameState *game)
{
	//free the label surface for later use.
	SDL_DestroyTexture(game->label);
	game->label = NULL;
}

