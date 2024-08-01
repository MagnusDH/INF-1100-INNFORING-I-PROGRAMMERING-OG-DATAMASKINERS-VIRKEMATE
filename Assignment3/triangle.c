#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000
#define TRIANGLE_SCALE 1

/* 
 * Print triangle coordinates along with a message
 */
void print_triangle(triangle_t *triangle, char *msg)
{
    printf("%s: %d,%d - %d,%d - %d,%d\n",
        msg,
        triangle->x1, triangle->y1, 
        triangle->x2, triangle->y2, 
        triangle->x3, triangle->y3);
}

/*
 * Return 0 if triangle coordinates are outside the surface boundary. 1 otherwise.
 */
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    if (triangle->sx1 < 0 || triangle->sx1 >= surface->w ||
        triangle->sx2 < 0 || triangle->sx2 >= surface->w ||
        triangle->sx3 < 0 || triangle->sx3 >= surface->w ||
        triangle->sy1 < 0 || triangle->sy1 >= surface->h ||
        triangle->sy2 < 0 || triangle->sy2 >= surface->h ||
        triangle->sy3 < 0 || triangle->sy3 >= surface->h) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * DONE!
 * Scale triangle, altering the on-screen coordinates(e.g. triangle->sx1)
 */
void scale_triangle(triangle_t *triangle)
{
    // TODO: Replace the code below with code that scales each triangle coordinate. 
    // The scaling factor is specified in triangle->scale.
    // Remember that this function MUST write to the on-surface coordinates.
    // Do not alter the model coordinates.

    triangle->scale = TRIANGLE_SCALE;
    triangle->x1 *= triangle->scale;
    triangle->x2 *= triangle->scale;
    triangle->x3 *= triangle->scale;
    triangle->y1 *= triangle->scale;
    triangle->y2 *= triangle->scale;
    triangle->y3 *= triangle->scale;
}

/*
 * DONE!
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    // TODO: Insert code that moves the triangle on the surface.
    // The translation coordinates are specified in triangle->tx and triangle->ty.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
    
    //Finding center of triangle
    // triangle->tx = triangle->x3 - (triangle->rect.w/2);
    // triangle->ty = triangle->y3 - triangle->rect.h/2;

    triangle->tx = 800;
    triangle->ty = 400;
    // triangle->tx = 0;
    // triangle->ty = 0;

    triangle->x1 += triangle->tx ;
    triangle->x2 += triangle->tx;
    triangle->x3 += triangle->tx;

    triangle->y1 += triangle->ty;
    triangle->y2 += triangle->ty;
    triangle->y3 += triangle->ty;

}

/*
 * DONE!
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    // TODO: Insert code that calculates the bounding box of a triangle.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
    // The bounding box coordinates should be written to 
    // triangle->rect.x, triangle->rect.y, triangle->rect.w, triangle->rect.h

    triangle->rect.x = triangle->x1;    //X point in left upper corner
    triangle->rect.y = triangle->y2;    //Y point in left upper corner
    triangle->rect.w = triangle->rect.x + (triangle->x3 - triangle->x1); //Length of the width
    triangle->rect.h = triangle->rect.y + (triangle->y3 - triangle->y2); //length og the height

    // printf("Bounding box X is %d\n", triangle->rect.x);
    // printf("Bounding box Y is %d\n", triangle->rect.y);
    // printf("Bounding box width is %d\n", triangle->rect.w);
    // printf("Bounding box height is %d\n", triangle->rect.h);
    // print_triangle(triangle, "triangle coordinates are");
}

/*
 * Fill the triangle on the surface with the triangle's color
 */
void fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    // TODO: Insert code that fills the triangle with the color specified in triangle->fillcolor.
    // Hint: Draw the triangle with color TRIANGLE_PENCOLOR (this color can not
    // occur in e.g. the teapot or the example triangles).  Thus, if your 
    // approach to filling the triangle relies on looking for the edges of
    // the triangle on the surface (via the GetPixel function), you will find those
    // edges even if the triangle overlaps with a triangle that has already
    // been drawn on the surface.

    int startX, startY, endX, endY; //Variables keeping track of when to start and end drawing a filled line

    for(int i = triangle->rect.y; i<=triangle->rect.h; i++){
        for(int j = triangle->rect.x; j<=triangle->rect.w; j++){    //LOOPS FORWARD AND FINDS THE STARTING POINT OF WHERE TO FILL
            if(get_pixel(surface, j, i) == TRIANGLE_PENCOLOR){
                startX = j;
                startY = i;
            }
        }
        for(int x = triangle->rect.w; x>=triangle->rect.x; x--){    //LOOPS BACKWARDS AND FINDS THE END POINT OF WHERE TO STOP FILLING
            if(get_pixel(surface, x, i) == TRIANGLE_PENCOLOR){
                endX = x;
                endY = i;
            }
        }
        draw_line(surface, startX, startY, endX, endY, triangle->fillcolor);
    }
}

/*
 * Draw a filled triangle on the given surface
 */
void draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    // print_triangle(triangle, "Corners of each triangle");
    int isOK;

    /* Scale. */
    scale_triangle(triangle);
    
    /* Translate. */
    translate_triangle(triangle);
    
    /* Determine bounding box */
    calculate_triangle_bounding_box(triangle);
   

    /* Sanity check that triangle is within surface boundaries. */
    isOK = sanity_check_triangle(surface, triangle);
    if (!isOK) {
        print_triangle(triangle, "Triangle outside surface boundaries");
        return;
    }

    /* 
     * TODO: Insert calls to draw_line to draw the triangle.
     * Remember to use the on-surface coordinates (triangle->sx1, etc.)
     */

    //Drawing triangle
    draw_line(surface, triangle->x1, triangle->y1, triangle->x2, triangle->y2, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->x2, triangle->y2, triangle->x3, triangle->y3, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->x3, triangle->y3, triangle->x1, triangle->y1, TRIANGLE_PENCOLOR);

    //Drawing bounding box
    // draw_line(surface, triangle->rect.x, triangle->rect.y, triangle->x3, triangle->rect.y, SDL_MapRGB(surface->format, 0, 0xff, 0));
    // draw_line(surface, triangle->x3, triangle->rect.y, triangle->x3, triangle->y3, SDL_MapRGB(surface->format, 0, 0xff, 0));
    // draw_line(surface, triangle->x3, triangle->y3, triangle->x1, triangle->y3, SDL_MapRGB(surface->format, 0, 0xff, 0));
    // draw_line(surface, triangle->x1, triangle->y3, triangle->rect.x, triangle->rect.y, SDL_MapRGB(surface->format, 0, 0xff, 0));

    /* Fill triangle */
    fill_triangle(surface, triangle);
}