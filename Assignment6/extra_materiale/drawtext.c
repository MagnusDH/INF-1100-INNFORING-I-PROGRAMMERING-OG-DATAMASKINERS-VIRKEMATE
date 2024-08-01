#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "SDL.h"
#include "drawline.h"
#include "hershey_font.h"

/*
 * Draw text on screen
 * Places text on coordinates (sx,sy)
 * Remember to call SDL_UpdateRect after, so text is visible
 */
void DrawText(SDL_Surface *screen, int sx, int sy, Uint32 color, char *text)
{
	int			c;
	int 		x1, y1, x2, y2;
	int 		numvertices;
	vertex_t	*vertices;

	// Draw text
	while (*text != 0) {
		// Skip unknown characters
        if (*text < ' ' || *text > '~') {
            text++;
			continue;
        }
			
		// Draw character
		c = *text - ' ';
		numvertices = font[c].numvertices;
		vertices = font[c].vertices;
		while (numvertices > 0) {
			x1 = vertices->x;
			y1 = vertices->y;
			
			// Next vertex
			numvertices--;
			vertices++;
			
			x2 = vertices->x;
			y2 = vertices->y;

			// Pen up?
			if (x2 == -1 && y2 == -1) {
				numvertices--;
				vertices++;
				continue;
			}
			
			DrawLine(screen, x1 + sx, -y1 + sy, x2 + sx, -y2 + sy, color);
		}

		// Move horizontally (space between characters)
		sx = sx + font[c].spacing;
		
		// Next character
		text++;
	}
}

