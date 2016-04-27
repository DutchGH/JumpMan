/*
 * render.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
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
//draw a blue background with a white square in the centre


void doRender(SDL_Renderer *renderer, GameState *game)
{
	SDL_SetRenderDrawColor(renderer, 155,155,155,255);
	//clear screen to grey
	SDL_RenderClear(renderer);
	
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
