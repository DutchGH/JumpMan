/*
 * map.h
 *
 *  Created on: 24 Apr 2016
 *      Author: jake
 */

#ifndef MAP_H_
#define MAP_H_
void drawImage(GameState *game, SDL_Surface *image, SDL_Renderer *renderer, int x, int y);
void loadMap(GameState *game, char *name);
void loadMapTiles(GameState *game);
void drawMap(GameState*game);





#endif /* MAP_H_ */
