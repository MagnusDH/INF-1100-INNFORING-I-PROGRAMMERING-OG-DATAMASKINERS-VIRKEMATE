/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#ifndef DRAW_FIGURES_H_
#define DRAW_FIGURES_H_

#include <SDL.h>
#include "vector.h"


/*
 * Draws a circle
 */
void draw_circle(SDL_Surface *surface, Vector *pos, int radius, unsigned int fillcolor);

/*
 * Draw a circle filled with color
 */
void draw_filled_circle(SDL_Surface *surface, Vector *pos, int radius, unsigned int fillcolor);


/*
 * Draw a circle with with a thick line in color
 * Thickness determines how many pixels wide the circle should be.
 */
void draw_thick_circle(SDL_Surface *surface, Vector *pos, int radius, int thickness, unsigned int fillcolor);

/*
 * Draw a rectangle
 */
 void draw_rectangle(SDL_Surface *surface, SDL_Rect rect, unsigned int fillcolor);

/*
 * Draw a filled rectangle
 */
void draw_filled_rectangle(SDL_Surface *surface, SDL_Rect rect, unsigned int fillcolor);

 #endif