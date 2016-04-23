/*
 * render.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "structs.h"
#include "events.h"
#include "render.h"
//draw a blue background with a white square in the centre


void doRender(SDL_Renderer *renderer, GameState *game)
{
	SDL_SetRenderDrawColor(renderer, 192,192,192,255);
	//clear screen to blue
	SDL_RenderClear(renderer);

	//set drawing colour to white
	//SDL_SetRenderDrawColor(renderer,255,255,255,255);
	//create a rectangle in the centre with defined co-ordinates
	SDL_Rect srcRect = { 60*game->player.currentSprite, 0, 60, 99 };
	SDL_Rect rect = { game->player.x, game->player.y, 60, 99 };
	SDL_RenderCopyEx(renderer, game->player.sheetTexture, &srcRect, &rect, 0, NULL, game->player.facingLeft);


	//create sprite for enemy
	SDL_Rect enemyRect = {50,50,106,120};
	SDL_RenderCopy(renderer, game->enemy, NULL, &enemyRect);

	//render everything on the screen
	SDL_RenderPresent(renderer);
}
