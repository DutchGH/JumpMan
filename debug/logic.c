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

	/*Choose which screen to display with its corresponding gameState
	and What actions to take*/


	if(game->gameStatus == GAME_STATE_LIVES)
	{
		//wait 2 seconds before displaying the game again
		if(game->globalTime > 120)
		{
			shutDownStatusLives(game);
			game->gameStatus =GAME_STATE_GAME;
			game->musicChannel = Mix_PlayChannel(-1, game->bgMusic, -1);
		}
	}

	//if gameover is displayed, exit the game
	else if (game->gameStatus == GAME_STATE_GAMEOVER)
	{
		if(game->globalTime>400)
		{
			exitSDL(game, game->renderer, game->window);
			exit(0);
		}
	}

	//if the victory screen is displayed, exit the screen
	else if (game->gameStatus == GAME_STATE_VICTORY)
	{
		if(game->globalTime>400)
		{
			exitSDL(game, game->renderer, game->window);
			exit(0);
		}
	}

	else if(game->gameStatus == GAME_STATE_GAME)
	{
		if(!game->player.isDead)
		{
			game->player.lifeState = game->player.sheetTexture;
			//increase co-ordinates with directional velocity
			game->player.x += game->player.dx;
			game->player.y += game->player.dy;
			//reset double jump counter once player lands
			if(game->player.onLedge == 1)
			{
				game->player.jumpCount = 0;
			}

			if (game->globalTime%4 == 0)
			{
				game->currentTeleColor++;
				game->currentTeleColor %=3;
			}


			if(game->player.x > game->map.maxX - 80)
			{
				initVictory(game);
				game->gameStatus = GAME_STATE_VICTORY;
				Mix_HaltChannel(game->musicChannel);
				Mix_PlayChannel(-1, game->victorySound, 0);
				game->globalTime = 0;
			}

			//impose gravity upon the player
			game->player.dy += GRAVITY;

			for(int i = 0; i < MAX_ENEMY; i++)
			{
				//move enemy sprites back and forth via a sin wave
				game->plog[i].x = game->plog[i].baseX;
				game->plog[i].y = game->plog[i].baseY;
				game->plog[i].x = game->plog[i].baseX+sinf(game->globalTime*0.06f)*(32*2);
			}
		}

		//increment the death counter if the player dies
		if(game->player.isDead && game->deathTime < 0)
		{
			game->player.lifeState = game->player.deathSheet;
			game->deathTime = 60;
		}

		if(game->deathTime >= 0)
		{
			//take away a life when dead
			game->deathTime--;
			if(game->deathTime < 0)
			{
				game->player.lives--;

				if(game->player.lives >= 0)
				{
					//if lives remain, restart the level
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
					//declare the game is over and quit the game
					initGameOver(game);
					game->gameStatus = GAME_STATE_GAMEOVER;
					Mix_HaltChannel(game->musicChannel);
					Mix_PlayChannel(-1, game->gameOver, 0);
					game->globalTime = 0;
				}
			}
		}
	}

	//set the scrollX values to be slightly behind the player for easier viewing
	game->scrollX = -game->player.x+320;

	//stop player going out of bounds/camera scrolling too far
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


