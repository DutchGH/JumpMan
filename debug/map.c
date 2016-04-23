/*
 * map.c

 *
 *  Created on: 21 Apr 2016
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

//Map map;
//
//void loadMap(char *name)
//{
//	int x, y;
//	FILE *fp;
//
//	fp = fopen(name, "rb");
//
//	//error handling for map file
//	if (fp == NULL)
//	{
//		printf("Failed To Open Map %s\n", name);
//		exit(1);
//	}
//
//	//read data from file into the map
//	for(y = 0; y <MAX_MAP_Y; y++)
//	{
//		for (x = 0; x<MAX_MAP_X; x++)
//		{
//			fscanf(fp, "%d", &map.tile[y][x]);
//		}
//	}
//
//	//set the start coordinates of the map
//	map.startX = map.startY = 0;
//
//	//set maximum scroll position of map.
//	map.maxX = MAX_MAP_X * TILE_SIZE;
//	map.maxY = MAX_MAP_Y * TILE_SIZE;
//
//	fclose(fp);
//
//}
//
//void drawMap(GameState *game)
//{
//	int x,y,mapX,x1,x2,mapY,y1,y2;
//
//	mapX = map.startX/TILE_SIZE;
//	x1 = (map.startX%TILE_SIZE) * -1;
//	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
//
//	mapY = map.startY / TILE_SIZE;
//	y1 = (map.startY % TILE_SIZE) * -1;
//	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
//	implement a proper drawimage
//	drawImage(game->backgroundImage, 0, 0);
//
//	for(y = y1; y<y2; y+=TILE_SIZE)
//	{
//		mapX = map.startX/TILE_SIZE;
//		for(x = x1; x<x2; x+= TILE_SIZE)
//		{
//			if (map.tile[mapY][mapX] != 0)
//			{
				//implement a proper drawimage
//				drawImage(game->brickImage, x, y);
//			}
//		}
//	}
//}

