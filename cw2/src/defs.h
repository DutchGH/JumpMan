/*
 * defs.h
 *
 *  Created on: 29 Apr 2016
 *      Author: jake
 */

#ifndef DEFS_H_
#define DEFS_H_
//DEFINITIONS
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_MAP_X 400
#define MAX_MAP_Y 300
#define TILE_SIZE 32
#define GRAVITY 0.5
#define GAME_STATE_LIVES 0
#define GAME_STATE_GAME 1
#define GAME_STATE_GAMEOVER 2
#define GAME_STATE_VICTORY 3


//LIBRARIES TO INCLUDE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"
#include "structs.h"
#include "init.h"
#include "events.h"
#include "lives.h"
#include "gameOver.h"
#include "gameWin.h"
#include "logic.h"
#include "render.h"
#include "map.h"
#include "collision.h"


#endif /* DEFS_H_ */
