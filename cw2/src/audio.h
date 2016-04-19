/*
 * audio.h
 *
 *  Created on: 19 Apr 2016
 *      Author: jake
 */

#ifndef AUDIO_H_
#define AUDIO_H_
Mix_Chunk *loadSound(char *name);
void playSound(Mix_Chunk *sfx);


#endif /* AUDIO_H_ */
