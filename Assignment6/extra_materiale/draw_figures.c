/*
 * Code created for assignment 6 for INF-1100 course UIT
 * Authors: Eric Brattli and Joakim Sjøhaug
 * Year:    2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#include "common.h"
#include "draw_figures.h"
#include "drawline.h"

void draw_circle(SDL_Surface *surface, Vector *pos, int radius, unsigned int fillcolor)
{
    SDL_Rect boundingbox;
    
    boundingbox.x = get_x(pos) - radius;
    boundingbox.y = get_y(pos) - radius;
    boundingbox.w = boundingbox.h = (radius * 2); /* H and W is the diamater of the circle */

    
    int x = radius-1;
    int y = 0;
    int x0 = get_x(pos);
    int y0 = get_y(pos);
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        set_pixel(surface, (x0 + x), (y0 + y), fillcolor);
        set_pixel(surface, (x0 + y), (y0 + x), fillcolor);
        set_pixel(surface, (x0 - y), (y0 + x), fillcolor);
        set_pixel(surface, (x0 - x), (y0 + y), fillcolor);
        set_pixel(surface, (x0 - x), (y0 - y), fillcolor);
        set_pixel(surface, (x0 - y), (y0 - x), fillcolor);
        set_pixel(surface, (x0 + y), (y0 - x), fillcolor);
        set_pixel(surface, (x0 + x), (y0 - y), fillcolor);
        
        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0)
        {
            x--;
            dx += 2;
            err += (-radius << 1) + dx;
        }
    }
}

/*
 * Draw a circle filled with color
 */
void draw_filled_circle(SDL_Surface *surface, Vector *pos, int radius, unsigned int fillcolor)
{
    int x = get_x(pos);
    int y = get_y(pos);

    for (int i = -radius; i < radius; ++i)
    {
        for (int j = -radius; j < radius; ++j)
        {
            if ((i*i + j*j) < (radius*radius))
            {
                set_pixel(surface, i + x, j + y, fillcolor);
            }
        }
    }
}

/*
 * Draw a circle with with a thick line in color
 */
void draw_thick_circle(SDL_Surface *surface, Vector *pos, int radius, int thicness, unsigned int fillcolor)
{
    int distance;
    int r_squared;
    int r_squared_small;

    int x = get_x(pos);
    int y = get_y(pos);

    for (int i = -radius; i < radius; ++i)
    {
        for (int j = -radius; j < radius; ++j)
        {
            distance = (i*i) + (j*j);
            r_squared = radius*radius;
            r_squared_small = (radius - thicness) * (radius - thicness);

            if (distance < r_squared && distance > r_squared_small)
            {
                set_pixel(surface, i + x, j + y, fillcolor);
            }
        }
    }
}


/*
 * Draw a rectangle
 */
void draw_rectangle(SDL_Surface *surface, SDL_Rect rect, unsigned int fillcolor)
{
    int topx, topy, w, h;

    topx = rect.x;
    topy = rect.y;
    w = rect.w;
    h = rect.h;

    draw_line(surface, topx, topy, (topx + w), topy, fillcolor);
    draw_line(surface, topx, topy, topx, (topy + h), fillcolor);
    draw_line(surface, topx, (topy + h), (topx + w), (topy + h), fillcolor);
    draw_line(surface, (topx + w), topy, (topx + w),  (topy + h), fillcolor);    
}

/*
 * Draw a filled rectangle
 */
void draw_filled_rectangle(SDL_Surface *surface, SDL_Rect rect, unsigned int fillcolor)
{
    SDL_FillRect(surface, &rect, fillcolor);
}





