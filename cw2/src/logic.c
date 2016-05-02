/*
 * logic.c
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */
#include "defs.h"

void updateLogic(GameState *game)
{
	game->globalTime++;
	if(game->gameStatus == GAME_STATE_LIVES)
	{
	if(game->globalTime > 120)
		{
			shutDownStatusLives(game);
			game->gameStatus =GAME_STATE_GAME;
		}
	}
	else if (game->gameStatus == GAME_STATE_GAMEOVER)
	{
		if(game->globalTime>190)
		{
			SDL_Quit();
			exit(0);
		}
	}
	else if(game->gameStatus == GAME_STATE_GAME)
	{
		if(!game->player.isDead)
		{
			//increase co-ordinates with directional velocity
			game->player.x += game->player.dx;
			game->player.y += game->player.dy;
			//reset double jump counter once player lands
			if(game->player.onLedge == 1)
			{
				game->player.jumpCount = 0;
			}


			if(game->player.x > game->map.maxX - 80)
			{
				initVictory(game);
				game->gameStatus = GAME_STATE_VICTORY;
			}
			//impose gravity upon the player
			game->player.dy += GRAVITY;
		  for(int i = 0; i < MAX_ENEMY; i++)
		  {
			game->plog[i].x = game->plog[i].baseX;
			game->plog[i].y = game->plog[i].baseY;
			game->plog[i].x = game->plog[i].baseX+sinf(game->globalTime*0.06f)*(32*2);
		  }
		}
	    if(game->player.isDead && game->deathTime < 0)
	    {
	      game->deathTime = 120;
	    }
	    if(game->deathTime >= 0)
	    {
	      game->deathTime--;
	      if(game->deathTime < 0)
	      {
	        game->player.lives--;

	        if(game->player.lives >= 0)
	        {
	          initStatusLives(game);
	          game->gameStatus = GAME_STATE_LIVES;
	          game->globalTime = 0;

	          //reset
	          game->player.isDead = 0;
	          game->player.x = 0;
	          game->player.y = 378;
	          game->player.dx = 0;
	          game->player.dy = 0;
	          game->player.onLedge = 0;
	        }
	        else
	        {
	          initGameOver(game);
	          game->gameStatus = GAME_STATE_GAMEOVER;
	          game->globalTime = 0;
	        }
	      }
	    }
	}

	game->scrollX = -game->player.x+320;
	//printf("SCROLLX VALUE = %g\n", game->scrollX);
	if(game->scrollX > 0)
	{
		game->scrollX = 0;
	}
	else if(game->scrollX < 800-game->map.maxX)
	{
		game->scrollX = 800-game->map.maxX;
	}
	if (game->player.x > game->map.maxX-30)
	{
		game->player.x = game->map.maxX-30;
	}
	if(game->player.x < 0)
	{
		game->player.x = 0;
	}

}


