#ifndef DRAW_TEXT_H_
#define DRAW_TEXT_H_

#include <SDL.h>

/*
 * Draw text on screen in given color
 * Places text on coordinates (sx,sy)
 * Remember to call SDL_UpdateRect after, so text is visible
 */
void DrawText(SDL_Surface *screen, int sx, int sy, Uint32 color, char *text);

 #endif