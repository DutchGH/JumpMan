/*
 * render.c
 *
 *  Created on: 20 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void doRender(SDL_Renderer *renderer, GameState *game)
{
	//READY LABELS DEPENDING ON GAMESTATE
	if(game->gameStatus == GAME_STATE_LIVES)
	{
		drawStatusLives(game);
	}

	else if (game->gameStatus == GAME_STATE_GAMEOVER)
	{
		drawGameOver(game);
	}

	else if (game->gameStatus == GAME_STATE_VICTORY)
	{
		drawVictory(game);
	}

	//IF IN THE GAME - RENDER THE ENTITES
	else if (game->gameStatus == GAME_STATE_GAME)
	{
		SDL_SetRenderDrawColor(renderer, 137,207,240,255);
		//clear screen to grey
		SDL_RenderClear(renderer);
        SDL_Rect bgRect = {0, -200, 1920, 1080};
        SDL_RenderCopy(game->renderer, game->bg, NULL, &bgRect);


		//render the tiles of the map
		drawMap(game);

		//draw all of the enemies on the map
		for(int i = 0; i < MAX_ENEMY; i++)
		{
		  SDL_Rect plogRect = {game-> scrollX + game->plog[i].x, game->plog[i].y, 32, 32 };
		  SDL_RenderCopy(renderer, game->enemy, NULL, &plogRect);
		}

		/*create a rectangle for the sprite sheet with
		 * The current sprite having its own rect
		 */
		SDL_Rect srcRect = { 60*game->player.currentSprite, 0, 60, 99 };
		SDL_Rect rect = { game->scrollX + game->player.x, game->player.y, 30, 50 };
		SDL_RenderCopyEx(renderer, game->player.lifeState, &srcRect, &rect, 0, NULL, game->player.facingLeft);
	
		/* Create the teleporter sprite sheet
		 * With the current color having its on rect
		 */
		SDL_Rect teleRect = { 64*game->currentTeleColor, 0, 64, 64 };
		SDL_Rect teleRectGame = { game->scrollX + (game->map.maxX - 100), 288, 64, 64 };
		SDL_RenderCopyEx(renderer, game->teleporter, &teleRect, &teleRectGame, 0, NULL, 0);

	}
	//render everything on the screen
	SDL_RenderPresent(renderer);
}
