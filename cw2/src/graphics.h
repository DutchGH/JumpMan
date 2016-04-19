/*
 * graphics.h
 *
 *  Created on: 10 Apr 2016
 *      Author: jake
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

SDL_Surface *loadImage(char *name);
void drawImage(SDL_Surface *image, int x, int y);
void updateScreen();
void loadSprite(int index, char *name);
void *getSprites(int index);
void freeSprites();
void loadAllSprites();



#endif /* GRAPHICS_H_ */
