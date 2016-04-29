/*
 * render.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void doRender(SDL_Renderer *renderer, GameState *game)
{
	SDL_SetRenderDrawColor(renderer, 155,155,155,255);
	//clear screen to grey
	SDL_RenderClear(renderer);
	
	//render the tiles of the map
    drawMap(game);
	

	SDL_Rect srcRect = { 60*game->player.currentSprite, 0, 60, 99 };
	SDL_Rect rect = { game->player.x, game->player.y, 30, 50 };
	SDL_RenderCopyEx(renderer, game->player.sheetTexture, &srcRect, &rect, 0, NULL, game->player.facingLeft);


	//~ //create sprite for enemy
	//~ SDL_Rect enemyRect = {50,50,106,120};
	//~ SDL_RenderCopy(renderer, game->enemy, NULL, &enemyRect);

	//render everything on the screen
	SDL_RenderPresent(renderer);
}
