/*
 * map.c

 *
 *  Created on: 21 Apr 2016
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

SDL_Surface *mapImages[MAX_TILES];

void drawImage(GameState *game, SDL_Surface *image, SDL_Renderer *renderer, int x, int y)
{
	//create a rectangle for the tile
	SDL_Rect tileRect = { x, y, 32, 32 };
	SDL_RenderCopy(renderer, game->brick, NULL, &tileRect);
}

void loadMap(GameState *game, char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");

	//error checking
	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}

	// Read the data from the file into the map

	game->map.maxX = game->map.maxY = 0;

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fscanf(fp, "%d", &(game->map.tile[y][x]));
			//printf("Tile Scanned @ %d %d\n", x, y);

			if (game->map.tile[y][x] > 0)
			{
				if (x > game->map.maxX)
				{
					game->map.maxX = x;
				}

				if (y > game->map.maxY)
				{
					game->map.maxY = y;
				}
			}
		}
	}

	// Set the maximum scroll position of the map

	game->map.maxX = (game->map.maxX + 1) * TILE_SIZE;
	game->map.maxY = (game->map.maxY + 1) * TILE_SIZE;

	//printf("%d %d\n", game->map.maxX, game->map.maxY);

	// Set the start coordinates

	game->map.startX = game->map.startY = 0;



	/* Close the file afterwards */
	//printf("file closed\n");
	fclose(fp);
}

void drawMap(GameState*game)
{
	int x, y, mapX, x1, x2, mapY, y1, y2;

	mapX = game->map.startX / TILE_SIZE;
	x1 = (game->map.startX % TILE_SIZE) * -1;
	printf("x1 %d\n", x1);
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
	printf("x2 %d\n", x2);

	mapY = game->map.startY / TILE_SIZE;
	y1 = (game->map.startY % TILE_SIZE) * -1;
	printf("y1 %d\n", y1);

	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
	printf("y2 %d\n", y2);




	//Draw the map

	for (y=y1;y<y2;y+=TILE_SIZE)
	{
		mapX = game->map.startX / TILE_SIZE;

		for (x=x1;x<x2;x+=TILE_SIZE)
		{
			if (game->map.tile[mapY][mapX] != 0)
			{
				printf("FOUND A TILE @ %d %d\n", x,y);
				drawImage(game, game->brickImages[game->map.tile[mapY][mapX]], game->renderer, x, y);
			}

			mapX++;
//			printf("map X %d\n", mapX);
		}
		mapY++;
//		printf("mapy %d\n", mapY);
	}
}




